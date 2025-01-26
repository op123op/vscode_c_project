#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <string.h>

#define LCD_PATH "/dev/fb0"
#define WITH 800
#define HEIGHT 480
#define LCD_SIZE WITH*HEIGHT*4
#define BMP_PATH "2.bmp"
typedef short int WORD;
typedef int DWORD;
typedef long LONG;

typedef struct lcd{
    int fd_lcd;
    int *p_lcd;
}P_LCD;
typedef struct tagBITMAPFILEHEADER
{
    WORD bfType;//位图文件的类型，必须为BM(1-2字节）
    DWORD bfSize;//位图文件的大小，以字节为单位（3-6字节，低位在前）
    WORD bfReserved1;//位图文件保留字，必须为0(7-8字节）
    WORD bfReserved2;//位图文件保留字，必须为0(9-10字节）
    DWORD bfOffBits;//位图数据的起始位置，以相对于位图（11-14字节，低位在前）
    //文件头的偏移量表示，以字节为单位
}__attribute__((packed)) BITMAPFILEHEADER;

typedef struct tagBITMAPINFOHEADER{
    DWORD biSize;//本结构所占用字节数（15-18字节）
    DWORD biWidth;//位图的宽度，以像素为单位（19-22字节）
    DWORD biHeight;//位图的高度，以像素为单位（23-26字节）
    WORD biPlanes;//目标设备的级别，必须为1(27-28字节）
    WORD biBitCount;//每个像素所需的位数，必须是1（双色），（29-30字节）
    //4(16色），8(256色）16(高彩色)或24（真彩色）之一
    DWORD biCompression;//位图压缩类型，必须是0（不压缩），（31-34字节）
    //1(BI_RLE8压缩类型）或2(BI_RLE4压缩类型）之一
    DWORD biSizeImage;//位图的大小(其中包含了为了补齐行数是4的倍数而添加的空字节)，以字节为单位（35-38字节）
    DWORD biXPelsPerMeter;//位图水平分辨率，每米像素数（39-42字节）
    DWORD biYPelsPerMeter;//位图垂直分辨率，每米像素数（43-46字节)
    DWORD biClrUsed;//位图实际使用的颜色表中的颜色数（47-50字节）
    DWORD biClrImportant;//位图显示过程中重要的颜色数（51-54字节）
}__attribute__((packed)) BITMAPINFOHEADER;
BITMAPFILEHEADER bmp_head;
BITMAPINFOHEADER bmp_info_head;
int lcd_init(P_LCD *lcd){
    lcd->fd_lcd = open(LCD_PATH,O_RDWR);
    if (lcd->fd_lcd == -1)
    {
        perror("打开文件失败\n");
        return -1;
    }
    lcd->p_lcd = mmap(NULL,LCD_SIZE,PROT_READ | PROT_WRITE,MAP_SHARED,lcd->fd_lcd,0);
    if (lcd->p_lcd == NULL)
    {
        perror("映射失败\n");
        return -1;
    }
    return 0; 
    
}
int bmp_init(const char *path){
    int fd_bmp = open(path,O_RDONLY);
    ssize_t rev_val;
    rev_val = read(fd_bmp,&bmp_head,sizeof(bmp_head));
    rev_val = read(fd_bmp,&bmp_info_head,sizeof(bmp_info_head));
    char bfType[2];
    memcpy(bfType,&bmp_head.bfType,sizeof(bmp_head.bfType));
    // char bfType1[2];
    // memcpy(bfType1,&bmp_head.bfReserved1,sizeof(bmp_head.bfReserved1));
    int with = bmp_info_head.biWidth;
    int height = bmp_info_head.biHeight;
    short int biBitCount = bmp_info_head.biBitCount;
    printf("图片类型：%s\n图片宽度：%d\n图片高度：%d\n图片位数：%d\n图片大小：%d\n",bfType,with,height,biBitCount,bmp_info_head.biSizeImage);
    return fd_bmp;
}

void bmp_lcd(int x_s,int y_s,P_LCD *lcd,int fd_bmp){
    int buf_lcd[bmp_info_head.biHeight][bmp_info_head.biWidth];
    char buf_bmp[bmp_info_head.biSizeImage]; 
    int num = 0 ;
    if ((bmp_info_head.biWidth*3) % 4 != 0)
    {
        num = 4 - (bmp_info_head.biWidth*3) % 4; 
    }
    
    // lseek(fd_bmp,54,SEEK_SET);
    size_t rea_val = read(fd_bmp , buf_bmp, bmp_info_head.biSizeImage);
    for (int y = 0; y < bmp_info_head.biHeight; y++)
    {
        for (int x = 0; x < bmp_info_head.biWidth; x++)
        {
            buf_lcd[bmp_info_head.biHeight-1-y][x] = buf_bmp[ (x + y*bmp_info_head.biWidth)*3 + 0 + y*num ] <<0 |
                                                     buf_bmp[ (x + y*bmp_info_head.biWidth)*3 + 1 + y*num ] <<8 |
                                                     buf_bmp[ (x + y*bmp_info_head.biWidth)*3 + 2 + y*num ] <<16 ;
        }
        
    }
    
    for (int y = 0; y < bmp_info_head.biHeight; y++)
    {
        for (int x = 0; x < bmp_info_head.biWidth; x++)
        {
            if ((y + y_s) < 480 && (x + x_s) < 800)
            {
                *(lcd->p_lcd + (y + y_s)*800 + x + x_s) = buf_lcd[y][x];
            }
        }
    }
    
}

void close_file(int fd_bmp,P_LCD *lcd){
    close(fd_bmp);
    close(lcd->fd_lcd);
    munmap(lcd->p_lcd,LCD_SIZE);
}

int main(int argc, char const *argv[])
{
    P_LCD lcd = {
        .fd_lcd = 0,
        .p_lcd = NULL,
    };
    //初始化显示屏信息
    lcd_init(&lcd);
    //初始化并显示bmp文件信息
    int fd_bmp = bmp_init(BMP_PATH);
    //显示lcd屏
    bmp_lcd(200,200,&lcd,fd_bmp);
    //关闭文件函数
    close_file(fd_bmp,&lcd);
    return 0;
}
