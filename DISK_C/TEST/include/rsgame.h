/********************************************************
FileName:rsgame.h
Author:
Main author :
Description：该模块为结算模块，一级模块，在每次回合结束时进行结算相关数据
FunctionList：
	1 void resultamy(struct island ild[]);
	2.void resultat(struct island ild[]);
	3.int hurt1(struct island ild[], int n);
	4.int hurt2(struct island ild[], int n);
********************************************************/
#ifndef _RSGAME__
#define _RSGAME__
void resultamy(struct island ild[]);
void resultat(struct island ild[]);
int hurt1(struct island ild[], int n);
int hurt2(struct island ild[], int n);
#endif