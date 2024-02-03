#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>
#include<netdb.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<fcntl.h>
#define PORT 6490
int main()
{
int i=0,sockfd,len;
char buf1[40],buf2[20000];
FILE* fp;
struct sockaddr_in their_addr;
if((sockfd=socket(AF_INET, SOCK_STREAM,0))==-1)
{
perror("socket");
exit(1);
}
their_addr.sin_family=AF_INET;
their_addr.sin_port=htons(PORT);
their_addr.sin_addr.s_addr=inet_addr("127.0.0.1");
memset(&(their_addr.sin_zero), '\0', 8);
if(connect(sockfd, (struct sockaddr *)&their_addr, sizeof(struct sockaddr))==-1)
{
perror("connect");
exit(1);
}
printf("CLIENT is online!\n");
printf("CLIENT:Enter the filename to be displayed: ");
scanf("%s",buf1);
send(sockfd,buf1,sizeof(buf1),0);
if(recv(sockfd,buf2,sizeof(buf2),0)==1)
{
perror("recv");
exit(1);
}
else
{
printf("Displyaing the contents of %s",buf1);
printf("\n%s\n",buf2);
}
close(sockfd);
return 0;
}
