#include <sys/socket.h>
#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <pthread.h>


int main(int argc, char const *argv[])
{
    struct sockaddr_in dest_addr;
    int socket_fd = socket(AF_INET,SOCK_STREAM, 0);
    if (socket_fd == -1)
    {
        perror("创建失败");
        return -1;
    }
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_port = htons(atoi(argv[2]));
    dest_addr.sin_addr.s_addr = inet_addr(argv[1]);
    
    int rea_val = connect(socket_fd, (struct sockaddr *)&dest_addr,sizeof(dest_addr));
    if (rea_val != 0)
    {
        perror("连接失败");
        return -1;
    }
    
    char buf[128] = {0};
    while(1){
        printf("joke：");
        scanf("%s",buf);
        send(socket_fd, buf, strlen(buf), 0);
        bzero(buf,sizeof(buf));
    }
    return 0;
}