#include <sys/socket.h>
#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/types.h>  


int main(int argc, char const *argv[])
{
    if (argc>3 || argc<3)
    {
        printf("参数不正确，应(./xxx 目标ip 目标端口)\n");
        return -1;
    } 

    struct sockaddr_in dest_addr;
    int socket_fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (socket_fd == -1)
    {
        perror("创建失败");
        return -1;
    }

    int flag = -1;
    int optlen  = sizeof(int);
    getsockopt(socket_fd,SOL_SOCKET, SO_BROADCAST,&flag,&optlen );
    printf("%d\n",flag);
    int optval = 1;
    setsockopt(socket_fd,SOL_SOCKET, SO_BROADCAST,&optval,optlen );
    getsockopt(socket_fd,SOL_SOCKET, SO_BROADCAST,&flag,&optlen );
    printf("%d\n",flag);
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_port = htons(atoi(argv[2]));
    dest_addr.sin_addr.s_addr = inet_addr(argv[1]);
    char buf[128] = {0};
    while(1){
        printf("joke：");
        scanf("%s",buf);
        sendto(socket_fd, buf, strlen(buf), 0,(struct sockaddr *)&dest_addr, sizeof(dest_addr));
        bzero(buf,sizeof(buf));
    }
    return 0;
}