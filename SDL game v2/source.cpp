#include "Game.h"
#include"Robot.h"
#include <cstdio>
#include "Conn.h"
#include"GlobalVariable.h"
#include "Starter.h"
using asio::ip::tcp;

Game* g_game = nullptr;
Starter* g_starter = nullptr;
#pragma warning (disable : 4996)
int main(int argc, char* argv[])
{
//	ConnMain();
//	加了下面两句即可在/SUBSYSTEM:WINDOWS 的条件下用控制台输出
	AllocConsole();
	freopen("CONOUT$", "w", stdout);
	//初始化win32套接字
#ifdef _WIN32

	WORD wVersionRequested;
	WSADATA wsaData;

	wVersionRequested = MAKEWORD(2, 2);

	(void)WSAStartup(wVersionRequested, &wsaData);
#endif

	g_starter = new Starter();
	g_starter->init();

	g_game = new Game();
	g_game->init("Chapter 1", 100, 100, 500, 500, false);

	while (g_game->running())
	{
		g_game->handleEvents();
		g_game->update();
		g_game->render();
	}
	g_game->clean();
	return 0;
}
