#include"normal.h"
#include "gback.h"
/*************************************************
Function：游戏简介函数
Input：
	无
Author:GRH
Output：
	int
*************************************************/
int  bkgrd()
{
	clrmous(MouseX, MouseY);
	delay(100);
	setfillstyle(0, WHITE);
	g_bkgrd();
	while (1)
	{
		newmouse(&MouseX, &MouseY, &press);
		if (mouse_press(100 - 20, 150 - 20, 100 + 100 - 20, 150 + 50 - 20) == 1)
		{
			cleardevice();
			g_bkgrd();
			gbkgrdl();
		}
		if (mouse_press(100 - 20, 250 - 20, 100 + 100 - 20, 250 + 50 - 20) == 1)
		{
			cleardevice();
			g_bkgrd();
			gbkgrdp();
		}
		if (mouse_press(100 - 20, 350 - 20, 100 + 100 - 20, 350 + 50 - 20) == 1)
		{
			cleardevice();
			g_bkgrd();
			gbkgrdh();
		}
		if (mouse_press(100 - 20, 450 - 20, 100 - 20 + 100, 450 + 50 - 20) == 1)
		{
			cleardevice();
			g_bkgrd();
			gbkgrdw(); 
		}
		if (mouse_press(550 - 5, 400 -5, 550 - 5+50, 400 - 5+25) == 1)
		{
			break;
		}
	}
	return 3;
 }
/*************************************************
Function：游戏简介函数，步兵部分
Input：
	无
Author:GRH
Output：
	无
*************************************************/
void gbkgrdh(void)
{
	setbkcolor(WHITE);
	bar(180, 281, 449, 599);
	putbmp(200, 200, "database\\boat.bmp");
	puthz(100+100+20, 100, "海军", 24, 24, RED);
	puthz(100 + 100 + 20, 130, "必需的运输兵种", 24, 24, RED);
	puthz(100 + 100 + 20, 160, "一次移动一个单位的距离", 24, 24, RED);
	puthz(550, 400, "退出", 24, 24, RED);
	setbkcolor(WHITE);
	bar(100, 350, 100 + 100, 350 + 50);
	puthz(100 - 20, 350 - 20, "海军", 24, 24, BLUE);
}
/*************************************************
Function：游戏简介函数，步兵部分
Input：
	无
Author:GRH
Output：
	无
*************************************************/
void gbkgrdp(void)
{
	setbkcolor(WHITE);
	bar(180, 281, 449, 599);
	putbmp(200 + 20, 200, "database\\tanke.bmp");
	puthz(100 + 100 + 20, 100, "炮兵", 24, 24, RED);
	puthz(100 + 100 + 20, 130, "伤害较低", 24, 24, RED);
	puthz(100 + 100 + 20, 160, "可以攻击单位范围内的目标", 24, 24, RED);
	puthz(550, 400, "退出", 24, 24, RED);
	setbkcolor(WHITE);
	bar(100, 250, 100 + 100, 250 + 50);
	puthz(100 - 20, 250 - 20, "炮兵", 24, 24, BLUE);
}
/*************************************************
Function：游戏简介函数，炮兵部分
Input：
	无
Author:GRH
Output：
	无
*************************************************/
void gbkgrdl(void)
{
	setbkcolor(WHITE);
	bar(180, 281, 449, 599);
	putbmp(200 + 20, 200, "database\\bub.bmp");
	puthz(100 + 100 + 20, 100, "陆军", 24, 24, RED);
	puthz(100 + 100 + 20, 130, "高伤害但是只能登岛作战", 24, 24, RED);
	puthz(550, 400, "退出", 24, 24, RED);
	setbkcolor(WHITE);
	bar(100, 150, 100 + 100, 150 + 50);
	puthz(100 - 20, 150 - 20, "陆军", 24, 24, BLUE);
}
/*************************************************
Function：游戏简介函数，海军部分
Input：
	无
Author:GRH
Output：
	无
*************************************************/
void gbkgrdw(void)
{
	setbkcolor(WHITE);
	bar(180, 281, 449, 599);
	putbmp(200 + 20, 200, "database\\wz.bmp");
	puthz(100 + 100 + 20, 100, "物资", 24, 24, RED);
	puthz(100 + 100 + 20, 130, "通过运送物资来加固你的岛屿", 24, 24, RED);
	puthz(100 + 100 + 20, 160, "让它逐渐变的坚不可摧", 24, 24, RED);
	puthz(550, 400, "退出", 24, 24, RED);
	setbkcolor(WHITE);
	bar(100, 450, 100 + 100, 450 + 50);
	puthz(100 - 20, 450 - 20, "物资", 24, 24, BLUE);
}
/*************************************************
Function：游戏简介函数，步兵部分
Input：
	无
Author:GRH
Output：
	无
*************************************************/
void g_bkgrd(void)
{
	cleardevice();
	setbkcolor(WHITE);
	bar(2, 281, 449, 599);
	bar(100, 150, 100 + 100, 150 + 50);
	bar(100, 250, 100 + 100, 250 + 50);
	bar(100, 350, 100 + 100, 350 + 50);
	bar(100, 450, 100 + 100, 450 + 50);
	bar(550, 400, 550 + 50, 400 + 30);


	puthz(100-20, 150 - 20, "陆军", 24, 24, RED);
	puthz(100 - 20, 250 - 20, "炮兵", 24, 24, RED);
	puthz(100 - 20, 350 - 20, "海军", 24, 24, RED);
	puthz(100 - 20, 450 - 20, "物资", 24, 24, RED);
	puthz(550, 400, "退出", 24, 24, RED);
	puthz(100 - 20, 50 - 20, "相关兵种介绍", 24, 24, RED);
}
