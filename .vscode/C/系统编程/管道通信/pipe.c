#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <string.h>

//无名管道
int main(int argc, char const *argv[])
{
    int filede[2];
    int pd = pipe(filede);//必须在创建进程前创建无名管道
    int pid = fork();     //创建子进程
    if (pid > 0)
    {
        printf("父进程：\n");
        char * msg1 = "hi,Child process";
        ssize_t w_f = write(filede[1], msg1, strlen(msg1));
        if (w_f == -1)
        {
            perror("write is error:");
            return -1;
        }
        printf("写入%ld个字节\n",w_f);
    }else if (pid == 0)
    {
        printf("子进程：\n");
        char msg2[24] = {0};
        ssize_t r_f = read(filede[0],msg2,sizeof(msg2));
        if (r_f == -1)
        {
            perror("read is error:");
            return -1;
        }
        printf("读取%ld个字节,读取到的内容为：%s\n",r_f,msg2);
    }else 
    {
        printf("进程创建失败\n");
    }
    
    
    
    return 0;
}
