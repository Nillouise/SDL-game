#pragma once
#include <utility>
#include <list>
#include "Snake.h"

class Maze
{
public:
	std::pair<int, int> ball;
	bool changeDirection(int nextDirection);
	//true����Ϸ�������У�false:��Ϸ����
	bool forward();
	std::list<std::pair<int, int>> getSanke();
private:
	Snake snake;

};
