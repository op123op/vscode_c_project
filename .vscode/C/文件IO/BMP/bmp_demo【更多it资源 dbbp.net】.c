#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define     LCD_PATH    "/dev/fb0"
#define     LCD_WIDTH    800
#define     LCD_HEIGHT   480
#define     LCD_SIZE     LCD_WIDTH*LCD_HEIGHT*4

typedef     short int    WORD   ;     
typedef     int          DWORD   ; 
typedef     long         LONG   ;     



typedef struct bmp_info
{
    int fd_lcd ;
    int * p_lcd ;
}Bmp_Info;

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
    LONG biWidth;//位图的宽度，以像素为单位（19-22字节）
    LONG biHeight;//位图的高度，以像素为单位（23-26字节）
    WORD biPlanes;//目标设备的级别，必须为1(27-28字节）
    WORD biBitCount;//每个像素所需的位数，必须是1（双色），（29-30字节）
    //4(16色），8(256色）16(高彩色)或24（真彩色）之一
    DWORD biCompression;//位图压缩类型，必须是0（不压缩），（31-34字节）
    //1(BI_RLE8压缩类型）或2(BI_RLE4压缩类型）之一
    DWORD biSizeImage;//位图的大小(其中包含了为了补齐行数是4的倍数而添加的空字节)，以字节为单位（35-38字节）
    LONG biXPelsPerMeter;//位图水平分辨率，每米像素数（39-42字节）
    LONG biYPelsPerMeter;//位图垂直分辨率，每米像素数（43-46字节)
    DWORD biClrUsed;//位图实际使用的颜色表中的颜色数（47-50字节）
    DWORD biClrImportant;//位图显示过程中重要的颜色数（51-54字节）
}__attribute__((packed)) BITMAPINFOHEADER;

int Lcd_Init(Bmp_Info * info)
{
    // 打开设备文件
    info->fd_lcd = open(LCD_PATH , O_RDWR ); 
    if (-1 == info->fd_lcd)
    {
        perror("显示器打开失败");
        return -1 ;
    }
    

    // 内存映射
    info->p_lcd = mmap(NULL , LCD_SIZE , PROT_READ | PROT_WRITE , 
            MAP_SHARED, info->fd_lcd , 0 );
    if (MAP_FAILED == info->p_lcd)
    {
        return -1 ;
    }
    
    return 0 ;
}

int Bmp_Display( int x_s , int y_s  , const char * pathName , Bmp_Info info )
{
    // 打开
    int fd_bmp = open(pathName , O_RDONLY ); 
    if (-1 == fd_bmp)
    {
        // perror("图片文件打开失败");
        fprintf( stderr ,"图片文件:%s 打开失败\n" ,pathName );
        return -1 ;
    }

    // 读取图片的信息
    BITMAPFILEHEADER file_head ; // 定义文件结构体
    int ret_val = read(fd_bmp , &file_head , sizeof(file_head));
    if (ret_val == -1 )
    {
        printf("读取文件头失败！！\n");
        return -1;
    }
    

    BITMAPINFOHEADER info_head ; // 定义信息头结构体
    ret_val = read(fd_bmp , &info_head , sizeof(info_head));
    if (ret_val == -1 )
    {
        printf("读取信息头失败！！\n");
        return -1;
    }

    char type[2];
    memcpy(type ,&file_head.bfType , 2 );
    printf("图像类型：%c%c\n" , type[0],type[1] );

    printf("图像宽度：%d\n" , info_head.biWidth );
    printf("图像高度：%d\n" , info_head.biHeight );
    printf("图像色深：%d\n" , info_head.biBitCount );
    printf("sizre:%ld\n" , info_head.biSizeImage);

    int Width = info_head.biWidth;
    int Height = info_head.biHeight ;
    int size_bmp = Width * Height * 3 ;

    // 计算补充字节
    int num = 0 ;
    if ( (Width*3)%4 != 0 )
    {
        num = 4 - (Width*3)%4 ;
    }else{
        num = 0 ;
    }
    

    // 读取颜色像素
    char buf_bmp[ info_head.biSizeImage ] ;
    ret_val = read(fd_bmp , buf_bmp  , info_head.biSizeImage );
    if (ret_val == -1 )
    {
        printf("读取颜色信息失败！！\n");
        return -1;
    }

    // 转换
    int lcd_buf [Height] [Width] ;

    for (int y = 0; y < Height ; y++)
    {
        for (int x = 0; x < Width ; x++)
        {
            lcd_buf [Height-y-1] [x] = buf_bmp[ (y*Width+x)*3 + 0+y*num ] << 0 |
                                        buf_bmp[ (y*Width+x)*3 + 1+y*num ] << 8 |
                                        buf_bmp[ (y*Width+x)*3 + 2+y*num ] << 16 ;
        }
    }
    // for(int y=0;y<Height;y++)
    // {
    //    memcpy(info.p_lcd+y*800 ,lcd_buf+y ,Width*4  ) ;
    // } 
    
    // memcpy(info.p_lcd ,lcd_buf ,Width*Height*4  );
    for (int y = 0; y < Height ; y++)
    {
        for (int x = 0; x < Width ; x++)
        {
            if ((y+y_s) <= 479 && (x+x_s) <= 799) // 判断显示区域是否在可见范围内
            {
                *(info.p_lcd+((y+y_s)*800)+(x+x_s)) = lcd_buf[y][x];
            }
            
        }
    }
    

    close(fd_bmp );

    return 0 ;
}

void Close(Bmp_Info info)
{
    close(info.fd_lcd);
    munmap(info.p_lcd , LCD_SIZE );

    return ;
}

int main(int argc, char const *argv[])
{
    // 显示器初始化
    Bmp_Info info ; 
    if(Lcd_Init(&info))
    {
        printf("初始化失败！！\n");
    }


    // 显示图像  图像显示的起始位置
    Bmp_Display( 500 , 100 , "2.bmp" , info );


    // 关闭文件
    Close(info);
    
    return 0;
}
