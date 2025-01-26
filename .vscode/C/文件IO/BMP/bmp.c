#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/mman.h>

#define DEVICE_PATH "/dev/fb0"
#define BMP_PATH "./1.bmp"
#define WIDTH 800
#define HEIGHT 480
#define LCD_SIZE WIDTH*HEIGHT*4
#define BMP_SIZE WIDTH*HEIGHT*3
int main(int argc, char const *argv[])
{
    int fd = open(DEVICE_PATH, O_RDWR);
    if (fd == -1)
    {
        perror("文件打开失败!!!\n");
        return -1;
    }
    char *p = mmap(NULL, LCD_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED,
                  fd, 0);
    if (p == MAP_FAILED)
    {
        perror("内存映射失败！！\n");
        return -1;
    }
    
    int fd_bmp1 = open(BMP_PATH,O_RDWR);
    if (fd_bmp1 == -1)
    {
        perror("打开1.bmp失败\n");
        return -1;
    }
    off_t ret_val = lseek(fd_bmp1, 54, SEEK_SET);
    if (ret_val == -1)
    {
        perror("偏移失败\n");
        return -1;
    }
    
    char bmp_buff[BMP_SIZE] = {0};
    ssize_t fd_bmp = read(fd_bmp1, bmp_buff, BMP_SIZE);
    if (fd_bmp == -1)
    {
        perror("读取文件失败！！\n");
        return -1;
    }
    printf("读到%ld字节\n",fd_bmp);
    int bmp_lcd[480][800] = {0};
    for (int y = 0; y < 480; y++)
    {
        for (int x = 0; x < 800; x++)
        {
            bmp_lcd[479-y][x] = bmp_buff[(x+y*800)*3+0] <<0  |
                                bmp_buff[(x+y*800)*3+1] <<8  |
                                bmp_buff[(x+y*800)*3+2] <<16;
        }
    }
    memcpy(p, bmp_lcd, LCD_SIZE);
    close(fd);
    munmap(p,LCD_SIZE);
    return 0;
}
