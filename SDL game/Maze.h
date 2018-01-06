#pragma once
#include <utility>

class Maze
{
public:
	std::pair<int, int> ball;
	bool changeDirection(int nextDirection);
	//true：游戏继续进行，false:游戏结束
	bool forward();

};
