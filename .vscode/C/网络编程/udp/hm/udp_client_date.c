#include <sys/socket.h>
#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    if (argc>3 || argc<3)
    {
        printf("参数不正确，应(./xxx 本机ip 本机端口)\n");
        return -1;
    }
    struct sockaddr_in dest_addr;
    time_t now;
    
    char buf[128] = {0};
    int socket_fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (socket_fd == -1)
    {
        perror("创建失败");
        return -1;
    }
    
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_port = htons(atoi(argv[2]));
    dest_addr.sin_addr.s_addr = inet_addr(argv[1]);
    time(&now);
    struct tm *local_time1 = localtime(&now);
    sprintf(buf,"%04d-%02d-%02d %02d:%02d:%02d\n",local_time1->tm_year + 1900,local_time1->tm_mon + 1,local_time1->tm_mday,local_time1->tm_hour,local_time1->tm_min,local_time1->tm_sec);
    sendto(socket_fd, buf, strlen(buf), 0,(struct sockaddr *)&dest_addr, sizeof(dest_addr));
    bzero(buf,sizeof(buf));
    return 0;
}
