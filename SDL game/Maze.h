#pragma once
#include <utility>
#include <list>
#include "Snake.h"

class Maze
{
public:
	//地图的大小
	int height, width;
	Point ball;
	Maze(int height,int width):height(height),width(width)
	{
		snake = new Snake();
	}
	~Maze()
	{
		delete snake;
	}
	bool changeDirection(int nextDirection);
	//true：游戏继续进行，false:游戏结束
	bool forward();
	std::list<Point> getSanke();
	bool init();
	void setNewTurn() { snake->setNewTurn(); }
private:
	Snake *snake = nullptr;
};
