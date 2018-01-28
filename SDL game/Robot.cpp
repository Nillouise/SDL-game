#include "Robot.h"
#include <queue>
//#include <winerror.h>

static bool isRobotStart = false;


class DirectStatus
{
public:
	int r, c, direct;
};

class Robot
{
	int snakeId = 0;
	int obstacle[100][100];
	int dist[100][100][4];
public:
	Robot(int snakeId) :snakeId(snakeId) {};
	void robotInput()
	{
		static long long preTime = 0;

		Interact* interact = g_game->m_interact;
		if (preTime == interact->m_Turn || !isRobotStart)
		{
			preTime = interact->m_Turn;
			return;
		}
		//robot要判断自己有没有死亡
		auto it = interact->m_snakeMap.find(snakeId);
		if(it == interact->m_snakeMap.end())
		{
			return;
		}

		Snake &snake = *it->second;
		Maze maze = *interact->m_maze;
		memset(obstacle, 0, sizeof(obstacle));
		memset(dist, 0x3f3f, sizeof(dist));
		//初始化障碍物
		for (auto a : interact->m_snakeMap)
		{
			for (auto b : a.second->body)
			{
				obstacle[b.r][b.c] = 1;
			}
		}
		obstacle[snake.body.front().r][snake.body.front().c] = 0;
		//初始化起始点
		std::queue<DirectStatus> Q;
		for (auto a : interact->m_maze->balls)
		{
			for (int direct = 0; direct < 4; direct++)
			{
				dist[a.r][a.c][direct] = 0;
				Q.push({ a.r ,a.c,direct });
			}
		}
		static const int directions[4][2] = { { -1,0 },{ 0,1 },{ 1,0 },{ 0,-1 } };
		while (!Q.empty())
		{
			DirectStatus o = Q.front(); Q.pop();
			//		std::cout << o.r << " " << o.c << " " << o.direct << " " << dist[o.r][o.c][o.direct] << std::endl;//
			for (int direct = 0; direct < 4; direct++)
			{
				if (abs(o.direct - direct) == 2)
					continue;
				int negativeDirection = (direct + 2) % 4;
				int nr = o.r + directions[direct][0];
				int nc = o.c + directions[direct][1];
				if (nr<0 || nr >= maze.height || nc<0 || nc >= maze.width)
					continue;
				if (obstacle[nr][nc] == 1)continue;;
				if (dist[nr][nc][direct] > dist[o.r][o.c][o.direct] + 1)
				{
					dist[nr][nc][direct] = dist[o.r][o.c][o.direct] + 1;
					Q.push({ nr,nc,direct });
				}
				int sr = snake.body.front().r;
				int sc = snake.body.front().c;
				if (check(sr, sc))
				{
					goto breakwhile;
				}
			}
		}
	breakwhile:
		int minDirect = 0;
		int minStep = 0x3f3f3f3f;
		for (int i = 0; i < 4; i++)
		{
			int r = snake.body.front().r, c = snake.body.front().c;
			if (r<0 || r >= maze.height || c<0 || c >= maze.width)
				continue;
			if (dist[r][c][i]<minStep)
			{
				minDirect = i;
				minStep = dist[r][c][i];
			}
		}
		int negativeDirection = (minDirect + 2) % 4;
		interact->input(snakeId, negativeDirection);
		return;
	}
private:
	bool check(int r, int c)
	{
		int count = 0;
		for (int i = 0; i<4; i++)
			if (dist[r][c][i] == 0x3f3f3f3f)
			{
				count++;
			}
		return count <= 1;
	}
	
};

std::vector<Robot> robots;

void robotInput()
{
	for(auto &a:robots)
	{
		a.robotInput();
	}
}


void addRobot(int snakeId)
{
	isRobotStart = true;
	robots.push_back(Robot(snakeId));
}

