/********************************************************
FileName:menu.c
Author:
Date:2019-8-25
Version:1
Description����ģ��֧����Ϸ�Ľ�����ʾ���ܣ�����ģ�飬����drawģ�顢kboardģ���mouseģ�飬֧��gameģ��
FunctionList:

History��
	Hong Jiahao 2019.8.19 �����ļ�
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
	char name[10];//�û���
	char password[10];//����
	char money[10];
	char phone[13];
	char truename[10];
	char card[5];
};
#endif 