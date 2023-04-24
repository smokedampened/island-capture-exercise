/********************************************************
FileName:game.c
Author:
Main author :
Description����ģ��Ϊ��Ϸ�ĺ��Ĺ���ģ�飬��ģ�飬����transferģ��,timerģ��,renewģ�飬processģ��,computerģ��
FunctionList��
	1.void g_game(void)
	2.int game(struct island ild[],int com);
	3.void check(struct island* pt);
	4.int transfer(struct island* pt1, struct island* pt2,int limit)
	5.int timer(struct island ild[], int round,int com)
********************************************************/
#ifndef __GAME__
#define __GAME__
int game(struct island ild[],int com);
void g_game(void);
int transfer(struct island* pt1, struct island* pt2,int limit,int x1,int y1, int x2, int y2);
void applyarmy(struct island* pt, struct island ild[]);
void check(struct island* pt);
int timer(struct island ild[], int round,int com);
int winlose(struct island ild[]);
int g_win();
int findx(int xx);
int findy(int yy);
#endif

