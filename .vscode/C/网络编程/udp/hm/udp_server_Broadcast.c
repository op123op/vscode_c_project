#include <sys/socket.h>
#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <pthread.h>

int main(int argc, char const *argv[])
{
    if (argc>3 || argc<3)
    {
        printf("参数不正确，应(./xxx 本机ip 本机端口)\n");
        return -1;
    }
    struct sockaddr_in host_addr;
    struct sockaddr_in src_addr;
    socklen_t src_addr_len = sizeof(src_addr);
    
    char buf[128] = {0};
    int socket_fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (socket_fd == -1)
    {
        perror("创建失败");
        return -1;
    }
    
    host_addr.sin_family = AF_INET;
    host_addr.sin_port = htons(atoi(argv[2]));
    // host_addr.sin_addr.s_addr = inet_addr(argv[1]);
    host_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    bind(socket_fd, (struct sockaddr *)&host_addr,sizeof(host_addr));
    printf("1\n");
    while(1){
        recvfrom(socket_fd, buf, sizeof(buf),0,(struct sockaddr *)&src_addr,&src_addr_len);
        printf("rosk：%s,对方ip：%s,对方端口：%d\n",buf,inet_ntoa(src_addr.sin_addr),ntohs(src_addr.sin_port));
        bzero(buf,sizeof(buf));
    }
    return 0;
}
