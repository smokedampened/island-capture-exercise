#include"normal.h"
#include "gback.h"
/*************************************************
Function����Ϸ��麯��
Input��
	��
Author:GRH
Output��
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
Function����Ϸ��麯������������
Input��
	��
Author:GRH
Output��
	��
*************************************************/
void gbkgrdh(void)
{
	setbkcolor(WHITE);
	bar(180, 281, 449, 599);
	putbmp(200, 200, "database\\boat.bmp");
	puthz(100+100+20, 100, "����", 24, 24, RED);
	puthz(100 + 100 + 20, 130, "������������", 24, 24, RED);
	puthz(100 + 100 + 20, 160, "һ���ƶ�һ����λ�ľ���", 24, 24, RED);
	puthz(550, 400, "�˳�", 24, 24, RED);
	setbkcolor(WHITE);
	bar(100, 350, 100 + 100, 350 + 50);
	puthz(100 - 20, 350 - 20, "����", 24, 24, BLUE);
}
/*************************************************
Function����Ϸ��麯������������
Input��
	��
Author:GRH
Output��
	��
*************************************************/
void gbkgrdp(void)
{
	setbkcolor(WHITE);
	bar(180, 281, 449, 599);
	putbmp(200 + 20, 200, "database\\tanke.bmp");
	puthz(100 + 100 + 20, 100, "�ڱ�", 24, 24, RED);
	puthz(100 + 100 + 20, 130, "�˺��ϵ�", 24, 24, RED);
	puthz(100 + 100 + 20, 160, "���Թ�����λ��Χ�ڵ�Ŀ��", 24, 24, RED);
	puthz(550, 400, "�˳�", 24, 24, RED);
	setbkcolor(WHITE);
	bar(100, 250, 100 + 100, 250 + 50);
	puthz(100 - 20, 250 - 20, "�ڱ�", 24, 24, BLUE);
}
/*************************************************
Function����Ϸ��麯�����ڱ�����
Input��
	��
Author:GRH
Output��
	��
*************************************************/
void gbkgrdl(void)
{
	setbkcolor(WHITE);
	bar(180, 281, 449, 599);
	putbmp(200 + 20, 200, "database\\bub.bmp");
	puthz(100 + 100 + 20, 100, "½��", 24, 24, RED);
	puthz(100 + 100 + 20, 130, "���˺�����ֻ�ܵǵ���ս", 24, 24, RED);
	puthz(550, 400, "�˳�", 24, 24, RED);
	setbkcolor(WHITE);
	bar(100, 150, 100 + 100, 150 + 50);
	puthz(100 - 20, 150 - 20, "½��", 24, 24, BLUE);
}
/*************************************************
Function����Ϸ��麯������������
Input��
	��
Author:GRH
Output��
	��
*************************************************/
void gbkgrdw(void)
{
	setbkcolor(WHITE);
	bar(180, 281, 449, 599);
	putbmp(200 + 20, 200, "database\\wz.bmp");
	puthz(100 + 100 + 20, 100, "����", 24, 24, RED);
	puthz(100 + 100 + 20, 130, "ͨ�������������ӹ���ĵ���", 24, 24, RED);
	puthz(100 + 100 + 20, 160, "�����𽥱�ļ᲻�ɴ�", 24, 24, RED);
	puthz(550, 400, "�˳�", 24, 24, RED);
	setbkcolor(WHITE);
	bar(100, 450, 100 + 100, 450 + 50);
	puthz(100 - 20, 450 - 20, "����", 24, 24, BLUE);
}
/*************************************************
Function����Ϸ��麯������������
Input��
	��
Author:GRH
Output��
	��
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


	puthz(100-20, 150 - 20, "½��", 24, 24, RED);
	puthz(100 - 20, 250 - 20, "�ڱ�", 24, 24, RED);
	puthz(100 - 20, 350 - 20, "����", 24, 24, RED);
	puthz(100 - 20, 450 - 20, "����", 24, 24, RED);
	puthz(550, 400, "�˳�", 24, 24, RED);
	puthz(100 - 20, 50 - 20, "��ر��ֽ���", 24, 24, RED);
}
