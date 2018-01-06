#define ASIO_STANDALONE 
#define ASIO_HAS_STD_ADDRESSOF
#define ASIO_HAS_STD_ARRAY
#define ASIO_HAS_CSTDINT
#define ASIO_HAS_STD_SHARED_PTR
#define ASIO_HAS_STD_TYPE_TRAITS

#include <asio.hpp>
#include "Game.h"
#include <cstdio>

using asio::ip::tcp;
// our Game object
Game* g_game = 0;
int main(int argc, char* argv[])
{
	//加了下面两句即可在/SUBSYSTEM:WINDOWS 的条件下用控制台输出

	asio::io_service io;
	tcp::acceptor acceptor(io, tcp::endpoint(tcp::v4(), 13));
	for(;;)
	{
		tcp::socket socket(io);
		acceptor.accept(socket);
		asio::write(socket, asio::buffer("Hello Server"));
	}

	AllocConsole();
	freopen("CONOUT$", "w", stdout);
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
