#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <errno.h>
#include <sys/socket.h>
#include <sys/types.h>

#define PORT "9990"
#define HOST "20.108.244.219"
#define MAX 100

void* get_in_addr(struct sockaddr *sa)
{
    if(sa->sa_family = AF_INET)
        {
            return &(((struct sockaddr_in *)(sa))->sin_addr);
        }
        return &(((struct sockaddr_in6*)(sa))->sin6_addr);
}


int get_floor(char* buf,int sizeof_buf)
{   
    int floor_no = 0;
    for(int i=0;i<sizeof_buf;i++)
    {
        if(buf[i] == '(')
            floor_no ++;
        else if(buf[i]==')')
            floor_no --;
    }
    return floor_no;
}


int main()
{
    int status,sockfd,numbytes,floor;
    char buf[MAX];
    addrinfo hints,*servinfo,*p;

    memset(&hints,0,sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if((status = getaddrinfo(HOST,PORT,&hints,&servinfo)) == -1)
    {
        fprintf(stderr,"getaddrinfo:");
        return(1);
    }

    for(p=servinfo;p != NULL;p->ai_next = p)
    {
        sockfd = socket(p->ai_family,p->ai_socktype,p->ai_protocol);
        if(sockfd == -1)
        {
            perror("Client: Socket");
            continue;
        }

        if((connect(sockfd,p->ai_addr,p->ai_addrlen))==-1)
        {
            perror("Client: Connect");
            continue;
        }
        break;
    }

    if(p=NULL)
    {
        fprintf(stderr,"Failed to connect!");
        return 2;
    }

    freeaddrinfo(servinfo);

    if((numbytes = recv(sockfd,buf,MAX-1,0)) == -1)
    {
        perror("Client: recv");
        exit(1);
    }
    
    buf[numbytes] = '\0';

    floor = get_floor(buf,numbytes);

    if((send(sockfd,&floor,sizeof(floor),0))== -1)
    {
        perror("Client: Send");
        exit(1);
    }
    close(sockfd);
    return 0;
}