/********************************************************
FileName:progress.c
Author:
Main author :
Description����ģ��Ϊ��Ϸ�ڵ���ģ�飬����ģ�飬Ϊ��Ϸִ���ṩ������Ҫ���ܣ�����computerģ�飬renewģ�飬rsgameģ��
FunctionList��
	1 void ownership1(struct island ild[])
	2.void ownership2(struct island ild[])
	3.int inputposin(int x1, int y1)
	4.int ild_select()
	5.void rebuit(struct island* pt)
	6.int judge(int a, int b)
********************************************************/
#include"structer.h"
#include"normal.h"
#include"renew.h"
#include"page3.h"
#include"game.h"
#include"computer.h"
#include"twopeop.h"
#include"rsgame.h"
#include"process.h"
#include"pagelob.h"

/*************************************************
Function����������жϺ���1
Input��
	1.struct island * pt1
Author:HJW
Output��
	��
*************************************************/
void ownership1(struct island ild[])
{
	int i;
	for (i = 0; i < 11; i++)
	{
		if (ild[i].amy1.num > 0
			|| ild[i].at1.num > 0
			|| ild[i].bt1.num > 0)
		{
			ild[i].id1 = 1;
		}
		else if (ild[i].amy2.num > 0
			|| ild[i].at2.num > 0
			|| ild[i].bt2.num > 0)
		{
			ild[i].id1 = 2;
		}
		else
		{
			ild[i].id1 = 0;
		}
	}
}

/*************************************************
Function����������жϺ���2�������־
Input��
	1.struct island * pt1
Author:HJW
Output��
	��
*************************************************/
void ownership2(struct island ild[])
{
	int i,x;
	for (i = 0; i < 11; i++)
	{
		if ((ild[i].amy1.num > 0
			|| ild[i].at1.num > 0
			|| ild[i].bt1.num > 0)
			&&
			(ild[i].amy2.num > 0
				|| ild[i].at2.num > 0
				|| ild[i].bt2.num > 0))
		{
			ild[i].id2 = 3;
		}
		else if (ild[i].amy1.num > 0
			|| ild[i].at1.num > 0
			|| ild[i].bt1.num > 0)
		{
			ild[i].id2 = 1;
		}
		else if (ild[i].amy2.num > 0
			|| ild[i].at2.num > 0
			|| ild[i].bt2.num > 0)
		{
			ild[i].id2 = 2;
		}
		else
		{
			ild[i].id2 = 0;
		}
	}
	/*for (i = 1; i < 4; i++)
	{
		if ((ild[i].id1 )== 1)
		{
			x = 80 * (i-1);
			setcolor(RED);
			setlinestyle(0, 0, 3);
			line(147,70+x,147,40 + x);
			line(147,50 + x,157,50 + x);
			line(147,40 + x,157,40 + x);
			line(157,40 + x,157,50 + x);
		}
		if ((ild[i].id1) == 2)
		{
			x = 80 * (i - 1);
			setcolor(BLUE);
			setlinestyle(0, 0, 3);
			line(147, 70 + x, 147, 40 + x);
			line(147, 50 + x, 157, 50 + x);
			line(147, 40 + x, 157, 40 + x);
			line(157, 40 + x, 157, 50 + x);
		}
	}
	for (i = 4; i < 7; i++)
	{
		if ((ild[i].id1) == 1)
		{
			x = 80 * (i - 4);
			setcolor(RED);
			setlinestyle(0, 0, 3);
			line(147+80, 70 + x, 147 + 80, 40 + x);
			line(147 + 80, 50 + x, 157 + 80, 50 + x);
			line(147 + 80, 40 + x, 157 + 80, 40 + x);
			line(157 + 80, 40 + x, 157 + 80, 50 + x);
		}
		if ((ild[i].id1) == 2)
		{
			x = 80 * (i - 4);
			setcolor(BLUE);
			setlinestyle(0, 0, 3);
			line(147 + 80, 70 + x, 147 + 80, 40 + x);
			line(147 + 80, 50 + x, 157 + 80, 50 + x);
			line(147 + 80, 40 + x, 157 + 80, 40 + x);
			line(157 + 80, 40 + x, 157 + 80, 50 + x);
		}
	}
	for (i = 7; i < 10; i++)
	{
		if ((ild[i].id1) == 1)
		{
			x = 80 * (i - 7);
			setcolor(RED);
			setlinestyle(0, 0, 3);
			line(147 + 160, 70 + x, 147 + 160, 40 + x);
			line(147 + 160, 50 + x, 157 + 160, 50 + x);
			line(147 + 160, 40 + x, 157 + 160, 40 + x);
			line(157 + 160, 40 + x, 157 + 160, 50 + x);
		}
		if ((ild[i].id1) == 2)
		{
			x = 80 * (i - 7);
			setcolor(BLUE);
			setlinestyle(0, 0, 3);
			line(147 + 160, 70 + x, 147 + 160, 40 + x);
			line(147 + 160, 50 + x, 157 + 160, 50 + x);
			line(147 + 160, 40 + x, 157 + 160, 40 + x);
			line(157 + 160, 40 + x, 157 + 160, 50 + x);
		}
	}*/
}

/*************************************************
Function���������ݵ�ѡ���ж�
Input��
	1.struct island * pt1
	2.int x
	3.int y
Author:GRH
Output��
	��
*************************************************/
int inputposin(int x1, int y1)
{
	int i = 0, num;
	char t;
	char a[2];
	char b[80];
	strcpy(b, "\0");
	clrmous(MouseX, MouseY);
	setfillstyle(SOLID_FILL, LIGHTGRAY);
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	bright(x1, y1, x1 + 281, y1 + 22, LIGHTGRAY);
	setcolor(BLUE);
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);
	settextjustify(LEFT_TEXT, TOP_TEXT);

	while (1)
	{
		t = bioskey(0);
		if (i < 2)
		{
			if (t != '\n' && t != '\r' && t != ' ')
			{
				if (t != '\b')
				{
					b[i] = t;
					a[0] = t;
					a[1] = '\0';
					b[i + 1] = '\0';
					outtextxy(2 + x1 + i * 10, y1 - 2, a);
					i++;
				}
				else if (t == '\b' && i > 0)
				{
					bar(x1 + i * 10 - 8, y1, x1 + i * 10 + 4, y1 + 22);
					i--;
					b[i] = '\0';
				}
			}
			else
			{
				setfillstyle(SOLID_FILL, LIGHTGRAY);
				break;
			}
		}
		else if (i >= 2)
		{
			if (t != '\n' && t != '\r' && t != ' ' && t != 033)//Esc
			{
				if (t == '\b' && i > 0)
				{
					bar(x1 + i * 10 - 8, y1, x1 + i * 10 + 4, y1 + 22);
					i--;
					b[i] = '\0';
				}
			}
			else
			{
				setfillstyle(SOLID_FILL, LIGHTGRAY);
				break;
			}
		}
	}
	bright(x1, y1, x1 + 281, y1 + 22, WHITE);
	outtextxy(x1 + 2, y1 - 2, b);
	num = atoi(b);
	if (((b[0] < '0') || (b[0] > '9') && (b[1] != '\0')) || (((b[1] < '0') || (b[1] > '9')) && (b[1] != '\0')))
	{
		num = atoi(b) + 100;
	}
	if (num > -1 && num < 1000)
	{
		return (num);
	}
	else
	{
		return (1000);
	}
}
/*************************************************
Function������ѡ����
Input��
	1.struct island * pt1
Author:GRH
Output��
	int
*************************************************/
int ild_select()
{
	clrmous(MouseX, MouseY);
	delay(100);
	setfillstyle(1, WHITE);
	bar(425, 40, 899, 599);
	puthz(424, 45, "��ѡ��һ������", 24, 26, RED);
	while (1)
	{
		newmouse(&MouseX, &MouseY, &press);
		if (mouse_press(100 - 30 - 35, 160 - 30 - 35, 100 - 30 + 35, 160 - 30 + 35) == 1)
		{
			puthz(424, 85, "��ѡ����һ�ŵ�", 24, 26, RED);
			delay(500);
			return 0;
		}
		if (mouse_press(180 - 30 - 25, 80 - 30 - 25, 180 - 30 + 25, 80 - 30) == 1)
		{
			puthz(424, 85, "��ѡ���Ƕ��ŵ�", 24, 26, RED);
			delay(500);
			return 1;
		}
		if (mouse_press(180 - 30 - 25, 160 - 30 - 25, 180 - 30 + 25, 160 - 30 + 25) == 1)
		{
			puthz(424, 85, "��ѡ�������ŵ�", 24, 26, RED);
			delay(500);
			return 2;
		}
		if (mouse_press(180 - 30 - 25, 240 - 30 - 25, 180 - 30 + 25, 240 - 30 + 25) == 1)
		{
			puthz(424, 85, "��ѡ�����ĺŵ�", 24, 26, RED);
			delay(500);
			return 3;
		}
		if (mouse_press(260 - 30 - 25, 80 - 30 - 25, 260 - 30 + 25, 80 - 30 + 25) == 1)
		{

			puthz(424, 85, "��ѡ������ŵ�", 24, 26, RED);
			delay(500);
			return 4;
		}
		if (mouse_press(260 - 30 - 25, 160 - 30 - 25, 260 - 30 + 25, 160 - 30 + 25) == 1)
		{
			puthz(424, 85, "��ѡ�������ŵ�", 24, 26, RED);
			delay(500);
			return 5;
		}
		if (mouse_press(260 - 30 - 25, 240 - 30 - 25, 260 - 30 + 25, 240 - 30 + 25) == 1)
		{
			puthz(424, 85, "��ѡ�����ߺŵ�", 24, 26, RED);
			delay(500);
			return 6;
		}
		if (mouse_press(340 - 30 - 25, 80 - 30 - 25, 340 - 30 + 25, 80 - 30 + 25) == 1)
		{
			puthz(424, 85, "��ѡ���ǰ˺ŵ�", 24, 26, RED);
			delay(500);
			return 7;
		}
		if (mouse_press(340 - 30 - 25, 160 - 30 - 25, 340 - 30 + 25, 160 - 30 + 25) == 1)
		{
			puthz(424, 85, "��ѡ���Ǿźŵ�", 24, 26, RED);
			delay(500);
			return 8;
		}
		if (mouse_press(340 - 30 - 25, 240 - 30 - 25, 340 - 30 + 25, 240 - 30 + 25) == 1)
		{
			puthz(424, 85, "��ѡ����ʮ�ŵ�", 24, 26, RED);
			delay(500);
			return 9;
		}
		if (mouse_press(420 - 30 - 35, 160 - 30 - 35, 420 - 30 + 35, 160 - 30 + 35) == 1)
		{
			puthz(424, 85, "��ѡ����ʮһ�ŵ�", 24, 26, RED);
			delay(500);
			return 10;
		}
	}
}
void rebuit(struct island* pt)//����һ������ַ�����������
{
	char a[4];
	char* n = a;
	sprintf(a, "%d", (pt->sp.num));
	setfillstyle(1, WHITE);
	bar(425, 40, 899, 599);
	puthz(424, 45, "������������Ϊ", 24, 26, RED);
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);
	settextjustify(LEFT_TEXT, TOP_TEXT);
	outtextxy(428, 75, n);

	puthz(424, 45 + 100, "�Ƿ���мӹ�", 24, 26, RED);

	setfillstyle(1, BLUE);
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
			if (pt->sp.num >= 10)
			{
				pt->sp.num -= 10;
				pt->sp.defes -= 0.1;
				puthz(459, 235 + 100, "�ӹ̳ɹ�", 24, 26, RED);
				delay(500);
				setfillstyle(1, WHITE);
				bar(425, 40, 899, 599);
				break;
			}
			else
			{
				puthz(459, 235 + 100, "������������", 24, 26, RED);
				puthz(459, 295 + 100, "�ӹ�ʧ��", 24, 26, RED);
				delay(500);
				setfillstyle(1, WHITE);
				bar(425, 40, 899, 599);
				break;
			}
		}
		if (mouse_press(564, 95 + 20 + 100, 614, 145 + 20 + 100) == 1)
		{
			delay(500);
			setfillstyle(1, WHITE);
			bar(425, 40, 899, 599);
			break;
		}
	}
}
int judge(int a, int b)
{
	int flag = 0;
	switch (a)
	{
	case(1):
	{
		if (b != 1 && b != 2 && b != 3 && b != 4)
		{
			flag = 0;
		}
		else
		{
			flag = 1;
		}
	}break;
	case(2):
	{
		if (b != 1 && b != 2 && b != 3 && b != 5)
		{
			flag = 0;
		}
		else
		{
			flag = 1;
		}
	}break;
	case(3):
	{
		if (b != 1 && b != 2 && b != 3 && b != 4 && b != 6)
		{
			flag = 0;
		}
		else
		{
			flag = 1;
		}
	}break;
	case(4):
	{
		if (b != 1 && b != 3 && b != 4 && b != 7)
		{
			flag = 0;
		}
		else
		{
			flag = 1;
		}
	}break;
	case(5):
	{
		if (b != 2 && b != 5 && b != 6 && b != 8)
		{
			flag = 0;
		}
		else
		{
			flag = 1;
		}
	}break;
	case(6):
	{
		if (b != 3 && b != 5 && b != 6 && b != 7 && b != 9)
		{
			flag = 0;
		}
		else
		{
			flag = 1;
		}
	}break;
	case(7):
	{
		if (b != 4 && b != 6 && b != 7 && b != 10)
		{
			flag = 0;
		}
		else
		{
			flag = 1;
		}
	}break;
	case(8):
	{
		if (b != 5 && b != 8 && b != 9 && b != 11)
		{
			flag = 0;
		}
		else
		{
			flag = 1;
		}
	}break;
	case(9):
	{
		if (b != 6 && b != 8 && b != 9 && b != 10 && b != 11)
		{
			flag = 0;
		}
		else
		{
			flag = 1;
		}
	}break;
	case(10):
	{
		if (b != 7 && b != 9 && b != 10 && b != 11)
		{
			flag = 0;
		}
		else
		{
			flag = 1;
		}
	}break;
	case(11):
	{
		if (b != 8 && b != 9 && b != 10 && b != 11)
		{
			flag = 0;
		}
		else
		{
			flag = 1;
		}
	}break;
	}
	return flag;
}

