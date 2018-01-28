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
	routine,
	finished,
};

class Interact
{
public:
	int m_aliveSnakeCount = 0;
	int m_oriAliveSnakeCount = 0;
	Status forward(Status &curSnakeStatus);
	void setNewTurn();
	//通过id操作snake
	bool input(int id,int direct);
	std::vector<Snake*> getSnakes();
	Maze* getMaze();
	bool init(int R,int C,int ballNum);
	Maze *m_maze;
	long long m_Turn = 0;
	std::map<int, Snake*> m_snakeMap;
	//检查是否失败了
	Status failCheck() const;
private:
	bool conflictWithAllObject(Point p);
};
