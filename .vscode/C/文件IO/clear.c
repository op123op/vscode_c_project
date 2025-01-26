#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
int main(int argc, char const *argv[])
{
    int fd = open("abc.c",O_RDWR|O_TRUNC);
    char a[]="hell";
    write(fd,a,sizeof(a)-1);
    read(fd,a,5);
    printf("a:%s",a);
    /* code */
    return 0;
}
