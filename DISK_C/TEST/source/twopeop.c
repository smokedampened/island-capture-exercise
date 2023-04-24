/********************************************************
FileName:twopeople.h
Author:
Main author :
Description：该模块为双人游戏模块，三级模块，调用timer模块,renew模块，process模块,computer模块
FunctionList：
	1 void resultamy(struct island ild[]);
	2.void resultat(struct island ild[]);
	3.int hurt1(struct island ild[], int n);
	4.int hurt2(struct island ild[], int n);
********************************************************/
#include"structer.h"
#include"normal.h"
#include"game.h"
#include"renew.h"
#include"page3.h"
#include"process.h"
#include"twopeop.h"
#include"rsgame.h"
/*************************************************
Function：游戏界面绘图函数
Input：
	无
Author:GRH
Output：无
*************************************************/
void g_game_(void)
{
	cleardevice();
	setbkcolor(WHITE);
	bar(2, 281, 449, 599);
	putbmp(1, 280, "database\\czk.bmp");
	puthz(16 + 100, 406 - 30 + 50 - 15, "运输部队", 24, 26, RED);
	puthz(16 + 15, 306 + 50, "查看兵力", 24, 26, RED);
	puthz(206 + 30, 306 + 50 - 35, "加固岛屿", 24, 26, RED);
	puthz(1, 250, "结束回合", 24, 26, RED);
	puthz(206 + 100, 406 - 30 + 50 - 50, "申请兵力", 24, 26, RED);
	setcolor(CYAN);
	setlinestyle(0, 0, 3);
	rectangle(600, 5, 620, 25);
	line(600, 5, 620, 25);
	line(620, 5, 600, 25);//右上角的框
	rectangle(20, 5, 40, 25);
	line(20, 15, 40, 15);
	line(20, 15, 25, 10);
	line(20, 15, 25, 20);//左上角的框
	circle(100-30, 160-30, 35);
	circle(180 - 30, 80 - 30, 25);
	circle(260 - 30, 80 - 30, 25);
	circle(340 - 30, 80 - 30, 25);
	circle(180 - 30, 160 - 30, 25);
	circle(260 - 30, 160 - 30, 25);
	circle(340 - 30, 160 - 30, 25);
	circle(180 - 30, 240 - 30, 25);
	circle(260 - 30, 240 - 30, 25);
	circle(340 - 30, 240 - 30, 25);
	circle(420 - 30, 160 - 30, 35);
	puthz(68 - 30, 155 - 30, "敌军基地", 16, 16, RED);
	puthz(388 - 30, 155 - 30, "我军基地", 16, 16, RED);
	puthz(165, 455, "玩家二的回合", 24, 26, RED);
}
/*************************************************
Function：游戏界面总功能函数
Input：
	1.struct island ild[]
	2.int com
Author:GRH
Output：
	1.page
*************************************************/
void game_(struct island ild[], int round)
{
	int i = 0;
	int time = 0;
	int c=0;
	int	page = 5; 
	int num;
	int flag = 0;
	int xx = 0;
	int yy = 0;
	int zz=0;
	int limit = 0;
	clrmous(MouseX, MouseY);
	delay(100);
	setfillstyle(0, GREEN);
	g_game_();   //draw game module 画出game界面
	ownership2(ild);
	while (page == 5)
	{
		newmouse(&MouseX, &MouseY, &press);
		if (mouse_press(14 + 15, 295 + 50, 135 + 15, 344 + 50) == 1)
		{
			c = ild_select();
			check(&ild[c]);
		}
		if (mouse_press(204 + 30, 295 + 50 - 35, 325 + 30, 344 + 50 - 35) == 1)
		{
			c = ild_select();
			rebuit(&ild[c]);
		}
		if (mouse_press(204, 395 - 30 + 50 - 50, 325 + 50, 444 - 30 - 50 + 50) == 1)
		{
			c = ild_select();
			applyarmy(&ild[c], ild);
		}
		if (mouse_press(14 + 100, 395 - 30 + 50 - 15, 135 + 100, 444 - 30 + 50 - 15) == 1)
		{
			if (limit < 4)
			while(1)
			{
				xx = ild_select() +1;
				yy = ild_select() +1;
				flag= judge(xx,yy);
				if (flag== 0)
				{
					puthz(459, 235, "两个岛不相邻", 24, 26, RED);
					puthz(459, 295, "运输失败", 24, 26, RED);
					delay(500);
					setfillstyle(1, WHITE);
					bar(425, 40, 899, 599);
					break;
				}
				else
				{
					ownership1(ild);
					transfer_(&ild[xx-1],&ild[yy-1], xx, yy);
					ownership2(ild);
					resultamy(ild);
					resultat(ild);
					flag = 0;
					break;
				}
			}
			else
			{
				setfillstyle(1, WHITE);
				bar(425, 40, 899, 599);
				bar(459, 235, 459 + 150, 235 + 100);
				puthz(459, 235, "这个回合可以", 24, 26, RED);
				puthz(459, 265, "运输的次数已达上限", 24, 26, RED);
				puthz(459, 415, "运输失败", 24, 26, RED);
			}
		}
		if (mouse_press(204, 395 - 30, 325, 444 - 30) == 1)
		{
			time = timer_(round);
			delay(100);
			if(time == 0)
			{
				break;
			}
		}
		else if (mouse_press(20, 5, 40, 25) == 1)
		{
			page = 3;
		}
		else if (mouse_press(600, 5, 620, 25) == 1)
		{
			page = CLOSE;
		}
	}
	return page;
}
/*************************************************
Function：游戏界面查看功能函数
Input：
	1.struct island * pt
Author:HJW
Output：
	无
*************************************************/
void check_(struct island* pt)
{
	int x ;
	char a[4],b[2];
	char* n = a;
	char* m = b;
	double z;
	setfillstyle(1, WHITE);
	bar(425, 40, 899, 599);
	if ((pt->id2) == 2)
	{
		sprintf(a, "%d", (pt->amy2.num));
		settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);
		settextjustify(LEFT_TEXT, TOP_TEXT);
		puthz(454, 45, "陆军", 24, 26, RED);
		outtextxy(545, 42, n);
		sprintf(a, "%d", (pt->at2.num));
		puthz(454, 75, "炮军", 24, 26, RED);
		outtextxy(545, 72, n);
		sprintf(a, "%d", (pt->bt2.num));
		puthz(454, 105, "海军", 24, 26, RED);
		outtextxy(545, 102, n);
		sprintf(a, "%d", (pt->sp.num));
		puthz(454, 135, "装备", 24, 26, RED);
		outtextxy(545, 132, n);
		z = (pt->sp.defes) * 10;
		b[0] = 10 - (int)z + 48;
		b[1] = '\0';
		puthz(425, 165, "加固程度", 24, 26, RED);
		outtextxy(545, 162, m);
		puthz(424, 205, "我方岛屿", 24, 26, RED);
	}
	if ((pt->id2) == 1)
	{
		sprintf(a, "%d", (pt->amy1.num));
		settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);
		settextjustify(LEFT_TEXT, TOP_TEXT);
		puthz(454, 45, "陆军", 24, 26, RED);
		outtextxy(545, 42, n);
		sprintf(a, "%d", (pt->at1.num));
		puthz(454, 75, "炮军", 24, 26, RED);
		outtextxy(545, 72, n);
		sprintf(a, "%d", (pt->bt1.num));
		puthz(454, 105, "海军", 24, 26, RED);
		outtextxy(545, 102, n);
		sprintf(a, "%d", (pt->sp.num));
		puthz(454, 135, "装备", 24, 26, RED);
		outtextxy(545, 132, n);
		z = (pt->sp.defes) * 10;
		b[0] = 10 - (int)z + 48;
		b[1] = '\0';
		puthz(425, 165, "加固程度", 24, 26, RED);
		outtextxy(545, 162, m);
		puthz(424, 205, "敌方岛屿", 24, 26, RED);
	}	
	if ((pt->id2) == 0)
	{
		sprintf(a, "%d", (pt->amy1.num));
		settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);
		settextjustify(LEFT_TEXT, TOP_TEXT);
		puthz(454, 45, "陆军", 24, 26, RED);
		outtextxy(545, 42, n);
		sprintf(a, "%d", (pt->at1.num));
		puthz(454, 75, "炮军", 24, 26, RED);
		outtextxy(545, 72, n);
		sprintf(a, "%d", (pt->bt1.num));
		puthz(454, 105, "海军", 24, 26, RED);
		outtextxy(545, 102, n);
		sprintf(a, "%d", (pt->sp.num));
		puthz(454, 135, "装备", 24, 26, RED);
		outtextxy(545, 132, n);
		z = (pt->sp.defes) * 10;
		b[0] = 10 - (int)z + 48;
		b[1] = '\0';
		puthz(425, 165, "加固程度", 24, 26, RED);
		outtextxy(545, 162, m);
		puthz(424, 205, "空岛屿", 24, 26, RED);
	}
	if ((pt->id2) == 3)
	{
		settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);
		settextjustify(LEFT_TEXT, TOP_TEXT);

		sprintf(a, "%d", (pt->amy2.num));
		puthz(424, 45, "我方陆军", 24, 26, RED);
		outtextxy(545, 42, n);

		sprintf(a, "%d", (pt->at2.num));
		puthz(424, 75, "我方炮军", 24, 26, RED);
		outtextxy(545, 72, n);

		sprintf(a, "%d", (pt->bt2.num));
		puthz(424, 105, "我方海军", 24, 26, RED);
		outtextxy(545, 102, n);



		sprintf(a, "%d", (pt->amy1.num));
		puthz(424, 205, "敌方陆军", 24, 26, RED);
		outtextxy(545, 202, n);

		sprintf(a, "%d", (pt->at1.num));
		puthz(424, 235, "敌方炮军", 24, 26, RED);
		outtextxy(545, 232, n);

		sprintf(a, "%d", (pt->bt1.num));
		puthz(424, 265, "敌方海军", 24, 26, RED);
		outtextxy(545, 262, n);



		sprintf(a, "%d", (pt->sp.num));
		puthz(454, 305, "装备", 24, 26, RED);
		outtextxy(545, 302, n);

		z = (pt->sp.defes) * 10;
		b[0] = 10 - (int)z + 48;
		b[1] = '\0';
		puthz(425, 335, "加固程度", 24, 26, RED);
		outtextxy(545, 332, m);

		if ((pt->id1) = 1)
		{
			puthz(425, 435, "我方准备进攻此岛！", 24, 26, RED);
		}
	}

}
/*************************************************
Function：游戏界面运输功能函数
Input：
	1.struct island * pt1
	2.
Author:HJW
Output：
	无
*************************************************/
void transfer_(struct island* pt1, struct island* pt2, int x,int y)
{
	int num_amy, num_at, ship,supply, total, judge;
	num_amy = 0;
	num_at = 0;
	ship = 0;
	supply = 0;
	setfillstyle(1, WHITE);
	bar(425, 40, 899, 599);
	bar(424, 465 - 100, 424 + 50, 465 + 50 - 100);
	bar(524, 465 - 100, 524 + 50, 465 + 50 - 100);
	clrmous(MouseX, MouseY);
	delay(100);
	puthz(424, 45, "陆军数量", 24, 26, RED);
	puthz(424, 85, "炮军数量", 24, 26, RED);
	puthz(424, 125, "海军数量", 24, 26, RED);
	puthz(424, 165, "物资数量", 24, 26, RED);
	puthz(424, 465 - 100, "确认", 24, 26, RED);
	puthz(524, 465 - 100, "取消", 24, 26, RED);
	while (1)
		{
			newmouse(&MouseX, &MouseY, &press);
			if (mouse_press(545, 42, 545+75, 42+25) == 1)
			{
				num_amy = inputposin(545, 42);
			}
			if (mouse_press(545, 82, 545 + 75, 82 + 25) == 1)
			{
				num_at = inputposin(545, 82);
			}
			if (mouse_press(545, 122, 545 + 75, 112 + 25) == 1)
			{
				ship = inputposin(545, 122);
			}
			if (mouse_press(545, 162, 545 + 75, 162 + 25) == 1)
			{
				supply = inputposin(545, 162);
			}
			if (mouse_press(524, 465 - 100, 524 + 50, 465 + 50 - 100) == 1)
			{
				break;
			}
			if (mouse_press(424, 465 - 100, 424 + 50, 465 + 50 - 100) == 1)
			{
				if ((num_amy < 0 || num_amy>99) || (num_at < 0 || num_at>99) || (ship < 0 || ship>99) ||(supply < 0 || supply>99))
				{
					puthz(459, 235, "输入错误", 24, 26, RED);
					delay(1000);
					setfillstyle(1, WHITE);
					bar(459, 235, 459 + 150, 235 + 100);
				}
				else
				{
					if (num_amy > (pt1->amy2.num) || ship > (pt1->bt2.num) || num_at > (pt1->at2.num) || supply > (pt1->sp.num))
					{
						puthz(459, 235, "岛上兵力不足", 24, 26, RED);
						puthz(459, 295, "运输失败", 24, 26, RED);
						delay(1000);
						setfillstyle(1, WHITE);
						bar(459, 235, 459 + 150, 235 + 100);
					}
					else
					{
						total = (num_amy) * (pt1->amy2.rate) + (num_at) * (pt1->at2.rate) + supply;
						if (((pt1->bt1.ts_rate) * ship) < total)
						{
							puthz(459, 235, "海军过少", 24, 26, RED);
							puthz(459, 295, "运输失败", 24, 26, RED);
							delay(1000);
							setfillstyle(1, WHITE);
							bar(459, 235, 459 + 150, 235 + 100);
						}
						else
						{
							(pt1->amy2.num) -= num_amy;
							(pt2->amy2.num) += num_amy;
							(pt1->at2.num) -= num_at;
							(pt2->at2.num) += num_at;
							(pt1->bt2.num) -= ship;
							(pt2->bt2.num) += ship;
							(pt1->sp.num) -= supply;
							(pt2->sp.num) += supply;
							puthz(459, 235, "运输成功", 24, 26, RED);
							delay(1000);
							setfillstyle(1, WHITE);
							bar(425, 40, 899, 599);
							break;
						}
					}
				}
			}
		}	
}
/*************************************************
Function：双人游戏界面结算功能函数
Input：
	1.struct island * pt1
	2.int round
	3.int com
Author:GRH
Output：
	无
*************************************************/
int timer_( int round)
{
	char a[4];
	char* n = a;
	int i;
	int time = 0;
	sprintf(a, "%d", round);
	setfillstyle(1, WHITE);
	bar(425, 40, 899, 599);
	puthz(424, 45 , "现在是第", 24, 26, RED);
	setfillstyle(1, BLUE);
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);
	settextjustify(LEFT_TEXT, TOP_TEXT);
	outtextxy(528, 45, n);
	puthz(584, 45, "回合", 24, 26, RED);
	puthz(424, 45 + 100, "是否结束回合", 24, 26, RED);
	bar(454, 95 + 20 + 100, 504, 145 + 20 + 100);
	puthz(459, 105 + 20 + 100, "是", 24, 26, RED);
	setfillstyle(1, BLUE);
	bar(564, 95 + 20 + 100, 614, 145 + 20 + 100);
	puthz(569, 105 + 20 + 100, "否", 24, 26, RED);
	clrmous(MouseX, MouseY);
	delay(100);
	while (1)
	{
		newmouse(&MouseX, &MouseY, &press);
		if (mouse_press(454, 95 + 20 + 100, 504, 145 + 20 + 100) == 1)
		{
			time = 0;
			setfillstyle(1, WHITE);
			bar(425, 40, 899, 599);
			break;
		}
		if (mouse_press(564, 95 + 20 + 100, 614, 145 + 20 + 100) == 1)
		{
			time = 1;
			setfillstyle(1, WHITE);
			bar(425, 40, 899, 599);
			break;
		}
	}
	return time;
}
void applyarmy_(struct island* pt, struct island ild[])
{
	int num_amy;
	int num_at;
	int num_bt;
	int total;
	char a[4];
	char* n = a;
	sprintf(a, "%d", (pt->sp.num));
	setfillstyle(1, WHITE);
	bar(425, 40, 899, 599);
	puthz(424, 45, "岛上物资数量为", 24, 26, RED);
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);
	settextjustify(LEFT_TEXT, TOP_TEXT);
	outtextxy(428, 75, n);
	puthz(524, 115, "申请兵力", 24, 26, RED);
	puthz(454, 145, "陆军", 24, 26, RED);
	puthz(454, 185, "炮军", 24, 26, RED);
	puthz(454, 225, "海军", 24, 26, RED);
	puthz(444, 465 - 100, "确认", 24, 26, RED);
	puthz(544, 465 - 100, "取消", 24, 26, RED);
	rectangle(545 - 1, 42 + 100 - 1, 545 + 75 + 1, 42 + 25 + 1 + 100);
	rectangle(545 - 1, 42 + 100 + 40 - 1, 545 + 1 + 75, 42 + 25 + 1 + 100 + 40);
	rectangle(545 - 1, 42 + 100 + 40 + 40 - 1, 545 + 1 + 75, 42 + 25 + 100 + 1 + 40 + 40);
	clrmous(MouseX, MouseY);
	delay(100);
	while (1)
	{
		newmouse(&MouseX, &MouseY, &press);
		if (mouse_press(545, 42 + 100, 545 + 75, 42 + 25 + 100) == 1)
		{
			num_amy = inputposin(545, 142);
		}
		if (mouse_press(545, 42 + 100 + 40, 545 + 75, 42 + 25 + 100 + 40) == 1)
		{
			num_at = inputposin(545, 182);
		}
		if (mouse_press(545, 42 + 100 + 40 + 40, 545 + 75, 42 + 25 + 100 + 40 + 40) == 1)
		{
			num_bt = inputposin(545, 222);
		}

		if (mouse_press(524, 465 - 100, 524 + 50, 465 + 50 - 100) == 1)
		{
			setfillstyle(1, WHITE);
			bar(425, 40, 899, 599);
			bar(459, 235, 459 + 150, 235 + 100);
			puthz(459, 235, "取消申请", 24, 26, RED);
			break;
		}
		if (mouse_press(424, 465 - 100, 424 + 50, 465 + 50 - 100) == 1)
		{

			setfillstyle(1, WHITE);
			bar(459, 235, 459 + 150, 235 + 100);

			if ((num_amy < 0 || num_amy > 99) || (num_at < 0 || num_at > 99) || (num_bt < 0 || num_bt > 99))
			{
				puthz(459, 235, "输入有误", 24, 26, RED);
			}
			else
			{
				if (num_amy > (pt->amy2.num) || num_bt > (pt->bt2.num) || num_at > (pt->at2.num))
				{
					puthz(459, 235, "岛上兵力不足", 24, 26, RED);
					puthz(459, 295, "运输失败", 24, 26, RED);
				}
				else
				{
					total = (num_amy) * (pt->amy2.rate) + (num_at) * (pt->at2.rate);
					if (((pt->sp.num)) < total)
					{
						puthz(459, 235, "物资不够", 24, 26, RED);
						puthz(459, 295, "申请失败", 24, 26, RED);
						setfillstyle(1, WHITE);
						bar(425, 40, 899, 599);
						break;
					}
					else
					{
						pt->sp.num -= total;
						ild[0].amy2.num += num_amy;
						ild[10].at2.num += num_at;
						ild[0].bt2.num += num_bt;
						puthz(459, 235, "申请成功", 24, 26, RED);
						delay(300);
						setfillstyle(1, WHITE);
						bar(425, 40, 899, 599);
						break;
					}
				}
			}
		}
	}
}