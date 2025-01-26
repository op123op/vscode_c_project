#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/sysmacros.h>



int main(int argc, char const *argv[])
{
    size_t p = 0;
    struct stat file_info;
    stat("fileinfo.c",&file_info);
    if (S_ISCHR(file_info.st_mode))
    {
        printf("这是字符文件文件\n");
    }
    
    printf("st_dev:%u\t,st_mode:%u\tst_ino:%u\t,st_nlink:%u\tst_uid:%u\t,st_gid:%u\tst_rdev:%u\tst_atime:%u\t,st_mtime:%u\t"
        "st_ctime:%u\t st_size:%lu\n",file_info.st_dev,file_info.st_mode,file_info.st_ino,file_info.st_nlink,file_info.st_uid,file_info.st_gid,file_info.st_rdev,
        file_info.st_atime,file_info.st_mtime,file_info.st_ctime,file_info.st_size
        );
    printf("主设备号:%d\t从设备号:%d\n",major(file_info.st_rdev),minor(file_info.st_rdev));
    return 0;
}

