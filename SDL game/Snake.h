#pragma once
#include <list>

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

class Point
{
public:
	int r, c;
	Point(int r=0, int c=0) :r(r), c(c) {}
};



class Snake
{
public:
	//��ͷ��β�ֱ���0123...
	std::list<Point> body;
	std::string textureId;
	Snake()
	{
		body.push_back(Point(0,0));
		direct = 1;
	}
	//nextDirect��0123�ֱ�����������
	//true:�ɹ��ı䷽��false�����ɹ�
	bool changedirect(int nextDirection);
	//������״̬
//	Status walk(Point ball);
	bool newTurn = true;
	void setNewTurn() { newTurn = true; }
private:
	const int directions[4][2]={{0,-1},{1,0},{0,1},{-1,0}};
	int direct = 0;//������������ϣ��γ��ƶ�����
};