#include "main.hpp"
////g++ test.cpp -std=c++11 -pthread -Wall -o testing

void pmsg(std::string str)
{
	
	std::cout << str << std::endl;
}

int main(int argc, char *argv[])
{
	int er = 0;
	control controller;
	std::string bucket;
	int previous = -1;
	int errors = 0;
	pmsg("Controller instantiated...");
	er = controller.init();
	pmsg("Controller initialized...");
	if (!er)
	{
		pmsg("Controller successful!\t......\tReading...");
		while(controller.dirty_sock_connected())
		{
			bucket = controller.Next_dirty_sock_line();
			if (bucket != "" && bucket != EMPTYSTRING)
			{
				
				if (previous + 1 != std::stoi(bucket)) std::cout << "ERROR: "  << errors++ << std::endl;
				std::cout << "While connected: " << bucket << std::endl;
				previous++;// = std::stoi(bucket);
				if (errors > 1)
				{
					return 0;
				}
				
			}
		}
		while(controller.dirty_sock.hasUnreadData())
		{
			bucket = controller.Next_dirty_sock_line();
			if(bucket != "" && bucket != EMPTYSTRING)
			std::cout << "After connection: " << bucket << "..."<< std::endl;
		}
	}
	return 0;
}
