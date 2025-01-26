#include <stdio.h>
#include <signal.h> 
#include <strings.h>
#include <sys/types.h>
#include <unistd.h>

void func(int sig, siginfo_t *info, void *arg){
    printf("信号：%d,发送数据：%s\n,arg：%d\n",sig,(char*)info->si_ptr,arg);
}
int main(int argc, char const *argv[])
{
    struct sigaction act ;
    bzero(&act,0);
    act.sa_sigaction = func;
    act.sa_flags = SA_SIGINFO;
    int sig = sigaction(3,&act,NULL);
    if (sig)
    {
        perror("捕获失败");
        return -1;
    }
    union sigval value;
    value.sival_int = 1024;
    value.sival_ptr = "hello";
    if (sigqueue(getpid(),3,value))
    {
        perror("发送失败：");
    }
    
    printf("发送信号成功\n");
    return 0;
}
 