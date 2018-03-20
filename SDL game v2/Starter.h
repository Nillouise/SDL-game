#pragma once
#include <string>
class Starter
{
public:
	//0代表正常初始化，1代表初始化错误
	int init();

private:
	std::string remoteServerIP;
	int remoteServerPort;
	bool isSetMyComputerToServer;
	int openPort;
	int robotNumber;
	bool robotStart;

public:

	int robot_number() const
	{
		return robotNumber;
	}

	void set_robot_number(int robot_number)
	{
		robotNumber = robot_number;
	}

	bool robot_start() const
	{
		return robotStart;
	}

	void set_robot_start(bool robot_start)
	{
		robotStart = robot_start;
	}

	std::string remote_server_ip() const
	{
		return remoteServerIP;
	}

	void set_remote_server_ip(const std::string& remote_server_ip)
	{
		remoteServerIP = remote_server_ip;
	}

	int remote_server_port() const
	{
		return remoteServerPort;
	}

	void set_remote_server_port(int remote_server_port)
	{
		remoteServerPort = remote_server_port;
	}

	bool is_set_my_computer_to_server() const
	{
		return isSetMyComputerToServer;
	}

	void set_is_set_my_computer_to_server(bool is_set_my_computer_to_server)
	{
		isSetMyComputerToServer = is_set_my_computer_to_server;
	}

	int open_port() const
	{
		return openPort;
	}

	void set_open_port(int open_port)
	{
		openPort = open_port;
	}
};