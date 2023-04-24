/********************************************************
FileName:renew.c
Author:
Main author :
Description：该模块为更新模块，一级模块，提供各种相关数据的更新和初始化
FunctionList：
	1.void renewgame(struct island ild[])
	2.void design(struct island* pt)
	3.void renew(struct island* pt)
	4.void begin(struct island* pt1, struct island* pt2)
	5.void  g_selfdesign(struct island ild[])
	6.void selfdesign(struct island ild[])
********************************************************/
#include"structer.h"
#include"normal.h"
#include"renew.h"
#include"choice.h"
/*************************************************
Function：调取每个岛上的更新信息函数
Input：
	struct island ild[]
Author:GRH
Output：
	void
*************************************************/
void renewgame(struct island ild[])
{

		int i, j;
		for (i = 0; i < 11; i++)
		{
			design(&ild[i]);
		}
		for (j = 1; j < 10; j++)
		{
			renew(&ild[j]);
		}
}
/*************************************************
Function：数据调节，平衡函数
Input：
	struct island* pt
Author:GRH
Output：
	void
*************************************************/
void design(struct island* pt)
{
	int a, b, c, d, e;
	a = 1;
	b = 3;
	c = 5;
	d = 1;
	e = 1;
	(pt->amy1.rate) = (pt->amy2.rate) = a;
	(pt->at1.rate) = (pt->at2.rate) = b;
	(pt->at1.atk) = (pt->at2.atk) = e;
	(pt->bt1.ts_rate) = (pt->bt2.ts_rate) = c;
}
void renew(struct island* pt)
{
	pt->sp.defes = 1;
}
/*************************************************
Function：默认游戏定义函数
Input：
	1.struct island* pt1, 	
	2.struct island* pt2
Author:GRH
Output：
	void
*************************************************/
void begin(struct island* pt1, struct island* pt2)
{
	pt1->amy1.num = 100;
	pt1->at1.num = 50;
	pt1->bt1.num = 80;
	pt1->sp.num = 100;
	pt1->amy2.num = 0;
	pt1->bt2.num = 0;
	pt1->at2.num = 0;
	pt1->sp.defes = 1;
	
	pt2->amy2.num = 100;
	pt2->at2.num = 50;
	pt2->bt2.num = 80;
	pt2->sp.num = 100;
	pt2->amy1.num = 0;
	pt2->at1.num = 0;
	pt2->bt1.num = 0;
	pt2->sp.defes = 1;
}
/*************************************************
Function：调节游戏初始化绘图函数
Input：
	1.struct island* pt1
Author:GRH
Output：
	void
*************************************************/
void  g_selfdesign(struct island ild[])
{
	char a[4], b[2];
	char* n = a;
	cleardevice();
	setbkcolor(WHITE);
	bar(2, 281, 449, 599);


	puthz(50, 50, "初始双方陆军数量", 24, 24, RED);
	rectangle(100, 85, 150, 135);
	line(110, 110, 125, 130 );
	line(140, 110 , 125, 130 );
	line(125, 130 -40, 125, 130);

	rectangle(350, 85, 400, 135);
	line(360, 110 , 375, 130 - 40);
	line(390, 110, 375, 130 - 40);
	line(375, 130-40, 375, 130 );

	sprintf(a, "%d", (ild[0].amy1.num));
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);
	settextjustify(LEFT_TEXT, TOP_TEXT);
	outtextxy(220, 105, n);



	puthz(50, 50+90, "初始双方炮兵数量", 24, 24, RED);
	rectangle(100, 85 + 90, 150, 135 + 90);
	line(110, 110 + 90, 125, 130 + 90);
	line(140, 110 + 90, 125, 130 + 90);
	line(125, 130 - 40 + 90, 125, 130 + 90);

	rectangle(350, 85 + 90, 400, 135 + 90);
	line(360, 110 + 90, 375, 130 - 40 + 90);
	line(390, 110 + 90, 375, 130 - 40 + 90);
	line(375, 130 - 40 + 90, 375, 130 + 90);

	sprintf(a, "%d", (ild[0].at1.num));
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);
	settextjustify(LEFT_TEXT, TOP_TEXT);
	outtextxy(220, 105 + 90, n);


	puthz(50, 50+180, "初始双方海军数量", 24, 24, RED);
	rectangle(100, 85 + 180, 150, 135 + 180);
	line(110, 110 + 180, 125, 130 + 180);
	line(140, 110 + 180, 125, 130 + 180);
	line(125, 130 + 180 - 40, 125, 130 + 180);

	rectangle(350, 85 + 180, 400, 135 + 180);
	line(360, 110 + 180, 375, 130 - 40 + 180);
	line(390, 110 + 180, 375, 130 - 40 + 180);
	line(375, 130 + 180 - 40, 375, 130 + 180);

	sprintf(a, "%d", (ild[0].bt1.num));
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);
	settextjustify(LEFT_TEXT, TOP_TEXT);
	outtextxy(220, 105 + 180, n);



	puthz(50, 50+270, "初始双方物资数量", 24, 24, RED);
	rectangle(100, 85 + 270, 150, 135 + 270);
	line(110, 110 + 270, 125, 130 + 270);
	line(140, 110 + 270, 125, 130 + 270);
	line(125, 130 + 270 - 40, 125, 130 + 270);

	rectangle(350, 85 + 270, 400, 135 + 270);
	line(360, 110 + 270, 375, 130 - 40 + 270);
	line(390, 110 + 270, 375, 130 - 40 + 270);
	line(375, 130 + 270 - 40, 375, 130 + 270);

	sprintf(a, "%d", (ild[0].sp.num));
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);
	settextjustify(LEFT_TEXT, TOP_TEXT);
	outtextxy(220, 105 + 270, n);

	puthz(550,400 ,"完成", 24, 24, RED);
}
/*************************************************
Function：调节游戏初始化函数
Input：
	1.struct island* pt1
Author:GRH
Output：
	void
*************************************************/
void selfdesign(struct island ild[])
{
	clrmous(MouseX, MouseY);
	delay(100);
	setfillstyle(0, GREEN);
	begin(&ild[0], &ild[10]);
	g_selfdesign(ild);
	while (1)
	{
		newmouse(&MouseX, &MouseY, &press);
		if (mouse_press(100, 85, 150, 135) == 1)
		{
			if ((ild[0].amy1.num) >= 55)
			{
				(ild[0].amy1.num) -= 5;
				(ild[10].amy2.num) -= 5;
			}
			clrmous(MouseX, MouseY);
			g_selfdesign(ild);
			while (press == 1)
			{
				newmouse(&MouseX, &MouseY, &press);
			}
		}
		if (mouse_press(350, 85, 400, 135) == 1)
		{
			if ((ild[0].amy1.num) <= 155)
			{
				(ild[0].amy1.num) += 5;
				(ild[10].amy2.num) += 5;
			}
			clrmous(MouseX, MouseY);
			g_selfdesign(ild);
			while (press == 1)
			{
				newmouse(&MouseX, &MouseY, &press);
			}
		}
		if (mouse_press(100, 85 + 90, 150, 135 + 90) == 1)
		{
			if ((ild[0].at1.num) >= 35)
			{
				(ild[0].at1.num) -= 5;
				(ild[10].at2.num) -= 5;
			}
			clrmous(MouseX, MouseY);
			g_selfdesign(ild);
			while (press == 1)
			{
				newmouse(&MouseX, &MouseY, &press);
			}
		}
		if (mouse_press(350, 85 + 90, 400, 135 + 90) == 1)
		{
			if ((ild[0].at1.num) <= 85)
			{
				(ild[0].at1.num) += 5;
				(ild[10].at2.num) += 5;
			}
			clrmous(MouseX, MouseY);
			g_selfdesign(ild);
			while (press == 1)
			{
				newmouse(&MouseX, &MouseY, &press);
			}
		}
		if (mouse_press(100, 85 + 180, 150, 135 + 180) == 1)
		{
			if ((ild[0].bt1.num) >= 55)
			{
				(ild[0].bt1.num) -= 5;
				(ild[10].bt2.num) -= 5;
			}
			clrmous(MouseX, MouseY);
			g_selfdesign(ild);
			while (press == 1)
			{
				newmouse(&MouseX, &MouseY, &press);
			}
		}
		if (mouse_press(350, 85 + 180, 400, 135 + 180) == 1)
		{
			if ((ild[0].bt1.num) <= 125)
			{
				(ild[0].bt1.num) += 5;
				(ild[10].bt2.num) += 5;
			}
			clrmous(MouseX, MouseY);
			g_selfdesign(ild);
			while (press == 1)
			{
				newmouse(&MouseX, &MouseY, &press);
			}
		}
		if (mouse_press(100, 85 + 270, 150, 135 + 270) == 1)
		{
			if ((ild[0].sp.num) >= 35)
			{
				(ild[0].sp.num) -= 5;
				(ild[10].sp.num) -= 5;
			}
			clrmous(MouseX, MouseY);
			g_selfdesign(ild);
			while (press == 1)
			{
				newmouse(&MouseX, &MouseY, &press);
			}
		}
		if (mouse_press(350, 85 + 270, 400, 135 + 270) == 1)
		{
			if ((ild[0].sp.num) <= 125)
			{
				(ild[0].sp.num) += 5;
				(ild[10].sp.num) += 5;
			}
			clrmous(MouseX, MouseY);
			g_selfdesign(ild);
			while (press == 1)
			{
				newmouse(&MouseX, &MouseY, &press);
			}
		}
		if (mouse_press(550, 400, 550+50, 400+30) == 1)
		{
			clrmous(MouseX, MouseY);
			delay(100);
			setfillstyle(0, GREEN);
			choice(ild);
			break;
		}
	}
}