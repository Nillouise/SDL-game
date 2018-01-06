#include "Maze.h"
#include<random>
//返回球的位置，先width，后height 感觉这种实现好蠢
std::pair<int,int> getRandomBall(int height,int width)
{
	static bool init = false;

	std::mt19937 rng;
	if (!init)
	{
		rng.seed(std::random_device()()); 
		init = true;
	}
	std::uniform_int_distribution<std::mt19937::result_type> randomHeight(0, height-1);
	std::uniform_int_distribution<std::mt19937::result_type> randomWidth(0, width-1);
	return{ randomWidth(rng), randomHeight(rng) };
}
bool conflict(const std::pair<int,int> &ball,const std::list<std::pair<int,int>> &body)
{
	for(auto unit:body)
	{
		if(unit.first == ball.first && unit.second == ball.second)
		{
			return true;
		}
	}
	return false;
}
bool Maze::changeDirection(int nextDirection)
{
	return snake->changedirect(nextDirection);
}

bool Maze::forward()
{
	Status st = snake->walk(ball);
	if(st==Status::eatball)
	{
		std::pair<int, int> nextBall;
		//这里没有处理蛇把整个屏幕占满的情况，会导致死循环
		do
		{
			nextBall = getRandomBall(height, width);			
		} while (conflict(ball, snake->body));
		ball = nextBall;
		return true;
	}else if(st == Status::fail)
	{
		return false;
	}else if(st == Status::routine)
	{
		return true;
	}
	return false;
}

std::list<std::pair<int, int>> Maze::getSanke()
{
	return snake->body;
}

bool Maze::init()
{
	delete snake;
	snake = new Snake();
	return true;
}
