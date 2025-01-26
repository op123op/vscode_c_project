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
        kill(pid,5);
    }else if (pid == 0)
    {
        printf("这里是子进程\n");
        signal(4,func);
        signal(5,func);
        sigset_t set,oldset;
        sigemptyset(&set);
        sigaddset(&set,4);
        sigaddset(&set,5);
        sigprocmask(SIG_BLOCK,&set,&oldset);
        sleep(1);    
        sigemptyset(&set);
        sigaddset(&set,4);
        sleep(1);
        sigprocmask(SIG_UNBLOCK,&set,NULL);
        sleep(2);
        sigemptyset(&set);
        sigaddset(&set,5);
        sleep(2);
        sigprocmask(SIG_UNBLOCK,&set,NULL);
        printf("1\n");
    }
    
    
    return 0;
}
