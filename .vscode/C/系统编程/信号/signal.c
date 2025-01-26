#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

void func(int arg){
    printf("执行了，%d\n",arg);
}
int main(int argc, char const *argv[])
{
    int pid = fork();
    if (pid > 0)
    {
        printf("这里是父进程\n");
        sleep(2);
        kill(pid,4);
    }else if (pid == 0)
    {
        int i = 0;
        if(signal(4,func) == SIG_ERR){
            perror("执行失败");
        }
        while (1)
        {
            printf("这里执行了%d次\n",i);
            sleep(1);
            i++;
        }
        
    }
    
    
    return 0;
}
