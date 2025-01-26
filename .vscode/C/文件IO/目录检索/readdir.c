#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
int main(int argc, char const *argv[])
{
    DIR *dp = opendir(".");
    while (1)
    {
        
        struct dirent *dir = readdir(dp);
        if (dir == NULL)
        {
            closedir(dp);
            return -1;
        }
        if (dir->d_type == 010)
        {
            char *a = strrchr(dir->d_name,'.');
            if (a == NULL)
                continue;
            if (*(a+1) == 'c')
            {
                printf("d_ino:%ld\t d_off:%ld\t d_reclen:%hu\t d_type:%u\t d_name:%s\t \n",
                dir->d_ino,dir->d_off,dir->d_reclen,dir->d_type,dir->d_name);
            }else{
                continue;
            }
        }else if(dir->d_type == 4){
            if (!strcmp(dir->d_name,".") || !strcmp(dir->d_name,".."))
            {
                continue;
            }
            
            printf("d_type:%u\t d_name:%s\t \n",
                dir->d_type,dir->d_name);
            continue;
        }
        
    }
    return 0;
}
