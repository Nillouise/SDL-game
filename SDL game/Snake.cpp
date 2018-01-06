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