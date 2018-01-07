#pragma once
#include <utility>
#include <list>
#include "Snake.h"
#include <set>
class Ball:Point
{
public:
	int r, c, R, G, B;
	Ball(int r=0,int c=0,int R=0,int G=0,int B=0):r(r),c(c),R(R),G(G),B(B){}
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
