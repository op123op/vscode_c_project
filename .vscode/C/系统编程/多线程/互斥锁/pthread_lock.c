#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

pthread_mutex_t cond;
char *p = NULL;

void* func(void * arg){
    while (1)
    {
        printf("func：正在等待获取资源....\n");
        pthread_mutex_lock(&cond);
        printf("func：获取成功，以上锁\n");
        printf("func收到消息：%s\n",p);
        
        pthread_mutex_unlock(&cond);    
        printf("func：已解锁\n");
        sleep(1);
        
    }
}

int main(int argc, char const *argv[])
{
    p = calloc(1,128);
    int rea_val = pthread_mutex_init(&cond,NULL);
    if (rea_val == -1)
    {
        perror("线程锁初始化失败");
        return -1;
    }
    pthread_t p_id ;
    pthread_create(&p_id,NULL,func,NULL);
    while (1){
        printf("main：正在等待获取资源....\n");
        pthread_mutex_lock(&cond);
        printf("main：获取成功，以上锁\n");
        printf("main：");
        fgets(p,128,stdin); 
        pthread_mutex_unlock(&cond);   
        printf("main:以解锁\n"); 
        sleep(1);
        
    }
    return 0;
}
