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
    int fd = open(PATH,O_RDONLY);
    if (fd == -1)
    {
        perror("文件读取失败");
        return -1;
    }
    char msg[24] = {0};
    size_t rea_val = read(fd,msg,sizeof(msg));  
    if (rea_val == -1)
    {
        perror("读取失败");
        return -1;
    }
    printf("读取%ld个字节,读到：%s\n",rea_val,msg);

    return 0;
}
