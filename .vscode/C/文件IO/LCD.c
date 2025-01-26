#include <stdio.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#define PATH "/dev/fb0"
int main(int argc, char const *argv[])
{
    printf("11\n");
    int fd = open(PATH,O_RDWR);//内存映射要读写权限
    if (fd == -1)
    {
        perror("open is failed:");
        close(fd);
        return 0;
    }
    printf("fd:%d\n",fd);
    int color = 0x00FF00;
    // int fd_w = 0;
    int *p = (int *)mmap(NULL,800*480*4,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
    if (p == MAP_FAILED)
    {
        perror("内存映射失败\n");
        return -1;
    }
    printf("%p,12\n",p);
    for (int i = 0; i < 800*480; i++)
    {
        *(p+i)= color;
    }
    printf("37\n");
    close(fd);
    munmap(p,800*480*4);
    p = NULL;
    return 0;
}
