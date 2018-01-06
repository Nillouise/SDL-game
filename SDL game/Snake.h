#pragma once
#include <list>

class Snake
{
public:
	//��ͷ��β�ֱ���0123...
	std::list<std::pair<int, int> > body;
	//nextDirect��0123�ֱ�����������
	//true:�ɹ��ı䷽��false�����ɹ�
	bool changedirect(int nextDirection);
	//true:�Ե���false���Բ�����
	bool walk(std::pair<int, int> ball);

private:

	const int  directions[4][2]={{0,-1},{1,0},{0,1},{-1,0}};
	int direct = 0;//������ı�����ϣ��γ��ƶ�����

	

};


