#include <sys/socket.h>
#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>


int main(int argc, char const *argv[])
{
    struct sockaddr_in host_addr;
    int socket_fd = socket(AF_INET, SOCK_STREAM , 0);
    if (socket_fd == -1)
    {
        perror("创建失败");
        return -1;
    }
    host_addr.sin_family = AF_INET;
    host_addr.sin_port = htons(atoi(argv[2]));
    host_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    bind(socket_fd, (struct sockaddr *)&host_addr,sizeof(host_addr));
    listen(socket_fd, 3);
    int len = sizeof(host_addr);
    int client_fd = accept(socket_fd,(struct sockaddr *)&host_addr,&len);
    char buf[128] = {0};
    while(1){
        printf("joke：");
        read(client_fd, buf, sizeof(buf));
        printf("joke:%s\n",buf);
        bzero(buf,sizeof(buf));
    }
    return 0;
}