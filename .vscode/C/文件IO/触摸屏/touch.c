#include <linux/input.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

typedef struct touch_info{
    int x;
    int y;
    unsigned int type;
    unsigned int code;
}Touch_i;


int display_coordinate(Touch_i *touch_i){
    int fd = open("/dev/input/event0",O_RDONLY);
    if (fd == -1)
    {
        perror("打开文件失败\n");
        return -1;
    }
    struct input_event input_e;
    while (1)
    {
        size_t ret_val = read(fd,&input_e,sizeof(input_e));
        if (ret_val == -1)
        {
            perror("读取失败\n");
            return -1;
        }
        if (input_e.type == EV_ABS )
        {
            if (input_e.code == ABS_X)
            {
                touch_i->x = input_e.value * 800 / 1024;
            }else if (input_e.code == ABS_Y)
            {
                touch_i->y = input_e.value * 480 /600;
            }
        }
        
        if (input_e.type == EV_KEY && input_e.code == BTN_TOUCH && input_e.value == 0)
        {
            printf("(%d,%d)\n",touch_i->x,touch_i->y);
        }
    }
    
    
    return 0;
}

int display(){
    int fd = open("/dev/input/event0",O_RDONLY);
    if (fd == -1)
    {
        perror("打开文件失败\n");
        return -1;
    }
    struct input_event input_e;
    while (1)
    {
        size_t ret_val = read(fd,&input_e,sizeof(input_e));
        if (ret_val == -1)
        {
            perror("读取失败\n");
            return -1;
        }
        printf("时间：%d-%d,type：%d,code：%d,value：%d\n",input_e.time.tv_sec,input_e.time.tv_usec,input_e.type,input_e.code,input_e.value);
    }
    
    
    return 0;
}
int main(int argc, char const *argv[])
{
    Touch_i touch_i;
    //显示触摸屏坐标
    // display_coordinate(&touch_i);
    display();
    return 0;
}
