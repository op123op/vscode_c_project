#include <stdio.h>
#include <pthread.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

void * func(void *arg ){
    int *i = calloc(1,4);
    *i = 1;
    while (1)
    {
        printf("--这里是子线程%d\n",pthread_self());
        sleep(1);
        pthread_exit(i);
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
    printf("-----这里是主线程%d\n",pthread_self());
    sleep(1);
    int *exit1;
    if(pthread_join(p_id,(void*)&exit1)){
        fprintf(stderr,"结合失败:%s\n",strerror(errno));
        return -1;
    }
    printf("%d\n",*exit1);
    return 0;
}
