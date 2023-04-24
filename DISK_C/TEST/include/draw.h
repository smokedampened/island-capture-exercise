/********************************************************
FileName:menu.c
Author:
Date:2019-8-25
Version:1
Description：该模块支持游戏的界面显示功能，三级模块，调用draw模块、kboard模块和mouse模块，支持game模块
FunctionList:

History：
	Hong Jiahao 2019.8.19 建立文件
********************************************************/
#ifndef _drawing_h_
#define _drawing_h_
void draw_mainform();
void button_light(int,int,int,int,int);
void draw_rounded_rectangle(int,int,int,int,int,int);
void draw_icon_account();
void cicle_fill(int,int,int,int);
void draw_button(int ,int ,int ,int ,int );
void draw_bar(int x,int y,int color);
void light_line(int ,int ,int ,int);
void draw_return(int ,int ,int ,int );
void draw_money(int ,int ,int ,int );
void draw_tangle(int ,int ,int ,int ,int);
void draw_logo();
void draw_right(int x,int y,int size,int color);
#endif