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
    int x,y;
    //获取用点击坐标
    while (1)
    {
        get_coordinate(&x,&y,lcd.fd_ts);
        if (x < 400 && y < 200)
        {
            printf("(%d,%d)\n",x,y);
            bmp_display(0,0,&lcd,"1.bmp");
        }else if(400< x && x < 800 && y < 200)
        {
            printf("(%d,%d)\n",x,y);
            bmp_display(0,0,&lcd,"2.bmp");
        }else if (x < 400 && 200 < y && y < 480)
        {
            printf("(%d,%d)\n",x,y);
            bmp_display(0,0,&lcd,"3.bmp");
        }
        
    }
    
    return 0;
}
