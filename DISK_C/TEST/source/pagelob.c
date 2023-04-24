/*************************************************
FileName:twopeople.h
Author :
Main author :
Description：该模块为游戏大厅模块，三级模块
FunctionList：
1.int lobby( void);
2.void g_lobby(void);
3.void DrawFlag(void);
********************************************************/
#include"normal.h"
#include"pagelob.h"
#include"page1.h"
#include "page3.h"
/*************************************************
Function：lobby
Description：游戏大厅功能
Input：
	
Output：void
Return：void
*************************************************/
int lobby(void)
{
	int	page = 3;
	
	clrmous(MouseX,MouseY);
	delay(100);
	setfillstyle(0,GREEN);
	g_lobby();   //draw
	while(page==3)
		{
			newmouse(&MouseX,&MouseY,&press);	
			if(mouse_press(600,5,620,25) == 1)
			{
				page = CLOSE;
				break;
			}

            /*返回*/
			else if(mouse_press(20,5,40,25) == 1)
			{
				page = 0;
				break;
			}

            else if(mouse_press(409, 60,409 + 180, 60 + 42) == 1)
		    {
		    	page = 4;
				break;
		    }
            else if(mouse_press(409, 160, 409 + 180, 160 + 42) == 1)
		    {
		    	page = 5;
				break;
		    }
            /*双人对战*/
		    else if(mouse_press(409, 260, 409 + 180, 260 + 42) == 1)
		    {
		    	page = 6;
				break;
		    }
        }
		 return page;
}

/*************************************************
Function：DrawFlag
Description：绘制红旗
Input：
	
Output：void
Return：void
*************************************************/
void DrawFlag(void)
{
		int v[] = {107.2, 104.8, 123.72, 155.48, 80.6, 124.12, 133.8, 124.12, 90.68, 155.48};//五角星
		int d[] = {150,124,142,141,145,148,154,131};
		int e[] = {158,131,170,148,175,145,163,124};
		int f[] = {179,135,182,142,198,141,198,134};
		int g[] = {34,88,96,275,351,286,286,127};
		int h[] = {0,0,40,90,170,430,0,660};//覆盖多余红色
		int c[] = {160,430,30,90,40,90,170,430};

		setfillstyle(1, RED);	//设置填充颜色 
		sector(38, 131, 0, 90, 250, 40);
		ellipse(103, 291, 0, 90, 250, 40);
		fillpoly(4, g);
		line(351 , 286 , 286 , 127 );
		setfillstyle(1, YELLOW);	//设置填充颜色 
		pieslice(107 , 132 , 0, 360, 11);	
		setlinestyle(0, 0, 3);
		fillpoly(5, v);
		fillpoly(4, d);
		fillpoly(4, e);
		fillpoly(4, f);
		setfillstyle(1, BLUE); //设置填充颜色 
		fillpoly(4, h);//覆盖多余红色
		setcolor(BROWN);
		setfillstyle(1, WHITE);
		fillpoly(4, c);
		pieslice(35 , 90 , 0, 360, 5);
}
/*************************************************
Function：lobby
Description：绘制游戏大厅界面，绘制红旗
Input：
	
Output：void
Return：void
*************************************************/
void g_lobby(void)
{
	cleardevice();
	setbkcolor(WHITE);
	setcolor(BLACK);
	DrawFlag();
	puthz(409, 60, "游戏简介", 24, 28, RED);//(x,y,字符,大小，字距，颜色)
	puthz(409, 160, "人机对战", 24, 28, RED);
	puthz(409, 260, "双人对战", 24, 28, RED);

	setcolor(CYAN);
	setlinestyle(0,0,3);
	rectangle(600,5,620,25);
	line(600,5,620,25);
	line(620,5,600,25);

	rectangle(20,5,40,25);
	line(20,15,40,15);
	line(20,15,25,10);
	line(20,15,25,20);
}


