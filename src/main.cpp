#include "main.hpp"
////g++ test.cpp -std=c++11 -pthread -Wall -o testing
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
		}
	}
	return 0;
}
