/* The time manager daemon (continuous running process) shall be created in this file.
   It should be the socket server which caters to the request coming from the shared library */

#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<time.h>
#include<sys/ipc.h>
#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>


void *mythread(void *vargp)
{
   int client_sd= *((int*)vargp);
    printf("client request accepted\n" );
      
         int64_t current_time= time(NULL);

         char epo_time[20]={0};
      
         sprintf(epo_time,"%ld",current_time);
         
         send(client_sd,epo_time,strlen(epo_time)+1,0);
         
         printf("date is sent to client\n");

         close(client_sd);
         pthread_exit(NULL);
         return 0;
}

int main()
{
   int server_sd,client_sd;
   

   server_sd=socket(AF_INET,SOCK_STREAM,0);

   struct sockaddr_in  addr;
   
   int opt=1;

   if (setsockopt(server_sd, SOL_SOCKET,SO_REUSEADDR, &opt,sizeof(opt))) 
   {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

   addr.sin_family= AF_INET;
   addr.sin_addr.s_addr=inet_addr("127.0.0.1");
   addr.sin_port=50166;

   int bind_fd = bind(server_sd,(struct sockaddr *)&addr,sizeof(addr));

   if(bind_fd < 0)
   {
      printf("Binding fails\n");
      perror(" ");
   }

   

   pthread_t tid[10];

   int i=0;

   while(1)
   {    
      
      listen(server_sd,10);
      
      printf("In listening mode\n");

      client_sd = accept(server_sd,0,0);
      if(client_sd==-1)
      {     printf("client request fail\n");
            perror(" ");
      }
      else
      {
         printf("client request is accepted\n ");
         printf("Creating thread \n");
      }
      
      
      pthread_create(&tid[i++],NULL,mythread,& client_sd); 
         /*pthread_join( tid[i-1], NULL);
         exit(0);*/

      
      /* pthread_exit(NULL);*/
      close(client_sd);
      
   }
   
   close(server_sd);
   /*shutdown(server_sd, SHUT_RDWR);*/
   return 0;
}
