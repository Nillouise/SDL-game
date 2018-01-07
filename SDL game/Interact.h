#pragma once
#include"Maze.h"
#include "Snake.h"
#include <map>
#include <vector>

enum class Status
{
	//成功通关游戏
	success,
	//失败
	fail,
	//吃到球
	eatball,
	//没事发生
	routine
};

class Interact
{
public:
	int m_aliveSnakeCount = 0;
	Status forward();
	void setNewTurn();
	//通过id操作snake
	bool input(int id,int direct);
	std::vector<Snake*> getSnakes();
	Maze* getMaze();
	
private:
	std::map<int, Snake*> m_snakeMap;
	bool conflictWithAllObject(Point p);
	Maze *m_maze;
	bool m_newTurn = true;
};
