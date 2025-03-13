#include <stdio.h>
#include "printf_ui.h"

extern void load();                                     //加载动画
extern int meun(Printf_Ui_Atr  *printf_atr);            //首页
extern void insert_info(Printf_Ui_Atr  *printf_atr);    //添加航班信息
extern void delete_info(Printf_Ui_Atr  *printf_atr);    //删除航班信息
extern void select_info(Printf_Ui_Atr  *printf_atr);    //查询航班信息
extern void update_info(Printf_Ui_Atr  *printf_atr);    //修改航班信息
extern void bsm(Printf_Ui_Atr  *printf_atr);            //后台管理
extern void printProgressBar(int percent);              //进度条

int main(int argc, char const *argv[])
{
    Printf_Ui_Atr  printf_atr;
    load();  
    while(1){
        // 设置界面
	    PRINTF_UI_SetMainInf("=", "*", 32, 13, &printf_atr, BGC_BLUE, FC_WHITE, SE_HIGH_LIGHT);
        int choice = meun(&printf_atr);

        switch (choice)
        {
            case 1:
                insert_info(&printf_atr);
                break;
            case 2:
                delete_info(&printf_atr);
                break;
            case 3:
                select_info(&printf_atr);
                break;
            case 4:
                update_info(&printf_atr);
                break;
            case 5:
                bsm(&printf_atr);
                break;
            case 6:
                return 0;
                break;
            default:
                break;
        }
    }
	
	// 设置光标位置
	CURSOR_MOVE(0, 12*2);
    return 0;
}

//菜单页面
int meun(Printf_Ui_Atr  *printf_atr){
    int choice = 0;
    
    // 设置字体
	PRINTF_UI_SetMainText(" 《 航班信息管理系统 》"       , 4, 1, printf_atr, BGC_BLUE, FC_WHITE, SE_HIGH_LIGHT); 		
	PRINTF_UI_SetMainText("   (1)、添加航班信息"		  , 4, 3, printf_atr, BGC_BLUE, FC_WHITE, SE_CLOSE);
	PRINTF_UI_SetMainText("   (2)、删除航班信息"		  , 4, 4, printf_atr, BGC_BLUE, FC_WHITE, SE_CLOSE);
	PRINTF_UI_SetMainText("   (3)、查询航班信息"		  , 4, 5, printf_atr, BGC_BLUE, FC_WHITE, SE_CLOSE);
	PRINTF_UI_SetMainText("   (4)、修改航班信息"		  , 4, 6, printf_atr, BGC_BLUE, FC_WHITE, SE_CLOSE);
	PRINTF_UI_SetMainText("   (5)、后台管理"			  , 4, 7, printf_atr, BGC_BLUE, FC_WHITE, SE_CLOSE);
	PRINTF_UI_SetMainText("                     退出(6)" , 4, 9, printf_atr, BGC_BLUE, FC_WHITE, SE_CLOSE);
    PRINTF_UI_SetMainText("   请选择(1~6)："			  , 4, 10, printf_atr, BGC_BLUE, FC_WHITE, SE_CLOSE);
    do
    {
        scanf("%d",&choice);
        while (getchar() != '\n');
    } while (choice > 6 || choice < 1);
    return choice;
}

//添加航班信息
void insert_info(Printf_Ui_Atr  *printf_atr){
    PRINTF_UI_SetSubInf( "=", "*",  32, 13, printf_atr, BGC_BLUE, FC_WHITE, SE_HIGH_LIGHT);
    PRINTF_UI_SetSubText("输入起始地：__________", 3, 1, printf_atr, BGC_BLUE, FC_WHITE,SE_CLOSE);
    PRINTF_UI_SetSubText("输入到达地：__________", 3, 3, printf_atr, BGC_BLUE, FC_WHITE,SE_CLOSE);
    PRINTF_UI_SetSubText("输入起飞时间：__________", 3, 5, printf_atr, BGC_BLUE, FC_WHITE,SE_CLOSE);
    PRINTF_UI_SetSubText("输入到达时间：__________", 3, 7, printf_atr, BGC_BLUE, FC_WHITE,SE_CLOSE);
    PRINTF_UI_SetSubText("输入飞机航班号：__________", 3, 9, printf_atr, BGC_BLUE, FC_WHITE,SE_CLOSE);
    char a = '1';
    scanf("%s",&a);
}

//删除航班信息
void delete_info(Printf_Ui_Atr  *printf_atr){
    PRINTF_UI_SetSubInf( "=", "*",  32, 13, printf_atr, BGC_BLUE, FC_WHITE, SE_HIGH_LIGHT);
    PRINTF_UI_SetSubText("输入要删除航班的航班号：", 3, 3, printf_atr, BGC_BLUE, FC_WHITE,SE_CLOSE);
    PRINTF_UI_SetSubText("_____________________________", 3, 5, printf_atr, BGC_BLUE, FC_WHITE,SE_CLOSE);
    char a = '1';
    scanf("%s",&a);
}

//查询航班信息
void select_info(Printf_Ui_Atr  *printf_atr){
    PRINTF_UI_SetSubInf( "=", "*",  32, 13, printf_atr, BGC_BLUE, FC_WHITE, SE_HIGH_LIGHT);
    PRINTF_UI_SetSubText("输入出发地：__________", 3, 2, printf_atr, BGC_BLUE, FC_WHITE,SE_CLOSE);
    PRINTF_UI_SetSubText("输入到达地：__________", 3, 4, printf_atr, BGC_BLUE, FC_WHITE,SE_CLOSE);
    PRINTF_UI_SetSubText("输入日期：__________", 3, 6, printf_atr, BGC_BLUE, FC_WHITE,SE_CLOSE);
    PRINTF_UI_SetSubText("显示查询航班信息：__________", 3, 8, printf_atr, BGC_BLUE, FC_WHITE,SE_CLOSE);
    char a = '1';
    scanf("%s",&a);
}

//修改航班信息
void update_info(Printf_Ui_Atr  *printf_atr){
    PRINTF_UI_SetSubInf( "=", "*",  32, 13, printf_atr, BGC_BLUE, FC_WHITE, SE_HIGH_LIGHT);
    PRINTF_UI_SetSubText("输入要修改航班的航班号：", 3, 3, printf_atr, BGC_BLUE, FC_WHITE,SE_CLOSE);
    PRINTF_UI_SetSubText("____________________", 3, 5, printf_atr, BGC_BLUE, FC_WHITE,SE_CLOSE);
    char a = '1';
    scanf("%s",&a);
}

//后台管理
void bsm(Printf_Ui_Atr  *printf_atr){

}

//加载动画
void load(){
    for (int i = 0; i < 100; i++)
    {
        system("clear");
        printf("\r");
        printf("\033[44;37m =================================================================\033[0m\n");
        printf("\033[44;37m *                                                              * \033[0m\n");
        printf("\033[44;37m *                   管理系统进入中                             * \033[0m\n");
        printf("\033[44;37m *                                                              * \033[0m\n");
        printf("\033[44;37m *   ");
        printProgressBar(i);
        printf("*\n");
        printf("\033[44;37m *                                                              * \033[0m\n");
        printf("\033[44;37m *                                                              * \033[0m\n");
        printf("\033[44;37m =================================================================\033[0m\n");
        fflush(stdout);
        usleep(10000); // 延时500000微妙 == 0.5秒
    }
}

void printProgressBar(int percent) {
    const int barWidth = 50;
    printf("[");
    for (int i = 0; i < barWidth; i++) {
        if (i < (barWidth * percent) / 100) {
            printf("#");
        } else {
            printf(" ");
        }
    }
    printf("] %d%%   * \r ", percent);
    fflush(stdout);  // 刷新输出缓冲区
}
