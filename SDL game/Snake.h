#pragma once
#include <list>

class Snake
{
public:
	//从头到尾分别是0123...
	std::list<std::pair<int, int> > body;
	//nextDirect：0123分辨是上右下左。
	//true:成功改变方向，false：不成功
	bool changedirect(int nextDirection);
	//true:吃到球，false：吃不到球。
	bool walk(std::pair<int, int> ball);

private:

	const int  directions[4][2]={{0,-1},{1,0},{0,1},{-1,0}};
	int direct = 0;//与上面的变量结合，形成移动方向

	

};


