#include <stdio.h>
#include <netdb.h>
int main(int argc, char *argv[])
{
	int mysocket;
	int conn;
	int port;
	int start = 0;
	int end  = 65535;
	char * destiny;
	if(argc < 2)
	{
		printf("How to use portscan\n");
		printf("%s 10.1.1.101\n",argv[0]);
		return 0;	
	}

	destiny = argv[1];
	struct sockaddr_in alvo;
	
	for(port = start; port < end; port++)
	{
		mysocket = socket(AF_INET, SOCK_STREAM, 0);
		alvo.sin_family = AF_INET;
		alvo.sin_port = htons(port);
		alvo.sin_addr.s_addr = inet_addr(destiny);
	
		conn = connect(mysocket, (struct sockaddr *)&alvo, sizeof alvo);
		if(conn == 0)
		{
			printf("Port %d - status [OPENNED] \n", port);
		}
		close(mysocket);
		close(conn);
	}
}
