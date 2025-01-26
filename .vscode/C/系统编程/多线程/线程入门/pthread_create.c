#include <stdio.h>
#include <pthread.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>

void * func(void *arg ){
    while (1)
    {
        printf("--这里是子线程%d\n",pthread_self());
        sleep(1);
    }
}
int main(int argc, char const *argv[])
{
    pthread_t p_id = 0;
    int rea_val = pthread_create(&p_id,NULL,func,NULL);
    if (rea_val != 0)
    {
        fprintf(stderr,"创建线程失败：%s\n",strerror(errno));
    }
    while (1)
    {
        printf("-----这里是主线程%d\n",pthread_self());
        sleep(1);
    }
    
    return 0;
}
