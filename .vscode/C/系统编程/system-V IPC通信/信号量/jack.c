#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <unistd.h>
#include <stdlib.h>

union se{
    int val;   
    struct semid_ds *buf;    
    unsigned short  *array; 
    struct seminfo  *__buf; 
};
// union se
// {
//     int val;
// };

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
int sem_init(){
    
    key_t key = ftok("./", 2);
    int sem_id = semget(key, 2, IPC_CREAT | 0644);
    if (sem_id == -1)
    {
        perror("信号量创建失败");
        exit(1);
    }
    union se set;
    set.val = 1;
    int space = semctl(sem_id, 0, SETVAL,set); //空间
    set.val = 0;
    int data = semctl(sem_id, 1, SETVAL,set); //数据
    return sem_id;
}
int main(int argc, char const *argv[])
{
    char* p = shm_init();
    int sem_id = sem_init();
    // struct sembuf{
    //         unsigned short sem_num;  /* semaphore number */
    //         short          sem_op;   /* semaphore operation */
    //         short          sem_flg;  /* operation flags */
    // }
    struct sembuf data = {
        .sem_num = 1,
        .sem_op = 1,
        .sem_flg = 0
    };
    struct sembuf space = {
        .sem_num = 0,
        .sem_op = -1,
        .sem_flg = 0
    };
    while (1)
    {
        printf("正在等待空间...\n");
        semop(sem_id,&space,1);
        fgets(p,4096,stdin);
        
        semop(sem_id,&data,1);
        printf("数据加一...\n");
        sleep(1);
    }
    
    return 0;
}
