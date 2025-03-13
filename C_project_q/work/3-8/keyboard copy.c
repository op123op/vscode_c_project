#include "printf_ui.h"  // printf函数ui特效
#include <stdio.h>

// 键盘值
#define UP      0x00
#define DOWN    0x01
#define LEFT    0x02
#define RIGHT   0x03
#define ENTER   0x04
#define YES     0x05
#define NO      0x06
#define EXIT    0x07
#define UNKNOW  0x08



/**
  * @brief  获取键盘值函数
  * @note   
  * 
        一些解释说明：
        键盘上键：^[[A == 27[A
        键盘下键：^[[B == 27[B
        键盘左键：^[[D == 27[D
        键盘右键：^[[C == 27[C

  * @param  None
  * @retval 返回的按键的值
  */ 
// 获取键盘值函数
int KEYBOAR_GetVal(void)
{
    int key = -1;
    char ch = 0;


    ch = getchar();             // 从标准输入(stdin,键盘)中获取一个字符(堵塞函数，除非你在键盘输入了一个字符)
    if(ch == 27)                // 判断字符是否是^[、\033、27(1)     // 判断是否是上下左右按键
    {
        ch = getchar();         // 判断字符是否为[(2)
        if(ch == '[')
        {
            ch = getchar();     // 判断字符是否为键盘的上下左右
            switch (ch)
            {
                case 'A': key = UP;    break;
                case 'B': key = DOWN;  break;
                case 'D': key = LEFT;  break;
                case 'C': key = RIGHT; break;
                default:  key = UNKNOW; break;
            }
        }
    }
    else if(ch == '\n')         // 判断字符是否是换行符(回车键)
    {
        key = ENTER;            
    }
    else if(ch == 'y' )         // 判断字符是否是'y'
    {
        ch = getchar();         // 让你确认是狗输入的是y值
        if(ch == '\n')
        {
            key = YES; 
        }
    }
    else if(ch == 'n' )         // 判断字符是否是'n'
    {
        ch = getchar();      
        if(ch == '\n')
        {
            key = NO; 
        }
    }

    return key;
}

// printf函数特效ui界面显示
// 显示主界面
void PRINTF_UI_ShowMainUi(char*test_buf, int num, Printf_Ui_Atr* p)
{
    if(test_buf != NULL)
    {
        // 设置界面
        PRINTF_UI_SetMainInf("=", "*", 32, 12, p, BGC_BLUE, FC_WHITE, SE_HIGH_LIGHT);
        // 设置字体
        PRINTF_UI_SetMainText(test_buf				, 4, 5, p, BGC_BLUE, FC_WHITE, SE_CLOSE);
    }
    else
    {
        // 设置界面
        PRINTF_UI_SetMainInf("=", "*", 32, 12, p, BGC_BLUE, FC_WHITE, SE_HIGH_LIGHT);

        // 设置字体
        PRINTF_UI_SetMainText("《 医疗挂号信息管理系统 》"		, 4, 1,  p, BGC_BLUE, FC_WHITE, SE_HIGH_LIGHT); 		
        PRINTF_UI_SetMainText("   (1)、挂号窗口"				, 4, 3, p, BGC_BLUE, FC_WHITE, SE_CLOSE);
        PRINTF_UI_SetMainText("   (2)、删除挂号信息"			, 4, 4, p, BGC_BLUE, FC_WHITE, SE_CLOSE);
        PRINTF_UI_SetMainText("   (3)、查找信息"				, 4, 5, p, BGC_BLUE, FC_WHITE, SE_CLOSE);
        PRINTF_UI_SetMainText("   (4)、修改信息"				, 4, 6, p, BGC_BLUE, FC_WHITE, SE_CLOSE);
        PRINTF_UI_SetMainText("   (5)、其它"					, 4, 7, p, BGC_BLUE, FC_WHITE, SE_CLOSE);
        PRINTF_UI_SetMainText("                     退出(q)"	, 4, 9, p, BGC_BLUE, FC_WHITE, SE_CLOSE);

        // 设置选择项目点
        if(num == 1)
        {
            PRINTF_UI_SetMainText("   (1)、挂号窗口"				, 4, 3, p, BGC_BLUE, FC_WHITE, CONCAT(SE_HIGH_LIGHT,SE_HIGH_LIGHT) );
        }
        else if(num == 2)
        {
            PRINTF_UI_SetMainText("   (2)、删除挂号信息"			, 4, 4, p, BGC_BLUE, FC_WHITE, CONCAT(SE_HIGH_LIGHT,SE_HIGH_LIGHT));
        }
        else if(num == 3)
        {
            PRINTF_UI_SetMainText("   (3)、查找信息"				, 4, 5, p, BGC_BLUE, FC_WHITE, CONCAT(SE_HIGH_LIGHT,SE_HIGH_LIGHT));
        }
        else if(num == 4)
        {
            PRINTF_UI_SetMainText("   (4)、修改信息"				, 4, 6, p, BGC_BLUE, FC_WHITE, CONCAT(SE_HIGH_LIGHT,SE_HIGH_LIGHT));
        }
        else if(num == 5)
        {
            PRINTF_UI_SetMainText("   (5)、其它"					, 4, 7, p, BGC_BLUE, FC_WHITE, CONCAT(SE_HIGH_LIGHT,SE_HIGH_LIGHT));
        }
        else if(num == 6)
        {
            PRINTF_UI_SetMainText("                     退出(q)"	, 4, 9, p, BGC_BLUE, FC_WHITE, CONCAT(SE_HIGH_LIGHT,SE_HIGH_LIGHT));
        }
    }
	// 设置光标位置
	CURSOR_MOVE(0, 12*2);
}

// 显示子界面
void PRINTF_UI_ShowSubUi(char*test_buf, int num, Printf_Ui_Atr* p)
{
    // 设置界面
	PRINTF_UI_SetMainInf("=", "*", 32, 12, p, BGC_BLUE, FC_WHITE, SE_HIGH_LIGHT);
    PRINTF_UI_SetSubInf("=", "*", 20, 6, p, BGC_PURPLE, FC_WHITE, SE_HIGH_LIGHT);

	// 设置字体
	PRINTF_UI_SetSubText(test_buf  , 4,  1, p, BGC_PURPLE, FC_WHITE, SE_HIGH_LIGHT); 		
	PRINTF_UI_SetSubText("是(y)"   , 1,  3, p, BGC_PURPLE, FC_WHITE, SE_CLOSE);
	PRINTF_UI_SetSubText("否(n)"   , 16, 3, p, BGC_PURPLE, FC_WHITE, SE_CLOSE);


    // // 设置选择项目点
    if(num == 1)
    {
        PRINTF_UI_SetSubText("是(y)"   , 1,  3, p, BGC_PURPLE, FC_WHITE, CONCAT(SE_HIGH_LIGHT,SE_FLICKER));
        
    }
    else if(num == 2)
    {
        PRINTF_UI_SetSubText("否(n)"   , 16, 3, p, BGC_PURPLE, FC_WHITE, CONCAT(SE_HIGH_LIGHT,SE_FLICKER));
    }

	// 设置光标位置
	CURSOR_MOVE(0, 12*2);
}



// main函数
int main(int argc, char const *argv[])
{
    // 相关变量
    int k_val     = 0;
    int num       = 0;
    int flag_exit = 0;

    // 初始化主界面
    Printf_Ui_Atr atr;
    PRINTF_UI_ShowMainUi(NULL, 0, &atr);
                                   

    // 操作主界面
    while(1)
    {
        // 主界面选择
        k_val = KEYBOAR_GetVal();       // 堵塞于此，等你输入数据
        if(k_val == UP)
        {
            num--;
            if(num < 1)
                num = 1;
        }
        else if(k_val == DOWN)
        {
            num++;
            if(num > 6)
                num = 6;
        }
        PRINTF_UI_ShowMainUi(NULL, num, &atr);

        // 功能选择进入
        switch (num)
        {
            case 1:
                break;

            case 2:
                break;

            case 3:
                break;

            case 4:
                break;

            case 5:
                break;

            case 6:
                if(k_val == YES)
                {
                    num = 1;
                    while(1)
                    {
                        PRINTF_UI_ShowSubUi("是否确定退出?", num, &atr);
                        k_val = KEYBOAR_GetVal();
                        if(k_val == LEFT)
                        {
                            num--;
                            if(num < 1)
                                num = 1;
                        }
                        else if(k_val == RIGHT)
                        {
                            num++;
                            if(num > 2)
                                num = 2;
                        }

                        switch (num)
                        {
                            case 1:
                                if(k_val == YES)
                                   goto exit_label;          
                                break;

                            case 2:
                                if(k_val == YES)
                                   goto return_main_label;              
                                break;
                        }
                    }
                }
                break;

return_main_label:
    num = 1;
    PRINTF_UI_ShowMainUi(NULL, num, &atr);   

        }
    }

exit_label:
    PRINTF_UI_ShowMainUi("       系统已退出!!", 1, &atr);   

    return 0;
}
