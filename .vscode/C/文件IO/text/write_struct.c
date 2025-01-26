#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

typedef struct node {
    char name[10];
    int age;
    char sex[4];
}Information;
int main(int argc, char const *argv[])
{
    Information xiaoho ={
        .name = "小红",
        .age = 18,
        .sex = "女"
    };
    int fd = open("1.txt",O_WRONLY | O_CREAT,066);
    if (fd == -1)
    {
        perror("打开文件失败\n");
    }
    int rel_val = write(fd,&xiaoho,sizeof(xiaoho));
    close(fd);
    return 0;
}
