#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 
#include <stdlib.h>
#include <time.h>


void error(char *msg)
{
    perror(msg);
    exit(0);
}

void fillRand(char *buf, int bufSize, int i)
{
	int randedA, randedD, randedC, randedB;
	bzero(buf, bufSize);
	//srand(time(0));
	
	randedA = rand();
	randedB = rand();
	randedC = rand();
	randedD = rand();
	randedA = randedB = randedC = randedD = i;
	snprintf(buf, bufSize, "%X-%X-%X-%X\n", randedA, randedB, randedC, randedD);
	
}

int main(int argc, char *argv[])
{
    int sockfd, portno, n, i;
	int randed;
	char buf1[256];
    struct sockaddr_in serv_addr;
    struct hostent *server;
	
    char buffer[512];
    if (argc < 3) {
       fprintf(stderr,"usage %s hostname port\n", argv[0]);
       exit(0);
    }
    srand(time(0));
    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        error("ERROR opening socket");
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, 
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(portno);
    if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0) 
        error("ERROR connecting");
    i = 0;
    while(i < atoi(argv[3]))
    {
		//printf("Please enter the message: ");
		printf("Time: %d\n", i);
		//i++;
		bzero(buffer,512);
		//fgets(buffer,255,stdin);
		fillRand(buffer, 512, i);
		n = write(sockfd,buffer,strlen(buffer));
		if (n < 0) 
			 error("ERROR writing to socket");
		//bzero(buffer,256);
		//n = read(sockfd,buffer,255);
		if (n < 0) 
			 error("ERROR reading from socket");
		//printf("%s\n",buffer);
		i++;
	}
    return 0;
}
