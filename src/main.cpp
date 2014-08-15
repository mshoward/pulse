#include "main.hpp"
////g++ test.cpp -std=c++11 -pthread -Wall -o testing

void pmsg(std::string str)
{
	std::cout << str << std::endl;
}

int main(int argc, char *argv[])
{
	sock_int sox;
	if(!sox.init())
	{
		if(!sox.start(atoi(argv[1])))
		{
			if(!sox.acceptConnection())
			{
				while(sox.readOnceFromConnection());
			}
			else
			{
				std::cout << "accept connection failed" << std::endl;
			}
		}
		else
		{
			pmsg("start fail");
			pmsg(std::to_string(sox.errorNo));
		}
	}
	else
	{
		pmsg("init fail");
	}
	return 0;
}
