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

class Snake
{
public:
	Snake()
	{
		body.push_back({ 0,0 });
		direct = 1;
	}
	//��ͷ��β�ֱ���0123...
	std::list<std::pair<int, int> > body;
	//nextDirect��0123�ֱ�����������
	//true:�ɹ��ı䷽��false�����ɹ�
	bool changedirect(int nextDirection);
	//������״̬
	Status walk(std::pair<int, int> ball);

private:

	const int  directions[4][2]={{0,-1},{1,0},{0,1},{-1,0}};
	int direct = 0;//������������ϣ��γ��ƶ�����

};


