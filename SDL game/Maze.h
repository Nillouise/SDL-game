#pragma once
#include <utility>

class Maze
{
public:
	std::pair<int, int> ball;
	bool changeDirection(int nextDirection);
	//true����Ϸ�������У�false:��Ϸ����
	bool forward();

};
