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
	//从头到尾分别是0123...
	std::list<Point> body;
	//在TextureManager那里应该用什么图表现。
	std::string textureId;
	//id是操作输入跟Interact交互的对象的标识号。
	int id = 0;
	//与表示方向的数组结合，形成移动方向
	//这个字段好像必须暴露出来，不然游戏的逻辑很不好写，因为Snake状态的变换有时是没有逻辑的（因为网络延迟的影响）
	int curDirect = 1;
	int nextDirect = 1;
	//0代表死亡，1代表活着
	int status = 1;
	Snake(Point p)
	{
		body.push_back(p);
	}
	Point nextStep();
	//nextDirect：0123分辨是上右下左
	//true:成功改变方向，false：不成功
//	bool changedirect(int nextDirection);
	//产生的状态
//	Status walk(Point ball);
//	bool forward = true;
//	void setNewTurn() { forward = true; }

private:
	const int directions[4][2]={{0,-1},{1,0},{0,1},{-1,0}};
};

