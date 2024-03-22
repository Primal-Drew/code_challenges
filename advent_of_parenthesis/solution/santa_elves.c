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
#define HOST "20.110.238.2"
#define MAX 100

void *get_in_addr(struct sockaddr *sa)
{
    if (sa->sa_family = AF_INET)
    {
        return &(((struct sockaddr_in *)(sa))->sin_addr);
    }
    return &(((struct sockaddr_in6 *)(sa))->sin6_addr);
}

int get_floor(char *buf, int sizeof_buf)
{
    int floor_no = 0;
    for (int i = 0; i < sizeof_buf; i++)
    {
        if (buf[i] == '(')
            floor_no++;
        else if (buf[i] == ')')
            floor_no--;
    }
    return floor_no;
}

int main()
{
    int status, sockfd, numbytes,numr, floor;
    char buf[MAX];
    char rbuf[MAX];
    struct addrinfo hints; 
    struct addrinfo *servinfo;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    if ((status = getaddrinfo(HOST, PORT, &hints, &servinfo)) == -1)
    {
        fprintf(stderr, "getaddrinfo: %s", gai_strerror(status));
        return (1);
    }

    sockfd = socket(servinfo->ai_family, servinfo->ai_socktype, servinfo->ai_protocol);
    if (sockfd == -1)
    {
        perror("Client: Socket");
        exit(1);
    }

    if ((connect(sockfd, servinfo->ai_addr, servinfo->ai_addrlen)) == -1)
    {
        perror("Client: Connect");
        close(sockfd);
        exit(1);
    }
    printf("connected\n");

    if (servinfo = NULL)
    {
        fprintf(stderr, "Failed to connect!");
        close(sockfd);
        return 2;
    }

    freeaddrinfo(servinfo);

    if ((numbytes = recv(sockfd, buf, MAX - 1, 0)) == -1)
    {
        perror("Client: recv");
        close(sockfd);
        exit(1);
    }

    buf[numbytes] = '\0';
    printf("Received: %s\n",buf);

    floor = get_floor(buf, numbytes);
    // char str_floor = (char)floor;
    // char contain[MAX];
    // strcat(contain,&str_floor);
    // strcat(contain,"\n");
    sprintf(buf, "%d\n", floor);
    printf("Floor: %s", buf);

    if ((send(sockfd,buf,strlen(buf), 0)) == -1)
    {
        perror("Client: Send");
        close(sockfd);
        exit(1);
    }

    usleep(100000);
    printf("Sent to server!\n");
    

    if((numr = recv(sockfd,rbuf,MAX -1,0))== -1)
    {
        perror("Client: Recv");
        close(sockfd);
        exit(0);
    }

    printf("Result: %s\n",rbuf);

    close(sockfd);
    return 0;
}