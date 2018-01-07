#pragma once
#include <list>

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
	//��TextureManager����Ӧ����ʲôͼ���֡�
	std::string textureId;
	//id�ǲ��������Interact�����Ķ���ı�ʶ�š�
	int id = 0;
	//���ʾ����������ϣ��γ��ƶ�����
	//����ֶκ�����뱩¶��������Ȼ��Ϸ���߼��ܲ���д����ΪSnake״̬�ı任��ʱ��û���߼��ģ���Ϊ�����ӳٵ�Ӱ�죩
	int curDirect = 1;
	int nextDirect = 1;
	//0����������1�������
	int status = 1;
	bool newTurn = true;
	Snake()
	{
		body.push_back(Point(0,0));
	}
	Point nextStep();
	//nextDirect��0123�ֱ�����������
	//true:�ɹ��ı䷽��false�����ɹ�
//	bool changedirect(int nextDirection);
	//������״̬
//	Status walk(Point ball);
//	bool forward = true;
//	void setNewTurn() { forward = true; }

private:
	const int directions[4][2]={{0,-1},{1,0},{0,1},{-1,0}};
};

