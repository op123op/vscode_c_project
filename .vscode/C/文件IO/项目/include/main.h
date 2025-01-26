#ifndef __MAIN_HI_
#define __MAIN_HI_

#include <stdio.h>
#include "./ly_dw.h"
#include "./mda_ply.h"
#include "./res_update.h"

typedef enum menu {
    Resource_update,
    media_player,
    lucky_draw
}Menu;
static int get_usr_input(char * msg )
{
    printf("%s" , msg);

    int num = 0 ;
    int ret_val = 0 ;

    while(ret_val != 1 )
    {
        ret_val = scanf("%d" , &num) ;
        if (ret_val != 1 )
        {
            while(getchar() != '\n');
            continue ;
        }
    }

    return num ;

}
static inline Menu menu1(){
    printf("********************\n");
    printf("*****1.资源更新*****\n");
    printf("*****2.媒体播放*****\n");
    printf("*****3.幸运抽奖*****\n");
    printf("********************\n");
    int num1 = get_usr_input("请输入你的选择:");
    if (num1>3 || num1<1)
    {
        printf("请选择(1-3)\n");
        return -1;
    }
    
    Menu menu2;
    switch (num1)
    {
        case 1:
            menu2 = Resource_update;
            break;
        case 2:
            menu2 = media_player;
            break;
        case 3:
            menu2 = lucky_draw;
        break;
        default:
            break;
    }
    return menu2;
}

#endif