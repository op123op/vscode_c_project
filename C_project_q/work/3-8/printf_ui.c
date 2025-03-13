#include "printf_ui.h"

/**
  * @brief  设置printf的ui界面
  * @note   None	
  * @param  col_ch： 界面装饰字符1(横)    行(横):row   列(竖):column 
            row_ch： 界面装饰字符2(竖)  
            inf_col：界面的宽(非像素点，指的是ubuntu终端显示横轴)
            inf_row：界面的高(非像素点，指的是ubuntu终端显示纵轴)
            bgc_buf：背景颜色
            fc_buf： 字体颜色
            se_buf： 显示特效
  * @retval None
  */ 
void PRINTF_UI_SetMainInf(unsigned char *w_ch, unsigned char *h_ch , int inf_w, int inf_h, Printf_Ui_Atr *p, const unsigned char *bgc_buf, const unsigned char *fc_buf, const unsigned char *se_buf)
{
	// 清除屏幕内容
    CLEAR_SCREEN();

	// 获取当前终端的长宽
	struct winsize w;
    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &w) == -1) 
	{  
        perror("ioctl\n");  
        return ;  
    }
	else
	{
		CURSOR_MOVE(0, 0);
		printf("FZetc飞贼(方惠清)  Terminal_Width: %d, Terminal_Height: %d\n", w.ws_col, w.ws_row);  
	}
	fflush(stdout);
	
	// 界面框架设计
	p->main_origin_x  = (w.ws_col-inf_w)/2 - 1;		// 获取界面在终端的中间位置(加1减1，只是为了调节位置，无其它意思)	
	p->main_origin_y  = (w.ws_row-inf_h)/2 + 1; 
	
	p->main_inf_w 	  = inf_w;						// 将主界面长宽赋值给提示界面的全局变量
	p->main_inf_h     = inf_h;
	
	int x     = 0;
	
	int y     = 0;
	int flag  = -1;
	
	if(strcmp(se_buf, SE_CLOSE)!=0)
		flag = 1;
	else
		flag = 0;
	
	// 画空格和w_ch内容
	CURSOR_MOVE(p->main_origin_x , p->main_origin_y );
	if(flag == 1)
		printf("%s%s%s %s", bgc_buf, fc_buf, se_buf,  SE_CLOSE);
	else
		printf("%s%s %s", bgc_buf, fc_buf, SE_CLOSE);

	for(x=0; x<inf_w+3; x++)
	{	
		if(flag == 1)
			printf("%s%s%s%s%s", bgc_buf, fc_buf, se_buf, w_ch, SE_CLOSE);
		else
			printf("%s%s%s%s", bgc_buf, fc_buf, w_ch, SE_CLOSE);
	}
	
	if(flag == 1)
		printf("%s%s%s %s", bgc_buf, fc_buf, se_buf,  SE_CLOSE);
	else
		printf("%s%s %s", bgc_buf, fc_buf, SE_CLOSE);
	
	// 画空格和h_ch内容
	for(y=0; y<inf_h-2; y++)
	{
		CURSOR_MOVE(p->main_origin_x, p->main_origin_y + y + 1);
		if(flag == 1)
			printf("%s%s%s %s%s", bgc_buf, fc_buf, se_buf, h_ch, SE_CLOSE);
		else
			printf("%s%s %s%s", bgc_buf, fc_buf, h_ch, SE_CLOSE);
		
		for(x=0; x<inf_w; x++)
			printf("%s%s %s", bgc_buf, fc_buf,  SE_CLOSE);
		
		if(flag == 1)
			printf("%s%s%s %s %s", bgc_buf, fc_buf, se_buf,  h_ch, SE_CLOSE);
		else
			printf("%s%s %s %s", bgc_buf, fc_buf,  h_ch, SE_CLOSE);
	}
	
	// 画空格和w_ch内容
	CURSOR_MOVE(p->main_origin_x, p->main_origin_y + y + 1);
	if(flag == 1)
		printf("%s%s%s %s", bgc_buf, fc_buf, se_buf,  SE_CLOSE);
	else
		printf("%s%s %s", bgc_buf, fc_buf, SE_CLOSE);
	
	for(x=0; x<inf_w+3; x++)
	{
		if(flag == 1)
			printf("%s%s%s%s%s", bgc_buf, fc_buf, se_buf, w_ch, SE_CLOSE);
		else
			printf("%s%s%s%s", bgc_buf, fc_buf, w_ch, SE_CLOSE);
	}
	
	if(flag == 1)
		printf("%s%s%s %s", bgc_buf, fc_buf, se_buf,  SE_CLOSE);
	else
		printf("%s%s %s", bgc_buf, fc_buf, SE_CLOSE);
	
	// 打印此界面的长宽
	CURSOR_MOVE(p->main_origin_x, p->main_origin_y + y + 2);
	printf("main_inf_w: %d, main_inf_h: %d", inf_w, inf_h);
	CURSOR_MOVE(0, p->main_origin_y + y + 5);
	


	fflush(stdout);	
}

/**
  * @brief  设置要显示在printfui界面的文本内容
  * @note   None	
  * @param  text：    要显示在printfui界面的文本内容 
            screen_x：printfui界面的x轴
            screen_y：printfui界面的y轴
            bgc_buf： 背景颜色
            fc_buf：  字体颜色
            se_buf：  显示特效
  * @retval None
  */ 
void PRINTF_UI_SetMainText(const unsigned char *text, int text_x, int text_y, Printf_Ui_Atr *p, const unsigned char *bgc_buf, const unsigned char *fc_buf, const unsigned char *se_buf)
{
	fflush(stdout);
	
	// 计算出显示字在主界面的初始位置
	int minf_text_x = text_x + p->main_origin_x + 2;		
	int minf_text_y = text_y + p->main_origin_y + 1;
	
    // 移动光标位置
	CURSOR_MOVE(minf_text_x, minf_text_y);	
	
	// printf函数特效打印
	if(strcmp(se_buf, SE_CLOSE)!=0)
		printf("%s%s%s%s%s", bgc_buf, fc_buf, se_buf, text, SE_CLOSE);
	else
		printf("%s%s%s%s", bgc_buf, fc_buf, text, SE_CLOSE);
	
	fflush(stdout);
}

/**
  * @brief  设置要显示在printfui界面的文本内容
  * @note   None	
  * @param  text：    要显示在printfui界面的文本内容 
            screen_x：printfui界面的x轴
            screen_y：printfui界面的y轴
            bgc_buf： 背景颜色
            fc_buf：  字体颜色
            se_buf：  显示特效
  * @retval None
  */ 
void PRINTF_UI_SetSubInf( unsigned char *w_ch, unsigned char *h_ch , int inf_w, int inf_h, Printf_Ui_Atr *p, const unsigned char *bgc_buf, const unsigned char *fc_buf, const unsigned char *se_buf)
{
	fflush(stdout);

	// 算出子界面的初始x轴和y轴位置(子界面位于主界面中间)
	p->sub_origin_x   = (p->main_inf_w-inf_w)/2 + p->main_origin_x;		// 加1减1，只是为了调节位置，无其它意思
	p->sub_origin_y   = (p->main_inf_h-inf_h)/2 + p->main_origin_y;

	int x     = 0;
	int y     = 0;
	int flag  = -1;
	
	// 判断是否要动用特效
	if(strcmp(se_buf, SE_CLOSE)!=0)
		flag = 1;
	else
		flag = 0;
	
	// 画空格和col_ch内容
	CURSOR_MOVE(p->sub_origin_x, p->sub_origin_y);
	if(flag == 1)
		printf("%s%s%s %s", bgc_buf, fc_buf, se_buf,  SE_CLOSE);
	else
		printf("%s%s %s", bgc_buf, fc_buf, SE_CLOSE);
	
	for(x=0; x<inf_w+3; x++)
	{	
		if(flag == 1)
			printf("%s%s%s%s%s", bgc_buf, fc_buf, se_buf, w_ch, SE_CLOSE);
		else
			printf("%s%s%s%s", bgc_buf, fc_buf, w_ch, SE_CLOSE);
	}
	
	if(flag == 1)
		printf("%s%s%s %s", bgc_buf, fc_buf, se_buf,  SE_CLOSE);
	else
		printf("%s%s %s", bgc_buf, fc_buf, SE_CLOSE);
	
	// 画空格和row_ch内容
	for(y=0; y<inf_h-2; y++)
	{
		CURSOR_MOVE(p->sub_origin_x, p->sub_origin_y + y + 1);
		if(flag == 1)
			printf("%s%s%s %s%s", bgc_buf, fc_buf, se_buf, h_ch, SE_CLOSE);
		else
			printf("%s%s %s%s", bgc_buf, fc_buf, h_ch, SE_CLOSE);
		
		for(x=0; x<inf_w; x++)
			printf("%s%s %s", bgc_buf, fc_buf,  SE_CLOSE);
		
		if(flag == 1)
			printf("%s%s%s %s %s", bgc_buf, fc_buf, se_buf,  h_ch, SE_CLOSE);
		else
			printf("%s%s %s %s", bgc_buf, fc_buf,  h_ch, SE_CLOSE);
	}
	
	// 画空格和col_ch内容
	CURSOR_MOVE(p->sub_origin_x, p->sub_origin_y + y + 1);
	if(flag == 1)
		printf("%s%s%s %s", bgc_buf, fc_buf, se_buf,  SE_CLOSE);
	else
		printf("%s%s %s", bgc_buf, fc_buf, SE_CLOSE);
	
	for(x=0; x<inf_w+3; x++)
	{
		if(flag == 1)
			printf("%s%s%s%s%s", bgc_buf, fc_buf, se_buf, w_ch, SE_CLOSE);
		else
			printf("%s%s%s%s", bgc_buf, fc_buf, w_ch, SE_CLOSE);
	}
	
	if(flag == 1)
		printf("%s%s%s %s", bgc_buf, fc_buf, se_buf,  SE_CLOSE);
	else
		printf("%s%s %s", bgc_buf, fc_buf, SE_CLOSE);
	
	
	// 打印此界面的长宽
	// CURSOR_MOVE(main_inf_x, main_inf_y+main_inf_h+2);
	// printf("inf_h: %d, inf_h: %d", inf_h, inf_h);

	
	fflush(stdout);	
}

/**
  * @brief  设置要显示在printfui界面的文本内容
  * @note   None	
  * @param  text：    要显示在printfui界面的文本内容 
            screen_x：printfui界面的x轴
            screen_y：printfui界面的y轴
            bgc_buf： 背景颜色
            fc_buf：  字体颜色
            se_buf：  显示特效
  * @retval None
  */ 
void PRINTF_UI_SetSubText(const unsigned char *text, int text_x, int text_y, Printf_Ui_Atr *p, const unsigned char *bgc_buf, const unsigned char *fc_buf, const unsigned char *se_buf)
{
	fflush(stdout);
	
	// 算出显示字在子界面的初始x轴和y轴位置
	int sinf_text_x = text_x + p->sub_origin_x + 2;		
	int sinf_text_y = text_y + p->sub_origin_y + 1;
	
    // (1)、移动光标位置
	CURSOR_MOVE(sinf_text_x, sinf_text_y);	
	
	// (2)、printf函数特效打印
	if(strcmp(se_buf, SE_CLOSE)!=0)
		printf("%s%s%s%s%s", bgc_buf, fc_buf, se_buf, text, SE_CLOSE);
	else
		printf("%s%s%s%s", bgc_buf, fc_buf, text, SE_CLOSE);
	
	fflush(stdout);
}
