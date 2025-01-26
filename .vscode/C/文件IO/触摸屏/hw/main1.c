#include <stdio.h>
#include "types.h"
#include <string.h>

int main(int argc, char const *argv[])
{
    LCD lcd ;
    //初始化lcd屏和触摸屏
    if (lcd_init(&lcd))
    {
        perror("初始化失败\n");
        return -1;
    }
    int x,y,num;
    char name[10];
    //获取用点击坐标
    while (1)
    {
        get_coordinate(&x,&y,lcd.fd_ts);
        if (x < 400)
        {
            num--;
            if (num < 1)
            {
                num = 3;
            }
            printf("(%d,%d)\n",x,y);
            sprintf(name,"%d.bmp",num);
            printf("当前图片为：%s\n",name);
            bmp_display(0,0,&lcd,name);
        }else if(400< x && x < 800){
            num++;
            if (num > 3)
            {
                num = 1;
            }
            printf("(%d,%d)\n",x,y);
            sprintf(name,"%d.bmp",num);
            printf("当前图片为：%s\n",name);
            bmp_display(0,0,&lcd,name);
        }
        
    }
    
    return 0;
}
