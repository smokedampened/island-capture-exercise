/*************************************************
FileName:twopeople.h
Author :
Main author :
Description����ģ��Ϊ˫����Ϸģ�飬����ģ�飬����timerģ��, renewģ�飬processģ��, computerģ��
FunctionList��
1 void resultamy(struct island ild[]);
2.void resultat(struct island ild[]);
3.int hurt1(struct island ild[], int n);
4.int hurt2(struct island ild[], int n);
********************************************************/
#ifndef __TWOPEOP__
#define __TWOPEOP__
void g_game_(void);
void game_(struct island ild[], int round);
int menu_();
void transfer_(struct island* pt1, struct island* pt2, int x, int y);
void check_(struct island* pt);
void applyarmy_(struct island* pt, struct island ild[]);
int timer_( int round);
#endif
