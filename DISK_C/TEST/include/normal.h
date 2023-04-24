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
#ifndef _NORMAL_H_
#define _NORMAL_H_
#define CLOSE 999
#define MAX 5
#include<graphics.h>
#include<stdio.h>
#include <string.h>
#include<stdlib.h>
#include<bios.h>
#include<alloc.h>
#include<time.h>
#include<dos.h>
#include<conio.h>
#include "putbmp.h"
#include"mouse.h"
#include"hz.h"
#include"draw.h"
struct U
{
	char name[10];//用户名
	char password[10];//密码
	char money[10];
	char phone[13];
	char truename[10];
	char card[5];
};
#endif 