/********************************************************
FileName:menu.c
Author:HJW
Date:2019-8-25
Version:1
Description����ģ��֧����Ϸ�Ľ�����ʾ���ܣ�����ģ�飬����drawģ�顢kboardģ���mouseģ�飬֧��gameģ��
FunctionList:

History��
	Hong Jiahao 2019.8.19 �����ļ�
********************************************************/
#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include <bios.h>
#include <dos.h>
#include <stdlib.h>
#include <string.h>
#include"structer.h"
#include"draw.h"
#include"normal.h"
#include "page1.h"
#include "page3.h"
#include"choice.h"
#include "gback.h"
#include"pagelob.h"
#include"game.h"
#include"renew.h"
/*************************************************
Function����������
Input��
	NONE
Author:
	HJW
Output��0
*************************************************/
int main()
{	 	
	
	int page = 1;
	int i;
	struct U user;
	
	int gd = VGA, gm = VGAHI;
	struct island ild[11] = { 0 };
	strcpy(user.name,"\0");
	strcpy(user.password,"\0");
	strcpy(user.phone, "\0");

	initgraph(&gd, &gm, "..\\BORLANDC\\BGI");
	mouseinit();
	while(1)
	{
		switch(page)
		{
			case 0://��ʼ��¼����
				page = p1(&user);
				break;
			case 1:
				page = p0();
				break;
			case 2://ע��ҳ��
				page = p3();
				break;
			case 3:
				page = lobby();
				break;
			case 4:
				page = bkgrd();
				break;
			case 5:
				page = choice(ild);
				break;
			case 6:
			{
				begin(&ild[0], &ild[10]);
				page = game(ild,4);
			}
			case CLOSE:
				closegraph();
				delay(100);
				exit(0);
		}
	}
	return 0;
}
/*************************************************
Function����ӭ����
Input��
	NONE
Author:
	GRH
Output��0
*************************************************/
int p0()
{
	clrmous(MouseX, MouseY);
	putbmp(50, 1, "database\\huanyin.bmp");
	puthz(250, 400, "��ʼ��Ϸ", 24, 26, RED);
	while (1)
	{
		newmouse(&MouseX, &MouseY, &press);
		if (mouse_press(250, 400, 300 + 100, 400 + 50) == 1)
		{
			return 0;
		}
	}
}