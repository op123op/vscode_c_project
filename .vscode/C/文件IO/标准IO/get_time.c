#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

// 编写一个程序，使之每隔1秒保存一次当前系统的时间和行号，保存到一个普通文件 time.txt
// 中。要求在按 ctrl+c 终止该程序后，文件 time.txt 能正常保存到所有的信息，并且在重启程序能继续保
// 存时间，并且保持行号连续，如下所示
int main(int argc, char const *argv[])
{
    FILE *fd = fopen("time.txt","a+");
    time_t now;
    int hang = 1;
    // fseek(fd,0,SEEK_SET);
    // while (1)
    // {
    //     int a =fgetc(fd);
    //     if ( a == '\n')
    //     {
    //         hang++;
    //     }else if (a == EOF)
    //     {
    //         hang++;
    //         break;  
    //     }   
    // }
    
    // 获取当前行号
    fseek(fd,-1,SEEK_END);
    while (1)
    {
        fseek(fd,-1,SEEK_CUR);
        char a =fgetc(fd);
        fseek(fd,-1,SEEK_CUR);
        // printf("....%ld,,,%c\n",ftell(fd),a);
        if ( a == '\n' | ftell(fd) == 0)
        {
            // printf("%ld\n",ftell(fd));
            fscanf(fd,"%d",&hang);
            hang++;
            break;
        } 
    }

    // 循环保存时间和行号和显示
    while (1)
    {
        
        time(&now);
        struct tm *local_time1 = localtime(&now);
        char time[30] ;
        sprintf(time,"%d %04d-%02d-%02d %02d:%02d:%02d\n",hang,local_time1->tm_year + 1900,local_time1->tm_mon + 1,local_time1->tm_mday,local_time1->tm_hour,local_time1->tm_min,local_time1->tm_sec);
        // strftime(time, 30, "%Y-%m-%d %H:%M:%S\n", local_time1);
        // printf("%s",time);
        fseek(fd,0,SEEK_SET);
        printf("%ld\n",ftell(fd));
        // char h = '\n';
        // if(fgetc(fd) != '\n'){
        //     fputs(&h, fd);
        // }
        int ret_val = fputs(time, fd);
        hang++;
        if (ret_val == EOF)
        {
            perror("写入失败：");
        }
        fseek(fd,-(strlen(time)),SEEK_CUR);//在写完当前时间后,光标(光标在文件的末尾)从最后移动到一条时间数据(比如5 2024-09-20 18:12:01)前显示
        int hanghao;
        int tm_year;
        int tm_mon;
        int tm_mday;
        int tm_hour;
        int tm_min;
        int tm_sec;
        fscanf(fd,"%d %d-%d-%d %d:%d:%d",&hanghao,&tm_year,&tm_mon,&tm_mday,&tm_hour,&tm_min,&tm_sec);
        printf("本地时间为：%d %04d-%02d-%02d %02d:%02d:%02d\n",hanghao,
           tm_year, // 年份从1900开始
           tm_mon,     // 月份从0开始
           tm_mday,
           tm_hour,
           tm_min,
           tm_sec);
        // printf("本地时间为： %04d-%02d-%02d %02d:%02d:%02d\n",
        //    local_time1->tm_year + 1900, // 年份从1900开始
        //    local_time1->tm_mon + 1,     // 月份从0开始
        //    local_time1->tm_mday,
        //    local_time1->tm_hour,
        //    local_time1->tm_min,
        //    local_time1->tm_sec);
        
        sleep(1);
    }
    return 0;
}
