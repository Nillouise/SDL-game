#include "Snake.h"
//bugFix �����ʵ�������⣬Ӧ��һֻ֡�ܸı�һ�η��򣬵������ʵ�ֻᵼ��һ֡�Ķ�η���
bool Snake::changedirect(int nextDirection)
{
	if (!newTurn) return false;
	if(abs(nextDirection - direct)==2||nextDirection==direct)
	{
		return false;
	}
	direct = nextDirection;
	newTurn = false;
	return true;
}

Status Snake::walk(Point ball)
{
	Point nextStep;
	nextStep.c = body.front().c + directions[direct][0];
	nextStep.r = body.front().r + directions[direct][1];
	if(nextStep.r == ball.r &&nextStep.c == ball.c)
	{
		body.push_front(nextStep);
		return Status::eatball;
	}
	//������û�гԵ��Լ����壬��ʱ�������߳���ͼ�������
	bool eatSelf = false;
	for(auto a:body)
	{
		if(a.r == nextStep.r && a.c == nextStep.c)
		{
			eatSelf = true;
			return Status::fail;
		}
	}
	body.push_front(nextStep);
	body.pop_back();
	return Status::routine;
}
