/* This file should should implement the getTime() function. 
   The getTime() function should send request (over socket) to the time manager service (daemon) and get the response.
   This function should not directly read the time from the system */

#include</home/ee212784/Downloads/time_manager/lib/include/time_manager.h>


#include<string.h>
#include<fcntl.h>
#include<stdlib.h>

int64_t getTime()
{
   
	int server_sd,client_sd;
	int64_t integer;
	char rbuf[20]={0};

	client_sd=socket(AF_INET,SOCK_STREAM,0);
	printf("socket id: %d\n",client_sd);

	struct sockaddr_in addr;

	addr.sin_family=AF_INET;
	addr.sin_addr.s_addr=inet_addr("127.0.0.1");
	addr.sin_port=50166;

	server_sd=connect(client_sd,(struct sockaddr *)&addr,sizeof(addr));
	
	if(server_sd==-1)
	{
		perror("");
	}
	else
	{
		printf("request is accepted by server\n");
		recv(client_sd,rbuf,25,0);
		printf("data is receive from server\n");
		integer = strtol(rbuf, NULL, 10);  
      	memset(&rbuf,'\0',25);
	}
   

   return  integer;
}


