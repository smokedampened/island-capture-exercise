/********************************************************
FileName:progress.h
Author:
Main author :
Description：该模块为游戏内调节模块，二级模块，为游戏执行提供各种重要功能，调用computer模块，renew模块，rsgame模块
FunctionList：
	1 void ownership1(struct island ild[])
	2.void ownership2(struct island ild[])
	3.int inputposin(int x1, int y1)
	4.int ild_select()
	5.void rebuit(struct island* pt)
	6.int judge(int a, int b)
********************************************************/
#ifndef __PROCESS__
#define __PROCESS__
void ownership1(struct island ild[]);
void ownership2(struct island ild[]);
int inputposin(int x1, int y1);
int ild_select(void);
void rebuit(struct island* pt);
int judge(int a, int b);
int timer_(struct island ild[], int round);
#endif