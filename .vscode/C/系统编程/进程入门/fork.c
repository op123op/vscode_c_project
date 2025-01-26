#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
    int stat_loc;
    pid_t pid = fork();
    if (pid > 0)
    {
        wait(stat_loc);
        printf("11\n");
        if (WIFEXITED(stat_loc))
        {
            printf("正常退出\n");
        }
        
    }else if (pid == 0)
    {
        execlp("rm","rm","-f","2.c",NULL);
    }
    return 0;
}
