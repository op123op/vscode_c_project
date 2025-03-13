/**
  ******************************************************************************
  * @file    printf_ui.h
  * @author  FZetc飞贼(方惠清)
  * @version V0.0.1
  * @date    2024.7
  * @brief   1、printf函数的宏定义(特效、背景色、字体色)
  *          2、printf函数的UI界面(主界面、功能界面、弹窗界面)
  *          
  ******************************************************************************
  * @attention
  *
  *	 推广：
  *  	合作交流建议：FZetcSnitch@163.com
  *		网站建设推广：www.FZetc.com
  *  	微信公众号：  FZetc飞贼 
  *
  ******************************************************************************
  */

#ifndef __PRINTF_UI_H	// 定义以防止递归包含
#define __PRINTF_UI_H

// (1)、头文件
#include <stdio.h>  
#include <stdlib.h>  
#include <unistd.h>  
#include <sys/ioctl.h>  
#include <termios.h> 
#include <string.h>

// (2)、宏定义(函数、变量、常量)
#define BGC_BLACK 			    "\033[40m"										                // 背景色(background color)
#define BGC_DARK_RED   	    "\033[41m"										                // 深红		    
#define BGC_GREEN 			    "\033[42m"									                  // 绿色
#define BGC_YELLOW 			    "\033[43m"									                  // 黄色
#define BGC_BLUE 			      "\033[44m"									                  // 蓝色
#define BGC_PURPLE 			    "\033[45m"									                  // 紫色
#define BGC_DARK_GREEN 		  "\033[46m"									                  // 深绿
#define BGC_WHITE 			    "\033[47m"									                  // 白色
									                                        
#define FC_BLACK 			      "\033[30m"										                // 字体色(font color)
#define FC_RED   			      "\033[31m"									                  // 红色	
#define FC_GREEN 			      "\033[32m"									                  // 绿色
#define FC_YELLOW 			    "\033[33m"									                  // 黄色
#define FC_BLUE 			      "\033[34m"									                  // 蓝色
#define FC_PURPLE			      "\033[35m"									                  // 紫色
#define FC_DARK_GREEN 		  " \033[36m"									                  // 深绿
#define FC_WHITE 			      "\033[37m"									                  // 白色
									                                        
#define SE_CLOSE 			      "\033[0m"										                  // 其它特效(Special effects)
#define SE_HIGH_LIGHT   	  "\033[1m"										                  // 高亮(加粗)
#define SE_UNDER_LINE 		  "\033[4m"										                  // 下划线
#define SE_FLICKER      	  "\033[5m"										                  // 闪烁
#define SE_REVERSE_DISPLAY 	"\033[7m"										                  // 反显
#define SE_BLACK_OUT		    "\033[8m"										                  // 消隐

#define CLEAR_SCREEN()   	{printf("\033[2J"); fflush(stdout);}			      // 清屏
#define CURSOR_MOVE(X, Y)	{printf("\033[%d;%dH", Y, X); fflush(stdout);}	// 设置光标位置  
#define SHOW_CURSOR()   	{printf("\033[?25h"); fflush(stdout);}			    // 显示光标
#define HIDE_CURSOR()		  {printf("\033[?25l"); fflush(stdout);}			    // 隐藏光标
#define CLEAR_CURSOR()   	{printf("\033[K"); fflush(stdout);}				      // 清除从光标到行尾的内容  
#define SAVE_CURSOR()   	{printf("\033[s"); fflush(stdout);}				      // 保存光标位置  
#define RSETORE_CURSOR()  {printf("\033[u"); fflush(stdout);}				      // 恢复光标位置 

#define CONCAT(x, y) x y													                         // 连接两个字符串

// (3)、数据类型(结构体、联合体、枚举)

// printf函数ui属性
typedef struct 
{
	int main_inf_w;				// 主界面长宽
	int main_inf_h;             
	int main_origin_x; 	  // 主界面初始x和y轴位置
	int main_origin_y;          
	int main_text_x;	    // 主界面显示字的x和y轴位置
	int main_text_y;            
                                
	int sub_inf_w;		    // 子界面长宽		
	int sub_inf_h;              
	int sub_origin_x;     // 子界面初始x和y轴位置
	int sub_origin_y;           
	int sub_text_x;       // 子界面显示字的x和y轴位置
	int sub_text_y;
	
}Printf_Ui_Atr;	



// (4)、全局变量声明
extern int patient_count;


// (5)、函数声明
extern void PRINTF_UI_SetMainInf(unsigned char *w_ch, unsigned char *h_ch , int inf_w, int inf_h, Printf_Ui_Atr *p, const unsigned char *bgc_buf, const unsigned char *fc_buf, const unsigned char *se_buf);
extern void PRINTF_UI_SetMainText(const unsigned char *text, int text_x, int text_y, Printf_Ui_Atr *p, const unsigned char *bgc_buf, const unsigned char *fc_buf, const unsigned char *se_buf);
extern void PRINTF_UI_SetSubInf( unsigned char *w_ch, unsigned char *h_ch , int inf_w, int inf_h, Printf_Ui_Atr *p, const unsigned char *bgc_buf, const unsigned char *fc_buf, const unsigned char *se_buf);
extern void PRINTF_UI_SetSubText(const unsigned char *text, int text_x, int text_y, Printf_Ui_Atr *p, const unsigned char *bgc_buf, const unsigned char *fc_buf, const unsigned char *se_buf);

// (6)、全局变量定义、静态函数定义



#endif /* __PRINTF_UI_H */





