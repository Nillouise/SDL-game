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
	//��ͼ�Ĵ�С
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
	//true����Ϸ�������У�false:��Ϸ����
//	bool forward();
//	std::list<Point> getSanke();
	bool init();
//	void setNewTurn() { snake->setNewTurn(); }
private:
//	Snake *snake = nullptr;
};
