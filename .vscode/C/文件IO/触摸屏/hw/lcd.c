#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/mman.h>
#include <string.h>
#include "types.h"
#include <linux/input.h>

#define LCD_SIZE 800*480*4

int lcd_init(LCD *lcd){
    lcd->fd_lcd = open("/dev/fb0",O_RDWR);
    if (lcd->fd_lcd == -1)
    {
        perror("打开lcd显示屏文件失败\n");
        return -1;
    }
    lcd->p_lcd = (int *)mmap(NULL,LCD_SIZE,PROT_READ | PROT_WRITE,MAP_SHARED,lcd->fd_lcd,0);
    if (lcd->p_lcd == NULL)
    {
        perror("内存映射失败\n");
        return -1;
    }
    
    lcd->fd_ts = open("/dev/input/event0",O_RDWR);
    if (lcd->fd_ts == -1)
    {
        perror("打开lcd触摸屏文件失败\n");
        return -1;
    }
    return 0;
}

int get_coordinate(int *x,int *y,int fd){
    struct input_event input_e;
    
    while (1)
    {
        size_t ret_cal = read(fd,&input_e,sizeof(input_e));
        if (input_e.type == EV_ABS)
        {
            if (input_e.code == ABS_X)
            {
                *x = input_e.value * 800 / 1024;
            }else if (input_e.code == ABS_Y)
            {
                *y = input_e.value * 480 / 600;
            }
            
        }
        if (input_e.type == EV_KEY && input_e.code == BTN_TOUCH && input_e.value == 0 )
        {
            printf("(%d,%d)\n",*x,*y);
            break;
        }
        
        
    }
    return 0;
}


void bmp_display(int x_s,int y_s,LCD *lcd,const char *path){
    BITMAPFILEHEADER bmp_head;
    BITMAPINFOHEADER bmp_head_info;
    int fd = open(path,O_RDWR);
    size_t ret_val = read(fd,&bmp_head,sizeof(bmp_head));
    ret_val = read(fd,&bmp_head_info,sizeof(bmp_head_info));
    char bfType[2];
    memcpy(bfType,&bmp_head.bfType,sizeof(bmp_head.bfType));
    printf("图片格式:%c%c\n",bfType[0],bfType[1]);
    printf("图片高度:%d\n图片宽度:%d\n图片色深:%d\n图片大小:%d\n",bmp_head_info.biHeight,bmp_head_info.biWidth,bmp_head_info.biBitCount,bmp_head_info.biSizeImage);
    int num = 0 ;
    if ((bmp_head_info.biWidth*3) % 4 != 0)
    {
        num = 4 - (bmp_head_info.biWidth*3) % 4; 
    }
    char buf_bmp[bmp_head_info.biSizeImage];
    int buf_lcd[bmp_head_info.biHeight][bmp_head_info.biWidth];
    // lseek(fd_bmp,54,SEEK_SET);
    ret_val = read(fd , buf_bmp, bmp_head_info.biSizeImage);
    for (int y = 0; y < bmp_head_info.biHeight; y++)
    {
        for (int x = 0; x < bmp_head_info.biWidth; x++)
        {
            buf_lcd[bmp_head_info.biHeight-1-y][x] = buf_bmp[ (x + y*bmp_head_info.biWidth)*3 + 0 + y*num ] <<0 |
                                                     buf_bmp[ (x + y*bmp_head_info.biWidth)*3 + 1 + y*num ] <<8 |
                                                     buf_bmp[ (x + y*bmp_head_info.biWidth)*3 + 2 + y*num ] <<16 ;
        }
        
    }
    
    for (int y = 0; y < bmp_head_info.biHeight; y++)
    {
        for (int x = 0; x < bmp_head_info.biWidth; x++)
        {
            if ((y + y_s) < 480 && (x + x_s) < 800)
            {
                *(lcd->p_lcd + (y + y_s)*800 + x + x_s) = buf_lcd[y][x];
            }
        }
    }
    close(fd);
}

