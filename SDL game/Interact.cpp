#include "Interact.h"
#include <random>

static Point getRandomBall(int height, int width)
{
	static bool init = false;
	static std::mt19937 rng;
	if (!init)
	{
		rng.seed(std::random_device()());
		init = true;
	}
	std::uniform_int_distribution<std::mt19937::result_type> randomHeight(0, height - 1);
	std::uniform_int_distribution<std::mt19937::result_type> randomWidth(0, width - 1);
	return Point(randomHeight(rng), randomWidth(rng));
}

static bool conflict(const Point a, const Point b)
{
	if (a.c == b.c&&a.r == b.r)
	{
		return true;
	}
	else
	{
		return false;
	}
}


static bool conflict(const Point &point, const std::list<Point> &units)
{
	for (auto unit : units)
	{
		if(conflict(unit,point))
		{
			return true;
		}
	}
	return false;
}

const int directions[4][2] = { { 0,-1 },{ 1,0 },{ 0,1 },{ -1,0 } };
//这里还要加入更改snake方向的代码
Status Interact::forward()
{
	for(auto a:m_snakeMap)
	{
		Snake &snake = *a.second;
		snake.curDirect = snake.nextDirect;
	}
	//判断是否有蛇死亡
	int snakeDeadCount = 0;
	//有多少ball被蛇吃了
	int ballDisappearCount = 0;
	for(auto a: m_snakeMap)
	{
//		Snake snake = *a.second;//这是错的，这是复制拷贝，没有修改原来的值
		Snake &snake = *a.second;
		bool ballConflicted = false;
		bool snakeConflicted = false;
		Point nextStep = snake.nextStep();
		//当前的蛇碰到ball就立刻吃掉
		m_maze->balls.begin();
		for(auto b = m_maze->balls.begin();b!=m_maze->balls.end();)
		{
			Ball real = *b;
			if (conflict(nextStep, real))
			{
				ballConflicted = true;
				b = m_maze->balls.erase(b);
			}else
			{
				++b;
			}
		}
		//碰到别的蛇或者碰到自己的身体，这里其实没有正确实现，因为当两条蛇相连得时候，他也当碰到
		for(auto b:m_snakeMap)
		{
			if(conflict(nextStep,b.second->body))
			{
				snakeDeadCount++;
				snake.status = 0;
				break;
			}
		}

		if(ballConflicted)
		{
			ballDisappearCount++;
			snake.body.push_front(nextStep);
		}else
		{
			snake.body.push_front(nextStep);
			snake.body.pop_back();
		}
	}
	for(int i=0;i<ballDisappearCount;i++)
	{
		Point p;
		do
		{
			p = getRandomBall(m_maze->height, m_maze->width);
		} while (conflictWithAllObject(p));
		m_maze->balls.push_back(p);
	}
	m_aliveSnakeCount -= snakeDeadCount;
	if(failCheck())
	{
		return Status::fail;
	}
	if(ballDisappearCount>0)
	{
		return Status::eatball;
	}
	return Status::routine;
}

void Interact::setNewTurn()
{
	m_newTurn = true;
}
bool canChangeDirect(int curDirect,int nextDirect)
{
	if(abs(nextDirect - curDirect)==2|| nextDirect ==curDirect)
	{
		return false;
	}
	return true;
}
bool Interact::input(int id, int direct)
{
	Snake *pSnake = nullptr;
	const auto &iter = m_snakeMap.find(id);
	if(iter == m_snakeMap.end())
	{
		return false;
	}
	pSnake = iter->second;

	if(canChangeDirect(pSnake->curDirect,direct))
	{
		pSnake->nextDirect = direct;
		return true;
	}
	return false;
}

bool Interact::failCheck() const
{
	return m_aliveSnakeCount <= 0;
}

bool Interact::conflictWithAllObject(Point p)
{
	for(auto &a:m_maze->balls)
	{
		if(conflict(p, a))
		{
			return true;
		}
	}
	for(auto &a:m_snakeMap)
	{
		auto &b = a.second;
		if(conflict(p,b->body))
		{
			return true;
		}
	}
	return false;
}
