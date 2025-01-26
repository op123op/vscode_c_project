#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#define PATH "/tmp/mkfifo"

int main(int argc, char const *argv[])
{
    if(access(PATH, F_OK)){
        int fo = mkfifo(PATH,0666);
        if (fo == -1)
        {
            perror("创建管道文件失败");
            return -1;
        }
        
    }
    int fd = open(PATH,O_WRONLY);
    if (fd == -1)
    {
        perror("文件打开失败");
        return -1;
    }
    size_t rea_val = write(fd,"hello,world",sizeof("hello,world"));  
    if (rea_val == -1)
    {
        perror("写入失败");
        return -1;
    }
    printf("写入%ld个字节\n",rea_val);

    return 0;
}
