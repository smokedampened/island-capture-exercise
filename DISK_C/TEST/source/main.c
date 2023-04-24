/********************************************************
FileName:menu.c
Author:HJW
Date:2019-8-25
Version:1
Description：该模块支持游戏的界面显示功能，三级模块，调用draw模块、kboard模块和mouse模块，支持game模块
FunctionList:

History：
	Hong Jiahao 2019.8.19 建立文件
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
Function：调控中心
Input：
	NONE
Author:
	HJW
Output：0
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
			case 0://初始登录界面
				page = p1(&user);
				break;
			case 1:
				page = p0();
				break;
			case 2://注册页面
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
Function：欢迎中心
Input：
	NONE
Author:
	GRH
Output：0
*************************************************/
int p0()
{
	clrmous(MouseX, MouseY);
	putbmp(50, 1, "database\\huanyin.bmp");
	puthz(250, 400, "开始游戏", 24, 26, RED);
	while (1)
	{
		newmouse(&MouseX, &MouseY, &press);
		if (mouse_press(250, 400, 300 + 100, 400 + 50) == 1)
		{
			return 0;
		}
	}
}