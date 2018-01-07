#pragma once
#include"Maze.h"
#include "Snake.h"
#include <map>
#include <vector>

enum class Status
{
	//�ɹ�ͨ����Ϸ
	success,
	//ʧ��
	fail,
	//�Ե���
	eatball,
	//û�·���
	routine
};

class Interact
{
public:
	int m_aliveSnakeCount = 0;
	Status forward();
	void setNewTurn();
	//ͨ��id����snake
	bool input(int id,int direct);
	std::vector<Snake*> getSnakes();
	Maze* getMaze();
	
private:
	std::map<int, Snake*> m_snakeMap;
	bool conflictWithAllObject(Point p);
	Maze *m_maze;
	bool m_newTurn = true;
};
