#define ASIO_STANDALONE 
#define ASIO_HAS_STD_ADDRESSOF
#define ASIO_HAS_STD_ARRAY
#define ASIO_HAS_CSTDINT
#define ASIO_HAS_STD_SHARED_PTR
#define ASIO_HAS_STD_TYPE_TRAITS

#include <asio.hpp>
#include "Game.h"
#include"Robot.h"
#include <cstdio>
#include "Conn.h"
#include "Starter.h"
using asio::ip::tcp;


Game* g_game = nullptr;
int main(int argc, char* argv[])
{
//	ConnMain();
//	加了下面两句即可在/SUBSYSTEM:WINDOWS 的条件下用控制台输出
	AllocConsole();

	freopen("CONOUT$", "w", stdout);
	Starter s;
	s.init();
	robotStart(0);
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
