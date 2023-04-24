/********************************************************
FileName:choice.c
Author:GRH
Description：该模块为选关，转跳，调节模块，级模块，调用game模块,renew模块
FunctionList：
	1.int choice(struct island ild[])
	2.void g_choice(void)
********************************************************/
#include"structer.h"
#include"normal.h"
#include"page3.h"
#include"choice.h"
#include"game.h"
#include "putbmp.h"
#include"renew.h"
/*************************************************
Function：选择中心
Input：
	struct island ild[]
Author:GRH
Output：1.page
		2.com
*************************************************/
int choice(struct island ild[])
{
	int com,page;
	int flag;
	flag = 0;
	com = 0;
	page = 0;
	clrmous(MouseX, MouseY);
	delay(100);
	setfillstyle(0, GREEN);
	g_choice();
	while (1)
	{
		newmouse(&MouseX, &MouseY, &press);
		if (mouse_press(30, 100, 30 + 150, 100 + 150) == 1)
		{
			com = 1;
			if (flag == 0)
			{
				begin(&ild[0], &ild[10]);
			}
			while (press == 1)
			{
				newmouse(&MouseX, &MouseY, &press);
			}
			page = game(ild,com);
			return page;
		}
		if (mouse_press(200 + 30, 100, 200 + 150 + 30, 100 + 150) == 1)
		{
			com = 2;
			if (flag == 0)
			{
				begin(&ild[0], &ild[10]);
			}
			while (press == 1)
			{
				newmouse(&MouseX, &MouseY, &press);
			}
			page = game(ild,com);
			return page;
		}
		if (mouse_press(370 + 30, 100, 370 + 150, 100 + 150 + 30) == 1)
		{
			com = 3;
			if (flag == 0)
			{
				begin(&ild[0], &ild[10]);
			}
			while (press == 1)
			{
				newmouse(&MouseX, &MouseY, &press);
			}
			page = game(ild,com);
			return page;
		}
		else if (mouse_press(30, 120 + 200, 30 + 150, 100 + 120 + 180) == 1)
		{
			selfdesign(ild);
			flag = 1;
			cleardevice();                                                                                                                                          
			g_choice();
		}
		else if (mouse_press(20, 5, 40, 25) == 1)
		{
			page = 3;
			break;
		}
		else if (mouse_press(600, 5, 620, 25) == 1)
		{
			page = 3;
			break;
		}
	}
	return(page);
}
/*************************************************
Function：选择中心绘图
Input：无
Author:GRH
Output：无
*************************************************/
void g_choice(void)
{
	cleardevice();
	bar(2, 281, 449, 599);
	putbmp(1, 1, "database\\drbj.bmp");
	bar(30, 100, 30 + 150, 100 + 150);
	bar(200+30, 100, 200 + 150 + 30, 100 + 150 );
	bar(370 + 30 + 30, 100, 370 + 150 + 30 + 30, 100 + 150);
	puthz(70 , 150, "普通", 24, 30, RED);
	puthz(70, 180, "难度", 24, 30, RED);
	puthz(280, 150, "中等",24, 30, RED);
	puthz(280, 180, "难度", 24, 30, RED);
	puthz(470, 150, "地狱",24, 26, RED);
	puthz(470, 180, "难度", 24, 30, RED);
	setcolor(CYAN);
	setlinestyle(0, 0, 3);
	rectangle(600, 5, 620, 25);
	line(600, 5, 620, 25);
	line(620, 5, 600, 25);//右上角的框
	rectangle(20, 5, 40, 25);
	line(20, 15, 40, 15);
	line(20, 15, 25, 10);
	line(20, 15, 25, 20);//左上角的框
	setfillstyle(1, WHITE);
	bar(30, 320,180, 400);
	puthz(70, 150+200, "设置", 24, 30, RED);
}