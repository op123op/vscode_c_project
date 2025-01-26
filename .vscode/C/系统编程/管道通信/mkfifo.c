#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#define PATH "/tmp/mkfifo"

void mkfifo_1(){
    if(access(PATH, F_OK)){
        int fo = mkfifo(PATH,0666);
        if (fo == -1)
        {
            perror("创建管道文件失败");
            return ;
        }
        
    }
}

void read_1(){
    int fd = open(PATH,O_RDONLY);
    if (fd == -1)
    {
        perror("文件读取失败");
        return ;
    }
    char msg[24] = {0};
    size_t rea_val = read(fd,msg,sizeof(msg));  
    if (rea_val == -1)
    {
        perror("读取失败");
        return ;
    }
    printf("读取%ld个字节,读到：%s\n",rea_val,msg);
}

void write_1(){
    int fd = open(PATH,O_WRONLY);
    if (fd == -1)
    {
        perror("文件打开失败");
        return ;
    }
    size_t rea_val = write(fd,"hello,world",sizeof("hello,world"));  
    if (rea_val == -1)
    {
        perror("写入失败");
        return ;
    }
    printf("写入%ld个字节\n",rea_val);
}
int main(int argc, char const *argv[])
{
    int pid = fork();
    if (pid > 0)
    {
        mkfifo_1();
        write_1();
    }else if (pid == 0)
    {
        sleep(3);
        read_1();
    }
    return 0;
}
