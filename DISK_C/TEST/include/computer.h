/********************************************************
FileName:computer.c
Author:
Main author :
Description����ģ��Ϊ����ģ�飬һ��ģ�飬�ṩ��ͬ�Ѷ������˻�
FunctionList��
	1.void easy(struct island ild[],int round)
	2.void middle(struct island ild[], int round)
	3.void difficult(struct island ild[], int round)
	4.void more_com(struct island ild[], int round)
	5.void move(struct island ild[], int num_amy, int num_at, int ship, int supply, int x, int y)
	6.int  com_judge(struct island ild[], int num_amy, int ship, int num_at, int supply,int x)
********************************************************/
#ifndef __COMPUTER__
#define __COMPUTER__
void easy(struct island ild[], int round);
void middle(struct island ild[], int round);
void difficult(struct island ild[], int round);
void move(struct island ild[], int num_amy, int num_at, int ship, int supply, int x, int y);
int com_judge(struct island ild[], int num_amy, int ship, int num_at, int supply, int x);
void more_com(struct island ild[], int round);
#endif

