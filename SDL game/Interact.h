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
	//ͨ��id����snake
	bool input(int id,int direct);
	std::vector<Snake*> getSnakes();
	Maze* getMaze();
	bool init(int R,int C,int ballNum);
	Maze *m_maze;
	long long m_Turn = 0;
	std::map<int, Snake*> m_snakeMap;
	//����Ƿ�ʧ����
	Status failCheck() const;
private:
	bool conflictWithAllObject(Point p);
};
