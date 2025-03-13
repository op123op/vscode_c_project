#include <sys/socket.h>
#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <pthread.h>
#include <netdb.h>

#define URL "https://api1.zhyunxi.com/"
//#define URL "www.baidu.com"
#define HOST "http://api.zhyunxi.com/api.php?api=2&key=aed9f67ef079cad6c2e623c394acd58f"
#define PORT 80

int main(int argc, char const *argv[])
{
    struct addrinfo hints, *result, *rp;
    char ipstr[INET6_ADDRSTRLEN];
    int err;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;     // 不限制 IP 地址版本
    hints.ai_socktype = SOCK_STREAM; // 使用 TCP 协议

    if ((err = getaddrinfo(URL, "80", &hints, &result)) != 0) {
        fprintf(stderr, "getaddrinfo failed: %s\n", gai_strerror(err));
        return -1;
    }
    printf("IP addresses for %s:\n", URL);
    for (rp = result; rp != NULL; rp = rp->ai_next) {
        void *addr;
        char *ipver;

        if (rp->ai_family == AF_INET) {
            struct sockaddr_in *ipv4 = (struct sockaddr_in *)rp->ai_addr;
            addr = &(ipv4->sin_addr);
            ipver = "IPv4";
        } else {
            struct sockaddr_in6 *ipv6 = (struct sockaddr_in6 *)rp->ai_addr;
            addr = &(ipv6->sin6_addr);
            ipver = "IPv6";
        }

        inet_ntop(rp->ai_family, addr, ipstr, sizeof(ipstr));
        printf("  %s: %s\n", ipver, ipstr);
    }

    return 1;
    struct sockaddr_in dest_addr;
    int socket_fd = socket(AF_INET,SOCK_STREAM, 0);
    if (socket_fd == -1)
    {
        perror("创建失败");
        return -1;
    }
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_port = htons(PORT);
    //dest_addr.sin_addr.s_addr = inet_addr(host->h_addr_list[0]);
    
    int rea_val = connect(socket_fd, (struct sockaddr *)&dest_addr,sizeof(dest_addr));
    if (rea_val != 0)
    {
        perror("连接失败");
        return -1;
    }
    
    char buf[1024] = {0};
    char buf1[1024] = {0};
    sprintf(buf,"GET %s HTTP/1.1\r\n"
                "HOST: %s\r\n"
                "\r\n",HOST,URL    
    );
    send(socket_fd, buf, strlen(buf), 0);
    bzero(buf1,sizeof(buf1));
    read(socket_fd, buf1, sizeof(buf1));
    printf("%s\n",buf1);
    return 0;
}