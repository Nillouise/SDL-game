#include "Snake.h"
//bugFix 这里的实现由问题，应该一帧只能改变一次方向，但这里的实现会导致一帧改多次方向
bool Snake::changedirect(int nextDirection)
{
	if (!newTurn)return false;
	if(abs(nextDirection - direct)==2||nextDirection==direct)
	{
		return false;
	}

	direct = nextDirection;
	newTurn = false;
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
	//测试有没有吃到自己身体，暂时不处理走出地图的情况。
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
