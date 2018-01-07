#pragma once
#include <utility>
#include <list>
#include "Snake.h"
#include <set>
class Ball:public Point
{
public:
	int r, c;
	int id;
	std::string textureId;
	Ball(int r=0,int c=0):r(r),c(c){}
	Ball(Point p)
	{
		r = p.r;
		c = p.c;
	}
};

class Maze
{
public:
	Ball a;
	//地图的大小
	int height, width;
//	Point ball;
	std::set<Ball> balls;
	Maze(int height,int width):height(height),width(width)
	{
//		snake = new Snake();
	}
	~Maze()
	{
//		delete snake;
	}
//	bool changeDirection(int nextDirection);
	//true：游戏继续进行，false:游戏结束
//	bool forward();
//	std::list<Point> getSanke();
	bool init();
//	void setNewTurn() { snake->setNewTurn(); }
private:
//	Snake *snake = nullptr;
};
