/********************************************************
FileName:rsgame.c
Author:
Main author :
Description：该模块为结算模块，一级模块，在每次回合结束时进行结算相关数据
FunctionList：
	1 void resultamy(struct island ild[]);
	2.void resultat(struct island ild[]);
	3.int hurt1(struct island ild[], int n);
	4.int hurt2(struct island ild[], int n);
********************************************************/
#include"structer.h"
#include"normal.h"
#include"rsgame.h"
/*************************************************
Function：存入步兵伤害函数
Input：
	1.struct island * pt1
Author:HJW
Output：
	无
*************************************************/
void resultamy(struct island ild[])
{
	int i;
	int hurt_1, hurt_2;
	for ( i = 0; i < 11; i++)
	{
		 hurt_1 = 0;
		 hurt_2 = 0;
		if (ild[i].id1 = 1)
		{
			hurt_1 = hurt1(ild, i + 1);
			hurt_2 = hurt2(ild, i + 1) * ild[i].sp.defes;
		}
		else
		{
			hurt_1 = hurt1(ild, i + 1) * ild[i].sp.defes;
			hurt_2 = hurt2(ild, i + 1);
		}

		if (ild[i].id2 == 2 || ild[i].id2 == 3)
		{
			if (hurt_1 < ild[i].amy2.num)
			{
				ild[i].amy2.num -= hurt_1;
			}
			else if (hurt_1 < (ild[i].at2.num + ild[i].amy2.num))
			{
				ild[i].at2.num -= (hurt_1 - ild[i].amy2.num);
				ild[i].amy2.num = 0;
			}
			else
			{
				ild[i].at2.num = 0;
				ild[i].amy2.num = 0;
				ild[i].bt2.num = 0;
			}
		}

		if (ild[i].id2 == 1 || ild[i].id2 == 3)
		{
			if (hurt_2 < ild[i].amy1.num)
			{
				ild[i].amy1.num -= hurt_2;
			}
			else if (hurt_2 < (ild[i].at1.num + ild[i].amy1.num))
			{
				ild[i].at1.num -= (hurt_2 - ild[i].amy1.num);
				ild[i].amy1.num = 0;
			}
			else
			{
				ild[i].at1.num = 0;
				ild[i].amy1.num = 0;
				ild[i].bt1.num = 0;
			}
		}
	}
}
/*************************************************
Function：存入炮兵伤害函数
Input：
	1.struct island * pt1
Author:HJW
Output：
	无
*************************************************/
void resultat(struct island ild[])
{
	int i;
	int hurtx, hurty;
	for ( i = 0; i < 11; i++)
	{

		if (ild[i].id2 == 3)
		{
			hurtx = 0;
			hurty = 0;
			if (ild[i].id1 = 1)
			{
				hurtx = (2 * ild[i].amy1.num + ild[i].at1.num);
				hurty = (2 * ild[i].amy2.num + ild[i].at2.num) * ild[i].sp.defes;
			}
			else
			{
				hurtx = (2 * ild[i].amy1.num + ild[i].at1.num) * ild[i].sp.defes;
				hurty = (2 * ild[i].amy2.num + ild[i].at2.num);
			}


			if (hurtx >= hurty)
			{
				ild[i].bt2.num = 0;
				ild[i].at2.num = 0;
				ild[i].amy2.num = 0;

				if (hurty < ild[i].amy1.num)
				{
					ild[i].amy1.num -= hurty;
				}
				else if (hurty < ild[i].at1.num + ild[i].amy1.num)
				{
					ild[i].at1.num -= (hurty - ild[i].amy1.num);
					ild[i].amy1.num = 0;
				}
				else
				{
					ild[i].amy1.num = hurty - ild[i].bt1.num - 2 * ild[i].at1.num;
				}
			}

			else
			{
				ild[i].bt1.num = 0;
				ild[i].at1.num = 0;
				ild[i].amy1.num = 0;

				if (hurtx < ild[i].amy2.num)
				{
					ild[i].amy2.num -= hurtx;
				}
				else if (hurtx < ild[i].amy2.num + ild[i].at2.num)
				{
					ild[i].at2.num -= (hurtx - ild[i].amy2.num);
					ild[i].amy2.num = 0;
				}
				else
				{
					ild[i].bt2.num = 0;
					ild[i].at2.num = 0;
					ild[i].amy2.num = 0;
				}
			}
		}
	}
}
/*************************************************
Function：存入玩家一对所有岛的无差别伤害伤害
Input：
	1.struct island * pt1
Author:HJW
Output：
	无
*************************************************/
int hurt1(struct island ild[], int n)
{
	int i = 0;
	int hurt = 0;

	for (i = 0; i < 11; i++)
	{
		if (judge(i + 1, n) == 1 && (ild[n - 1].id2 == 2 || ild[n - 1].id2 == 3) && (ild[i].id2 == 1 || ild[i].id2 == 3))
		{
			hurt += ((ild[i].at1.num) * (ild[i].at1.atk));
		}
	}
	return hurt;
}

/*************************************************
Function：存入玩家二对所有岛的无差别伤害伤害
Input：
	1.struct island * pt1
Author:HJW
Output：
	无
*************************************************/
int hurt2(struct island ild[], int n)
{
	int i = 0;
	int hurt = 0;

	for (i = 0; i < 11; i++)
	{
		if (judge(i + 1, n) == 1 && (ild[n - 1].id2 == 1 || ild[n - 1].id2 == 3) && (ild[i].id2 == 2 || ild[i].id2 == 3))
		{
			hurt += (ild[i].at2.num) * (ild[i].at2.atk);
		}
	}
	return hurt;
}