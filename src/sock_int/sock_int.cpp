#pragma once
sock_int::sock_int()
{
	sockfd = 0;
	newsockfd = 0;
	portno = 0;
	clilen = 0;
	n = 0;
	errorNo = 0;
	memset(&buffer, 0, sizeof(buffer));
	#ifdef PULSE_DEBUG
	printmsg("sock_int created");
	#endif
}
sock_int::~sock_int()
{
}


//errorNo = -1 == failure to open socket
int sock_int::init()
{
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0)
	{
		errorMsg = "Error opening socket";
		errorNo = -1;
		return errorNo;
	}
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	clilen = sizeof(cli_addr);
	#ifdef PULSE_DEBUG
	printmsg("sock_int initialized");;
	#endif
	return errorNo;
}


//errorNo = -2 error on binding to port
//binds and begins listening for connections
int sock_int::start(int thisPort)
{
	#ifdef PULSE_DEBUG
	printmsg("starting sock_int...");
	printmsg("with parameter " + std::to_string(thisPort));
	#endif
	portno = thisPort;
	serv_addr.sin_port = htons(portno);
	if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
	{
		errorMsg = "ERROR on binding";
		errorNo = -2;
		return errorNo;
	}
	listen(sockfd, 12);
	#ifdef PULSE_DEBUG
	printmsg("sock_int started");
	#endif
	return errorNo;
}


//errorNo = -3 on accepting connection error
int sock_int::acceptConnection()
{
	newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, (unsigned int *) &clilen);
	if (newsockfd < 0)
	{
		errorMsg = "Error accepting connection";
		errorNo = -3;
		return errorNo;
	}
	#ifdef PULSE_DEBUG
	printmsg("sock_int connection accepted");
	#endif
	return errorNo;
}
//errorNo = -4 on reading from socket error
int sock_int::readOnceFromConnection()
{
	#ifdef PULSE_DEBUG
	printmsg("sock_int message read begin...");
	#endif
	memset(&buffer, 0, sizeof(buffer));
	n = read(newsockfd, buffer, 255);
	if(n < 0)
	{
		errorMsg = "Error reading from socket";
		errorNo = -4;
		return errorNo;
	}
	#ifdef PULSE_DEBUG
	printmsg("sock_int message of " + std::to_string(n) + " bytes read:");
	#endif
	std::string temp(buffer);
	std::cout << temp << std::endl;
	
	return n;
}

void sock_int::printmsg(std::string str)
{
	std::cout << str << std::endl;
}









