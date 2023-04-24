/*************************************************
FileName:twopeople.h
Author :
Main author :
Description：该模块为双人游戏模块，三级模块，调用timer模块, renew模块，process模块, computer模块
FunctionList：
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
