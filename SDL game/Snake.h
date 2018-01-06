#pragma once
#include <list>

enum class Status
{
	//成功通关游戏
	success,
	//失败
	fail,
	//吃到球
	eatball,
	//没事发生
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
	//从头到尾分别是0123...
	std::list<std::pair<int, int> > body;
	//nextDirect：0123分辨是上右下左。
	//true:成功改变方向，false：不成功
	bool changedirect(int nextDirection);
	//产生的状态
	Status walk(std::pair<int, int> ball);

private:

	const int  directions[4][2]={{0,-1},{1,0},{0,1},{-1,0}};
	int direct = 0;//与上面的数组结合，形成移动方向

};


