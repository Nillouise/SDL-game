#include "Snake.h"
inline bool Snake::changedirect(int nextDirection)
{
	if(abs(nextDirection - direct)==2||nextDirection==direct)
	{
		return false;
	}
	direct = nextDirection;
	return true;
}

Status Snake::walk(std::pair<int, int> ball)
{
	std::pair<int, int> nextStep;
	nextStep.first = body.front().first + directions[direct][0];
	nextStep.second = body.front().second + directions[direct][1];
	if(nextStep.first == ball.first &&nextStep.second == ball.second)
	{
		body.push_front(nextStep);
		return Status::eatball;
	}
	//������û�гԵ��Լ����壬��ʱ�������߳���ͼ�������
	bool eatSelf = false;
	for(auto a:body)
	{
		if(a.first == nextStep.first&&a.second == nextStep.second)
		{
			eatSelf = true;
			return Status::fail;
		}
	}

	body.push_front(nextStep);
	body.pop_back();
	return Status::routine;
}
