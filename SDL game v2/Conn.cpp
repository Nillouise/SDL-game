#include "Conn.h"

using asio::ip::tcp;

void ConnMain()
{
	asio::io_service io;
	tcp::acceptor acceptor(io, tcp::endpoint(tcp::v4(), 13));
	for (;;)
	{
		tcp::socket socket(io);
		acceptor.accept(socket);
		asio::write(socket, asio::buffer("Hello Server"));
	}
}