#include "Maze.h"
#include<random>
//返回球的位置，先width，后height 感觉这种实现好蠢
static Point getRandomBall(int height,int width)
{
	static bool init = false;
	static std::mt19937 rng;
	if (!init)
	{
		rng.seed(std::random_device()()); 
		init = true;
	}
	std::uniform_int_distribution<std::mt19937::result_type> randomHeight(0, height-1);
	std::uniform_int_distribution<std::mt19937::result_type> randomWidth(0, width-1);
	return Point(randomHeight(rng), randomWidth(rng));
}
static bool conflict(const Point &ball,const std::list<Point> &units)
{
	for(auto unit:units)
	{
		if(unit.r == ball.r && unit.c == ball.c)
		{
			return true;
		}
	}
	return false;
}
//bool Maze::changeDirection(int nextDirection)
//{
//	return snake->changedirect(nextDirection);
//}

//bool Maze::forward()
//{
//	Status st = snake->walk(ball);
//	if(st==Status::eatball)
//	{
//		Point nextBall;
//		//这里没有处理蛇把整个屏幕占满的情况，会导致死循环
//		do
//		{
//			nextBall = getRandomBall(height, width);			
//		} while (conflict(nextBall, snake->units));
//		ball = nextBall;
//		return true;
//	}else if(st == Status::fail)
//	{
//		return false;
//	}else if(st == Status::routine)
//	{
//		return true;
//	}
//	return false;
//}

//std::list<Point> Maze::getSanke()
//{
//	return snake->units;
//}

bool Maze::init()
{
//	delete snake;
//	snake = new Snake();
//	ball = { 10,10 };
	balls.push_back(Ball(10,10));
	balls.push_back(Ball(15,15));
	return true;
}
