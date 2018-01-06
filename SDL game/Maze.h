#pragma once
#include <utility>
#include <list>
#include "Snake.h"

class Maze
{
public:
	//��ͼ�Ĵ�С
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
	//true����Ϸ�������У�false:��Ϸ����
	bool forward();
	std::list<Point> getSanke();
	bool init();
	void setNewTurn() { snake->setNewTurn(); }
private:
	Snake *snake = nullptr;
};
