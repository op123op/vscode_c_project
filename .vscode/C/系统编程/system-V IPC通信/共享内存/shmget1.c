#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    key_t key = ftok("./", 1);

    int shmget_t = shmget(key, 4096, IPC_CREAT|0666);
    char *p = shmat(shmget_t, NULL, SHM_RND);
    // memcpy(p,"hello",sizeof("hello"));
    printf("%s\n",p);
    char *tmp = strpbrk(p,",")+1;
    char arr[8] ;
    int i;
    for (i = 0; tmp[i] != '\0'; i++)
    {
        arr[i] = tmp[i];
    }
    arr[i] = '\0';
    printf("%s\n",arr);
    int pid = atoi(arr);
    printf("%d\n",pid);
    kill(pid,10);
    sleep(1);
    printf("%s\n",p);
    // shmdt(p);
    // shmctl(shmget_t , IPC_RMID, NULL);
    return 0;
}
