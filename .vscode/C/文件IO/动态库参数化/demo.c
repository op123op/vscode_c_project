#include <stdio.h>
#include <dlfcn.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    FILE *fp = fopen("config","r");
    if (fp == NULL)
    {
        perror("打开文件失败\n");
        return -1;
    }  
    char *buff = calloc(1,30);
    if (fgets(buff,30,fp) == NULL)
    {
        perror("读取失败\n");
        return -1;
    }
    printf("%s\n",buff);
    void * dl = dlopen(strtok(buff,"\n"), RTLD_NOW );
    if (dl == NULL)
    {
        printf("打开动态库失败\n");
        return -1;
    }
    
    int (*dest)(void) = dlsym(dl,"dest");
    if (dest == NULL)
    {
        fprintf(stderr,"查找符号失败:%s",strerror(errno));
        return -1;
    }
    dest();
    fclose(fp);
    dlclose(dl);
    return 0;
}
