#include <stdio.h>
#include <pthread.h>
#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */
#include <semaphore.h>
#include <stdlib.h>
#include <sys/shm.h>


char* shm_init(){
    key_t key = ftok("./", 1);
    int shm_id = shmget(key, 4096, IPC_CREAT | 0666);
    if (shm_id == -1)
    {
        perror("共享内存初始化失败");
        exit(1);
    }
    char *p = shmat(shm_id,NULL,0);
    if (p == (void*)-1)
    {
        perror("共享内存初始化失败");
        exit(1);
    }
    return p;
}
int main(int argc, char const *argv[])
{
    char *p = shm_init();
    sem_t* sem_id = sem_open("/my_sem_name",O_CREAT,0644,0);
    sem_wait(sem_id);
    while (1)
    {
        printf("正在读取资源....\n");
        sem_wait(sem_id);
        printf("资源获取成功....\n");
        printf("%s\n",p);
        sem_post(sem_id);
        printf("释放资源成功....\n");
    }
    
    return 0;
}
