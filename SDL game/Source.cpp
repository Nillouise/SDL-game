#include "Game.h"
#include "Windows.h"
#include <cstdio>
// our Game object
Game* g_game = 0;
int main(int argc, char* argv[])
{
	//�����������伴����/SUBSYSTEM:WINDOWS ���������ÿ���̨���
	AllocConsole();
	freopen("CONOUT$", "w", stdout);
	g_game = new Game();
	g_game->init("Chapter 1", 100, 100, 640, 480, false);
	while (g_game->running())
	{
		g_game->handleEvents();
		g_game->update();
		g_game->render();
	}
	g_game->clean();
	return 0;
}