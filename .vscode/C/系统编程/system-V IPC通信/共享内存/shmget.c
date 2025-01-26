#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

char *p = NULL;
void func(int arg){
    sprintf(p,"进程%d已退出%d",getpid(),arg);
    exit(0);
}

int main(int argc, char const *argv[])
{
    signal(10,func);
    key_t key = ftok("./", 1);

    int shmget_t = shmget(key, 4096, IPC_CREAT|0666);
    p = shmat(shmget_t, NULL, SHM_RND);
    // memcpy(p,"hello",sizeof("hello"));
    sprintf(p,"hello,%d",getpid());
    pause();
    
    // shmdt(p);
    // shmctl(shmget_t , IPC_RMID, NULL);
    return 0;
}