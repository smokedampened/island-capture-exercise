/********************************************************
FileName:twopeople.h
Author:
Main author :
Description����ģ��Ϊ˫����Ϸģ�飬����ģ�飬����timerģ��,renewģ�飬processģ��,computerģ��
FunctionList��
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
Function����Ϸ�����ͼ����
Input��
	��
Author:GRH
Output����
*************************************************/
void g_game_(void)
{
	cleardevice();
	setbkcolor(WHITE);
	bar(2, 281, 449, 599);
	putbmp(1, 280, "database\\czk.bmp");
	puthz(16 + 100, 406 - 30 + 50 - 15, "���䲿��", 24, 26, RED);
	puthz(16 + 15, 306 + 50, "�鿴����", 24, 26, RED);
	puthz(206 + 30, 306 + 50 - 35, "�ӹ̵���", 24, 26, RED);
	puthz(1, 250, "�����غ�", 24, 26, RED);
	puthz(206 + 100, 406 - 30 + 50 - 50, "�������", 24, 26, RED);
	setcolor(CYAN);
	setlinestyle(0, 0, 3);
	rectangle(600, 5, 620, 25);
	line(600, 5, 620, 25);
	line(620, 5, 600, 25);//���ϽǵĿ�
	rectangle(20, 5, 40, 25);
	line(20, 15, 40, 15);
	line(20, 15, 25, 10);
	line(20, 15, 25, 20);//���ϽǵĿ�
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
	puthz(68 - 30, 155 - 30, "�о�����", 16, 16, RED);
	puthz(388 - 30, 155 - 30, "�Ҿ�����", 16, 16, RED);
	puthz(165, 455, "��Ҷ��Ļغ�", 24, 26, RED);
}
/*************************************************
Function����Ϸ�����ܹ��ܺ���
Input��
	1.struct island ild[]
	2.int com
Author:GRH
Output��
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
	g_game_();   //draw game module ����game����
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
					puthz(459, 235, "������������", 24, 26, RED);
					puthz(459, 295, "����ʧ��", 24, 26, RED);
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
				puthz(459, 235, "����غϿ���", 24, 26, RED);
				puthz(459, 265, "����Ĵ����Ѵ�����", 24, 26, RED);
				puthz(459, 415, "����ʧ��", 24, 26, RED);
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
Function����Ϸ����鿴���ܺ���
Input��
	1.struct island * pt
Author:HJW
Output��
	��
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
		puthz(454, 45, "½��", 24, 26, RED);
		outtextxy(545, 42, n);
		sprintf(a, "%d", (pt->at2.num));
		puthz(454, 75, "�ھ�", 24, 26, RED);
		outtextxy(545, 72, n);
		sprintf(a, "%d", (pt->bt2.num));
		puthz(454, 105, "����", 24, 26, RED);
		outtextxy(545, 102, n);
		sprintf(a, "%d", (pt->sp.num));
		puthz(454, 135, "װ��", 24, 26, RED);
		outtextxy(545, 132, n);
		z = (pt->sp.defes) * 10;
		b[0] = 10 - (int)z + 48;
		b[1] = '\0';
		puthz(425, 165, "�ӹ̶̳�", 24, 26, RED);
		outtextxy(545, 162, m);
		puthz(424, 205, "�ҷ�����", 24, 26, RED);
	}
	if ((pt->id2) == 1)
	{
		sprintf(a, "%d", (pt->amy1.num));
		settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);
		settextjustify(LEFT_TEXT, TOP_TEXT);
		puthz(454, 45, "½��", 24, 26, RED);
		outtextxy(545, 42, n);
		sprintf(a, "%d", (pt->at1.num));
		puthz(454, 75, "�ھ�", 24, 26, RED);
		outtextxy(545, 72, n);
		sprintf(a, "%d", (pt->bt1.num));
		puthz(454, 105, "����", 24, 26, RED);
		outtextxy(545, 102, n);
		sprintf(a, "%d", (pt->sp.num));
		puthz(454, 135, "װ��", 24, 26, RED);
		outtextxy(545, 132, n);
		z = (pt->sp.defes) * 10;
		b[0] = 10 - (int)z + 48;
		b[1] = '\0';
		puthz(425, 165, "�ӹ̶̳�", 24, 26, RED);
		outtextxy(545, 162, m);
		puthz(424, 205, "�з�����", 24, 26, RED);
	}	
	if ((pt->id2) == 0)
	{
		sprintf(a, "%d", (pt->amy1.num));
		settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);
		settextjustify(LEFT_TEXT, TOP_TEXT);
		puthz(454, 45, "½��", 24, 26, RED);
		outtextxy(545, 42, n);
		sprintf(a, "%d", (pt->at1.num));
		puthz(454, 75, "�ھ�", 24, 26, RED);
		outtextxy(545, 72, n);
		sprintf(a, "%d", (pt->bt1.num));
		puthz(454, 105, "����", 24, 26, RED);
		outtextxy(545, 102, n);
		sprintf(a, "%d", (pt->sp.num));
		puthz(454, 135, "װ��", 24, 26, RED);
		outtextxy(545, 132, n);
		z = (pt->sp.defes) * 10;
		b[0] = 10 - (int)z + 48;
		b[1] = '\0';
		puthz(425, 165, "�ӹ̶̳�", 24, 26, RED);
		outtextxy(545, 162, m);
		puthz(424, 205, "�յ���", 24, 26, RED);
	}
	if ((pt->id2) == 3)
	{
		settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);
		settextjustify(LEFT_TEXT, TOP_TEXT);

		sprintf(a, "%d", (pt->amy2.num));
		puthz(424, 45, "�ҷ�½��", 24, 26, RED);
		outtextxy(545, 42, n);

		sprintf(a, "%d", (pt->at2.num));
		puthz(424, 75, "�ҷ��ھ�", 24, 26, RED);
		outtextxy(545, 72, n);

		sprintf(a, "%d", (pt->bt2.num));
		puthz(424, 105, "�ҷ�����", 24, 26, RED);
		outtextxy(545, 102, n);



		sprintf(a, "%d", (pt->amy1.num));
		puthz(424, 205, "�з�½��", 24, 26, RED);
		outtextxy(545, 202, n);

		sprintf(a, "%d", (pt->at1.num));
		puthz(424, 235, "�з��ھ�", 24, 26, RED);
		outtextxy(545, 232, n);

		sprintf(a, "%d", (pt->bt1.num));
		puthz(424, 265, "�з�����", 24, 26, RED);
		outtextxy(545, 262, n);



		sprintf(a, "%d", (pt->sp.num));
		puthz(454, 305, "װ��", 24, 26, RED);
		outtextxy(545, 302, n);

		z = (pt->sp.defes) * 10;
		b[0] = 10 - (int)z + 48;
		b[1] = '\0';
		puthz(425, 335, "�ӹ̶̳�", 24, 26, RED);
		outtextxy(545, 332, m);

		if ((pt->id1) = 1)
		{
			puthz(425, 435, "�ҷ�׼�������˵���", 24, 26, RED);
		}
	}

}
/*************************************************
Function����Ϸ�������书�ܺ���
Input��
	1.struct island * pt1
	2.
Author:HJW
Output��
	��
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
	puthz(424, 45, "½������", 24, 26, RED);
	puthz(424, 85, "�ھ�����", 24, 26, RED);
	puthz(424, 125, "��������", 24, 26, RED);
	puthz(424, 165, "��������", 24, 26, RED);
	puthz(424, 465 - 100, "ȷ��", 24, 26, RED);
	puthz(524, 465 - 100, "ȡ��", 24, 26, RED);
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
					puthz(459, 235, "�������", 24, 26, RED);
					delay(1000);
					setfillstyle(1, WHITE);
					bar(459, 235, 459 + 150, 235 + 100);
				}
				else
				{
					if (num_amy > (pt1->amy2.num) || ship > (pt1->bt2.num) || num_at > (pt1->at2.num) || supply > (pt1->sp.num))
					{
						puthz(459, 235, "���ϱ�������", 24, 26, RED);
						puthz(459, 295, "����ʧ��", 24, 26, RED);
						delay(1000);
						setfillstyle(1, WHITE);
						bar(459, 235, 459 + 150, 235 + 100);
					}
					else
					{
						total = (num_amy) * (pt1->amy2.rate) + (num_at) * (pt1->at2.rate) + supply;
						if (((pt1->bt1.ts_rate) * ship) < total)
						{
							puthz(459, 235, "��������", 24, 26, RED);
							puthz(459, 295, "����ʧ��", 24, 26, RED);
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
							puthz(459, 235, "����ɹ�", 24, 26, RED);
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
Function��˫����Ϸ������㹦�ܺ���
Input��
	1.struct island * pt1
	2.int round
	3.int com
Author:GRH
Output��
	��
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
	puthz(424, 45 , "�����ǵ�", 24, 26, RED);
	setfillstyle(1, BLUE);
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);
	settextjustify(LEFT_TEXT, TOP_TEXT);
	outtextxy(528, 45, n);
	puthz(584, 45, "�غ�", 24, 26, RED);
	puthz(424, 45 + 100, "�Ƿ�����غ�", 24, 26, RED);
	bar(454, 95 + 20 + 100, 504, 145 + 20 + 100);
	puthz(459, 105 + 20 + 100, "��", 24, 26, RED);
	setfillstyle(1, BLUE);
	bar(564, 95 + 20 + 100, 614, 145 + 20 + 100);
	puthz(569, 105 + 20 + 100, "��", 24, 26, RED);
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
	puthz(424, 45, "������������Ϊ", 24, 26, RED);
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);
	settextjustify(LEFT_TEXT, TOP_TEXT);
	outtextxy(428, 75, n);
	puthz(524, 115, "�������", 24, 26, RED);
	puthz(454, 145, "½��", 24, 26, RED);
	puthz(454, 185, "�ھ�", 24, 26, RED);
	puthz(454, 225, "����", 24, 26, RED);
	puthz(444, 465 - 100, "ȷ��", 24, 26, RED);
	puthz(544, 465 - 100, "ȡ��", 24, 26, RED);
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
			puthz(459, 235, "ȡ������", 24, 26, RED);
			break;
		}
		if (mouse_press(424, 465 - 100, 424 + 50, 465 + 50 - 100) == 1)
		{

			setfillstyle(1, WHITE);
			bar(459, 235, 459 + 150, 235 + 100);

			if ((num_amy < 0 || num_amy > 99) || (num_at < 0 || num_at > 99) || (num_bt < 0 || num_bt > 99))
			{
				puthz(459, 235, "��������", 24, 26, RED);
			}
			else
			{
				if (num_amy > (pt->amy2.num) || num_bt > (pt->bt2.num) || num_at > (pt->at2.num))
				{
					puthz(459, 235, "���ϱ�������", 24, 26, RED);
					puthz(459, 295, "����ʧ��", 24, 26, RED);
				}
				else
				{
					total = (num_amy) * (pt->amy2.rate) + (num_at) * (pt->at2.rate);
					if (((pt->sp.num)) < total)
					{
						puthz(459, 235, "���ʲ���", 24, 26, RED);
						puthz(459, 295, "����ʧ��", 24, 26, RED);
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
						puthz(459, 235, "����ɹ�", 24, 26, RED);
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