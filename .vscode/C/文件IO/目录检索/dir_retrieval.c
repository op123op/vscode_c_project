#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>
// #include <strings.h>
#include <stdlib.h>

int find(const char * path){
    DIR *dp = opendir(path);
    if (dp == NULL)
    {
        fprintf(stderr,"打开%s失败:%s\n",path,strerror(errno));
        return -1;
    }
    struct dirent *dir = NULL;
    // struct stat *stat_info = NULL;
    char *buff = calloc(1,257);
    // bzero(buff,sizeof(buff));
    while (1)
    {
        dir = readdir(dp);
        if (dir == NULL)
        {
            free(buff);
            break;
        }
        if (dir->d_type == 8)
        {
            char *a = strrchr(dir->d_name,'.');
            if (a == NULL)
                continue;
            if (*(a+1) == 'c')
            {
                sprintf(buff,"%s/%s",path,dir->d_name);
                printf("file_path:%s\t d_ino:%ld\t d_off:%ld\t d_reclen:%hu\t d_type:%u\t d_name:%s\t \n",
                buff,dir->d_ino,dir->d_off,dir->d_reclen,dir->d_type,dir->d_name);
            }else{
                continue;
            }
        }else if(dir->d_type == 4){
            if (!strcmp(dir->d_name ,".") || !strcmp(dir->d_name ,".."))
            {
                continue;
            }
            
            sprintf(buff,"%s/%s",path,dir->d_name);
            find(buff);
            continue;
        }
        
    }
    return 0;
}
int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        printf("参数错误\n");
        return -1;
    }
    find(argv[1]);
    return 0;
}
