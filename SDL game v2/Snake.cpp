#include "Snake.h"
//bugFix 这里的实现由问题，应该一帧只能改变一次方向，但这里的实现会导致一帧改多次方向
//bool Snake::changedirect(int nextDirection)
//{
//	if (!forward) return false;
//	if(abs(nextDirection - curDirect)==2||nextDirection==curDirect)
//	{
//		return false;
//	}
//	curDirect = nextDirection;
//	forward = false;
//	return true;
//}

//Status Snake::walk(Point ball)
//{
//	Point nextStep;
//	nextStep.c = body.front().c + directions[curDirect][0];
//	nextStep.r = body.front().r + directions[curDirect][1];
//	if(nextStep.r == ball.r &&nextStep.c == ball.c)
//	{
//		body.push_front(nextStep);
//		return Status::eatball;
//	}
//	//测试有没有吃到自己身体，暂时不处理走出地图的情况。
//	bool eatSelf = false;
//	for(auto a:body)
//	{
//		if(a.r == nextStep.r && a.c == nextStep.c)
//		{
//			eatSelf = true;
//			return Status::fail;
//		}
//	}
//	body.push_front(nextStep);
//	body.pop_back();
//	return Status::routine;
//}
const int directions[4][2] = { { 0,-1 },{ 1,0 },{ 0,1 },{ -1,0 } };
Point Snake::nextStep()
{
	Point nextStep;
	nextStep.c = body.front().c + directions[curDirect][0];
	nextStep.r = body.front().r + directions[curDirect][1];
	return nextStep;
}
