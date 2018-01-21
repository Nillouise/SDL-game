#include "Starter.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <map>

std::vector<std::string> split(const std::string& s, std::string delimiter)
{
	std::vector<std::string> res;
	auto start = 0U;
	auto end = s.find(delimiter);
	while (end != std::string::npos)
	{
		res.push_back(s.substr(start, end - start));
		start = end + delimiter.length();
		end = s.find(delimiter, start);
	}
	res.push_back(s.substr(start, end));
	return res;
}

int Starter::init()
{

	std::ifstream file("setting.ini");
	try
	{
		std::string line;
		std::map<std::string, std::string> bucket;
		if (file.is_open())
		{
			while (std::getline(file, line))
			{
				std::vector<std::string> vec = split(line, "=");
				if (vec.size()>=2)
				{
					bucket[vec[0]] = vec[1];
				}
			}
			file.close();
		}
		remoteServerIP = bucket["remoteServerIP"];
		remoteServerPort = stoi(bucket["remoteServerPort"]);
		isSetMyComputerToServer = bucket["isSetMyComputerToServer"] == "true" ? true : false;
		openPort = stoi(bucket["openPort"]);
	}
	catch (...)
	{
		file.close();
		return 1;
	}
	return 0;
}
