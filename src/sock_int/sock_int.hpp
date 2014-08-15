#pragma once

/**
 * Implentation of socket.h
 */


class sock_int
{
private:
	void printmsg(std::string);
public:
	int sockfd; //socket file descriptor
	int newsockfd; //new socket file descriptor
	int portno; //port number
	int clilen; //address size of the client
	int n; //return value for read() / write() calls
	int errorNo;
	
	char buffer[256];
	
	struct sockaddr_in serv_addr;
	struct sockaddr_in cli_addr;
	std::string errorMsg;
	
	sock_int();
	~sock_int();
	
	int init();
	
	int start(int thisPort);
	int acceptConnection();
	int readOnceFromConnection();
	
	
};
