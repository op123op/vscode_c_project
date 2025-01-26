#include <sys/socket.h>
#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <pthread.h>

void * func(void *arg){
    char *argv = (char *)arg;
    int sock_fd = socket(AF_INET, SOCK_DGRAM, 0);
    struct sockaddr_in host_addr1;
    struct sockaddr_in src_addr;
    socklen_t src_addr_len = sizeof(src_addr);
    host_addr1.sin_family = AF_INET;
    host_addr1.sin_port = htons(60002);
    host_addr1.sin_addr.s_addr = htonl(INADDR_ANY);
    if(bind(sock_fd, (struct sockaddr *)&host_addr1,sizeof(host_addr1))){
        perror("绑定失败");
        exit(-1);
    }
    printf("ip：%s,端口：%d\n",inet_ntoa(host_addr1.sin_addr),ntohs(host_addr1.sin_port));
    char buf[128] = {0};
    while (1)
    {
        recvfrom(sock_fd, buf, sizeof(buf),0,(struct sockaddr *)&src_addr,&src_addr_len);
        printf("target(%s) is buf：%s\n",inet_ntoa(src_addr.sin_addr),buf);
        bzero(buf,sizeof(buf));
    }
}

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
    pthread_t  thread;
    int pth_id = pthread_create(&thread,NULL,func,(void*)argv);
    if (pth_id != 0)
    {
        perror("线程创建失败");
        return -1;
    }
    
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