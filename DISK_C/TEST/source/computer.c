/********************************************************
FileName:computer.c
Author:
Main author :
Description：该模块为电脑模块，一级模块，提供不同难度智能人机
FunctionList：
	1.void easy(struct island ild[],int round)
	2.void middle(struct island ild[], int round)
	3.void difficult(struct island ild[], int round)
	4.void more_com(struct island ild[], int round)
	5.void move(struct island ild[], int num_amy, int num_at, int ship, int supply, int x, int y)
	6.int  com_judge(struct island ild[], int num_amy, int ship, int num_at, int supply,int x)
********************************************************/
#include"structer.h"
#include"normal.h"
#include"computer.h"
/*************************************************
Function：简单电脑人机
Input：
	1.struct island ild[]
	2.int round
Author:GRH
Output：1.struct island ild[]
*************************************************/
void easy(struct island ild[],int round)
{
	int num_amy, num_at, ship, supply;
	int x, y;
	if (round > 6)
	{
		round = 6;
	}
	switch (round)
	{
	case(1):
		{
			num_amy = 30;
			num_at = 20;
			ship = 20;
			supply = 10;
			x = 10;
			y = 8;
			move(ild, num_amy, num_at, ship, supply, x, y);
		}break;
	case(2):
		{
			num_amy = 30;
			num_at =20;
			ship = 20;
			supply = 10;
			x = 10;
			y = 7;
			if (com_judge(ild, num_amy, num_at, ship, supply, x))
			{
				num_amy = 20;
				num_at = 20;
				ship = 14;
				supply = 10;
				x = 10;
				y = 7;
				move(ild, num_amy, num_at, ship, supply, x, y);
			}
			else
			{
				move(ild, num_amy, num_at, ship, supply, x, y);
			}
		}break;
	case(3):
		{
			num_amy = 30;
			num_at = 20;
			ship = 20;
			supply =10;
			x = 10;
			y = 9;
			if (com_judge(ild, num_amy, num_at, ship, supply, x))
			{
				num_amy = 20;
				num_at =10;
				ship = 10;
				supply = 0;
				x = 8;
				y = 5;
				if (com_judge(ild, num_amy, num_at, ship, supply, x))
				{
					num_amy = 20;
					num_at = 10;
					ship = 10;
					supply = 0;
					x = 8;
					y = 9;
				}
				else
				{
					move(ild, num_amy, num_at, ship, supply, x, y);
					num_amy = 20;
					num_at = 10;
					ship = 14;
					supply = 10;
					x = 7;
					y = 5;
					if (com_judge(ild, num_amy, num_at, ship, supply, x))
					{
					}
					else
					{
						move(ild, num_amy, num_at, ship, supply, x, y); 
					}
				}
			}
			else
			{
				move(ild, num_amy, num_at, ship, supply, x, y);
				num_amy = 20;
				num_at = 10;
				ship = 10;
				supply = 0;
				x = 8;
				y = 5;
				if (com_judge(ild, num_amy, num_at, ship, supply, x))
				{
				}
				else
				{
					move(ild, num_amy, num_at, ship, supply, x, y); 
				}
			}
		}break;
	case(4):
	{
		num_amy = 30;
		num_at = 20;
		ship = 20;
		supply = 20;
		x = 10;
		y = 8;
		if (com_judge(ild, num_amy, num_at, ship, supply, x))
		{
			num_amy = 20;
			num_at = 20;
			ship = 10;
			supply = 20;
			x = 9;
			y = 6;
			if (com_judge(ild, num_amy, num_at, ship, supply, x))
			{
			}
			else
			{
				move(ild, num_amy, num_at, ship, supply, x, y);
				num_amy = 20;
				num_at = 10;
				ship = 12;
				supply = 10;
				x = 8;
				y = 5;
				if (com_judge(ild, num_amy, num_at, ship, supply, x)){}
				else
				{
					move(ild, num_amy, num_at, ship, supply, x, y); 
				}
			}
		}
		else
		{
			move(ild, num_amy, num_at, ship, supply, x, y);
			num_amy = 20;
			num_at = 20;
			ship = 10;
			supply =10;
			x = 7;
			y = 4;
			if (com_judge(ild, num_amy, num_at, ship, supply, x)){}
			else
			{
				move(ild, num_amy, num_at, ship, supply, x, y); 
			}
		}
	}break;
	case(5):
		{
			x = 4;
			y = 1;
			num_amy = (ild[x].amy2.num);
			num_at = (ild[x].at2.num);
			ship = (ild[x].bt2.num);
			supply = (ild[x].sp.num);
			if (com_judge(ild, num_amy, num_at, ship, supply, x))
			{
				move(ild, num_amy, num_at, ship, supply, x, y);
			}
			else
			{
				x = 7;
				y = 4;
				num_amy = (ild[x].amy2.num);
				num_at = (ild[x].at2.num);
				ship = (ild[x].bt2.num);
				supply = (ild[x].sp.num);
				if(com_judge(ild, num_amy, num_at, ship, supply, x))
				{
					move(ild, num_amy, num_at, ship, supply, x, y);
				}
			}
			x = 5;
			y = 2;
			num_amy = (ild[x].amy2.num);
			num_at = (ild[x].at2.num);
			ship = (ild[x].bt2.num);
			supply = (ild[x].sp.num);
			if (com_judge(ild, num_amy, num_at, ship, supply, x))
			{
				move(ild, num_amy, num_at, ship, supply, x, y);
			}
			else
			{
				x = 7;
				y = 4;
				num_amy = (ild[x].amy2.num);
				num_at = (ild[x].at2.num);
				ship = (ild[x].bt2.num);
				supply = (ild[x].sp.num);
				if(com_judge(ild, num_amy, num_at, ship, supply, x))
				{
					move(ild, num_amy, num_at, ship, supply, x, y);
				}
			}
			x = 8;
			y = 5;
			num_amy = (ild[x].amy2.num);
			num_at = (ild[x].at2.num);
			ship = (ild[x].bt2.num);
			supply = (ild[x].sp.num);
			if (com_judge(ild, num_amy, num_at, ship, supply, x))
			{
				move(ild, num_amy, num_at, ship, supply, x, y);
			}
			else
			{
				x = 9;
				y = 6;
				num_amy = (ild[x].amy2.num);
				num_at = (ild[x].at2.num);
				ship = (ild[x].bt2.num);
				supply = (ild[x].sp.num);
				if(com_judge(ild, num_amy, num_at, ship, supply, x))
				{
					move(ild, num_amy, num_at, ship, supply, x, y);
				}
			}
		}break;
	case(6):
	{
		x = 4;
		y = 1;
		num_amy = (ild[x].amy2.num);
		num_at = (ild[x].at2.num);
		ship = (ild[x].bt2.num);
		supply = (ild[x].sp.num);
		if (com_judge(ild, num_amy, num_at, ship, supply, x))
		{
			move(ild, num_amy, num_at, ship, supply, x, y);
		}
		else
		{
			x = 7;
			y = 4;
			num_amy = (ild[x].amy2.num);
			num_at = (ild[x].at2.num);
			ship = (ild[x].bt2.num);
			supply = (ild[x].sp.num);
			if(com_judge(ild, num_amy, num_at, ship, supply, x))
			{
				move(ild, num_amy, num_at, ship, supply, x, y);
			}
			else
			{
				x = 10;
				y = 7;
				num_amy = (ild[x].amy2.num);
				num_at = (ild[x].at2.num);
				ship = (ild[x].bt2.num);
				supply = (ild[x].sp.num);
				if (com_judge(ild, num_amy, num_at, ship, supply, x))
				{
					move(ild, num_amy, num_at, ship, supply, x, y);
				}
			}
		}
		x = 5;
		y = 2;
		num_amy = (ild[x].amy2.num);
		num_at = (ild[x].at2.num);
		ship = (ild[x].bt2.num);
		supply = (ild[x].sp.num);
		if (com_judge(ild, num_amy, num_at, ship, supply, x))
		{
			move(ild, num_amy, num_at, ship, supply, x, y);
		}
		else
		{
			x = 7;
			y = 4;
			num_amy = (ild[x].amy2.num);
			num_at = (ild[x].at2.num);
			ship = (ild[x].bt2.num);
			supply = (ild[x].sp.num);
			if(com_judge(ild, num_amy, num_at, ship, supply, x))
			{
				move(ild, num_amy, num_at, ship, supply, x, y);
			}
			else
			{
				x = 10;
				y = 8;
				num_amy = (ild[x].amy2.num);
				num_at = (ild[x].at2.num);
				ship = (ild[x].bt2.num);
				supply = (ild[x].sp.num);
				if (com_judge(ild, num_amy, num_at, ship, supply, x))
				{
					move(ild, num_amy, num_at, ship, supply, x, y);
				}
			}
		}
		x = 8;
		y = 5;
		num_amy = (ild[x].amy2.num);
		num_at = (ild[x].at2.num);
		ship = (ild[x].bt2.num);
		supply = (ild[x].sp.num);
		if (com_judge(ild, num_amy, num_at, ship, supply, x))
		{
			move(ild, num_amy, num_at, ship, supply, x, y);
		}
		else
		{
			x = 9;
			y = 6;
			num_amy = (ild[x].amy2.num);
			num_at = (ild[x].at2.num);
			ship = (ild[x].bt2.num);
			supply = (ild[x].sp.num);
			if(com_judge(ild, num_amy, num_at, ship, supply, x))
			{
				move(ild, num_amy, num_at, ship, supply, x, y);
			}
			else
			{
				x = 10;
				y = 9;
				num_amy = (ild[x].amy2.num);
				num_at = (ild[x].at2.num);
				ship = (ild[x].bt2.num);
				supply = (ild[x].sp.num);
				if (com_judge(ild, num_amy, num_at, ship, supply, x))
				{
					move(ild, num_amy, num_at, ship, supply, x, y);
				}
			}
		}
	}break;
	}
}
/*************************************************
Function：初等电脑人机
Input：
	1.struct island ild[]
	2.int round
Author:GRH
Output：1.struct island ild[]
*************************************************/
void middle(struct island ild[], int round)
{
	int num_amy, num_at, ship, supply;
	int x, y;
	if (round > 6)
	{
		round = 6;
	}
	switch (round)
	{
	case(1):
	{
		num_amy = 30;
		num_at = 20;
		ship = 20;
		supply = 10;
		x = 10;
		y = 8;
		move(ild, num_amy, num_at, ship, supply, x, y);
	}break;
	case(2):
	{
		num_amy = 30;
		num_at = 20;
		ship = 20;
		supply = 10;
		x = 10;
		y = 7;
		if (com_judge(ild, num_amy, num_at, ship, supply, x))
		{
			num_amy = 20;
			num_at = 20;
			ship = 14;
			supply = 10;
			x = 10;
			y = 7;
			move(ild, num_amy, num_at, ship, supply, x, y);
		}
		else
		{
			move(ild, num_amy, num_at, ship, supply, x, y);
		}
	}break;
	case(3):
	{
		num_amy = 30;
		num_at = 20;
		ship = 20;
		supply = 10;
		x = 10;
		y = 9;
		if (com_judge(ild, num_amy, num_at, ship, supply, x))
		{
			num_amy = 20;
			num_at = 10;
			ship = 10;
			supply = 0;
			x = 8;
			y = 5;
			if (com_judge(ild, num_amy, num_at, ship, supply, x))
			{
				num_amy = 20;
				num_at = 10;
				ship = 10;
				supply = 0;
				x = 8;
				y = 9;
			}
			else
			{
				move(ild, num_amy, num_at, ship, supply, x, y);
				num_amy = 20;
				num_at = 10;
				ship = 14;
				supply = 10;
				x = 7;
				y = 5;
				if (com_judge(ild, num_amy, num_at, ship, supply, x))
				{
				}
				else
				{
					move(ild, num_amy, num_at, ship, supply, x, y);
				}
			}
		}
		else
		{
			move(ild, num_amy, num_at, ship, supply, x, y);
			num_amy = 20;
			num_at = 10;
			ship = 10;
			supply = 0;
			x = 8;
			y = 5;
			if (com_judge(ild, num_amy, num_at, ship, supply, x))
			{
			}
			else
			{
				move(ild, num_amy, num_at, ship, supply, x, y);
			}
		}
	}break;
	case(4):
	{
		num_amy = 30;
		num_at = 20;
		ship = 20;
		supply = 20;
		x = 10;
		y = 8;
		if (com_judge(ild, num_amy, num_at, ship, supply, x))
		{
			num_amy = 20;
			num_at = 20;
			ship = 10;
			supply = 20;
			x = 9;
			y = 6;
			if (com_judge(ild, num_amy, num_at, ship, supply, x))
			{
			}
			else
			{
				move(ild, num_amy, num_at, ship, supply, x, y);
				num_amy = 20;
				num_at = 10;
				ship = 12;
				supply = 10;
				x = 8;
				y = 5;
				if (com_judge(ild, num_amy, num_at, ship, supply, x)) {}
				else
				{
					move(ild, num_amy, num_at, ship, supply, x, y);
				}
			}
		}
		else
		{
			move(ild, num_amy, num_at, ship, supply, x, y);
			num_amy = 20;
			num_at = 20;
			ship = 10;
			supply = 10;
			x = 7;
			y = 4;
			if (com_judge(ild, num_amy, num_at, ship, supply, x)) {}
			else
			{
				move(ild, num_amy, num_at, ship, supply, x, y);
			}
		}
	}break;
	case(5):
	{
		x = 4;
		y = 1;
		num_amy = (ild[x].amy2.num);
		num_at = (ild[x].at2.num);
		ship = (ild[x].bt2.num);
		supply = (ild[x].sp.num);
		if (com_judge(ild, num_amy, num_at, ship, supply, x))
		{
			move(ild, num_amy, num_at, ship, supply, x, y);
		}
		else
		{
			x = 7;
			y = 4;
			num_amy = (ild[x].amy2.num);
			num_at = (ild[x].at2.num);
			ship = (ild[x].bt2.num);
			supply = (ild[x].sp.num);
			if (com_judge(ild, num_amy, num_at, ship, supply, x))
			{
				move(ild, num_amy, num_at, ship, supply, x, y);
			}
		}
		x = 5;
		y = 2;
		num_amy = (ild[x].amy2.num);
		num_at = (ild[x].at2.num);
		ship = (ild[x].bt2.num);
		supply = (ild[x].sp.num);
		if (com_judge(ild, num_amy, num_at, ship, supply, x))
		{
			move(ild, num_amy, num_at, ship, supply, x, y);
		}
		else
		{
			x = 7;
			y = 4;
			num_amy = (ild[x].amy2.num);
			num_at = (ild[x].at2.num);
			ship = (ild[x].bt2.num);
			supply = (ild[x].sp.num);
			if (com_judge(ild, num_amy, num_at, ship, supply, x))
			{
				move(ild, num_amy, num_at, ship, supply, x, y);
			}
		}
		x = 8;
		y = 5;
		num_amy = (ild[x].amy2.num);
		num_at = (ild[x].at2.num);
		ship = (ild[x].bt2.num);
		supply = (ild[x].sp.num);
		if (com_judge(ild, num_amy, num_at, ship, supply, x))
		{
			move(ild, num_amy, num_at, ship, supply, x, y);
		}
		else
		{
			x = 9;
			y = 6;
			num_amy = (ild[x].amy2.num);
			num_at = (ild[x].at2.num);
			ship = (ild[x].bt2.num);
			supply = (ild[x].sp.num);
			if (com_judge(ild, num_amy, num_at, ship, supply, x))
			{
				move(ild, num_amy, num_at, ship, supply, x, y);
			}
		}
	}break;
	case(6):
	{
		x = 4;
		y = 1;
		num_amy = (ild[x].amy2.num);
		num_at = (ild[x].at2.num);
		ship = (ild[x].bt2.num);
		supply = (ild[x].sp.num);
		if (com_judge(ild, num_amy, num_at, ship, supply, x))
		{
			move(ild, num_amy, num_at, ship, supply, x, y);
		}
		else
		{
			x = 7;
			y = 4;
			num_amy = (ild[x].amy2.num);
			num_at = (ild[x].at2.num);
			ship = (ild[x].bt2.num);
			supply = (ild[x].sp.num);
			if (com_judge(ild, num_amy, num_at, ship, supply, x))
			{
				move(ild, num_amy, num_at, ship, supply, x, y);
			}
			else
			{
				x = 10;
				y = 7;
				num_amy = (ild[x].amy2.num);
				num_at = (ild[x].at2.num);
				ship = (ild[x].bt2.num);
				supply = (ild[x].sp.num);
				if (com_judge(ild, num_amy, num_at, ship, supply, x))
				{
					move(ild, num_amy, num_at, ship, supply, x, y);
				}
			}
		}
		x = 5;
		y = 2;
		num_amy = (ild[x].amy2.num);
		num_at = (ild[x].at2.num);
		ship = (ild[x].bt2.num);
		supply = (ild[x].sp.num);
		if (com_judge(ild, num_amy, num_at, ship, supply, x))
		{
			move(ild, num_amy, num_at, ship, supply, x, y);
		}
		else
		{
			x = 7;
			y = 4;
			num_amy = (ild[x].amy2.num);
			num_at = (ild[x].at2.num);
			ship = (ild[x].bt2.num);
			supply = (ild[x].sp.num);
			if (com_judge(ild, num_amy, num_at, ship, supply, x))
			{
				move(ild, num_amy, num_at, ship, supply, x, y);
			}
			else
			{
				x = 10;
				y = 8;
				num_amy = (ild[x].amy2.num);
				num_at = (ild[x].at2.num);
				ship = (ild[x].bt2.num);
				supply = (ild[x].sp.num);
				if (com_judge(ild, num_amy, num_at, ship, supply, x))
				{
					move(ild, num_amy, num_at, ship, supply, x, y);
				}
			}
		}
		x = 8;
		y = 5;
		num_amy = (ild[x].amy2.num);
		num_at = (ild[x].at2.num);
		ship = (ild[x].bt2.num);
		supply = (ild[x].sp.num);
		if (com_judge(ild, num_amy, num_at, ship, supply, x))
		{
			move(ild, num_amy, num_at, ship, supply, x, y);
		}
		else
		{
			x = 9;
			y = 6;
			num_amy = (ild[x].amy2.num);
			num_at = (ild[x].at2.num);
			ship = (ild[x].bt2.num);
			supply = (ild[x].sp.num);
			if (com_judge(ild, num_amy, num_at, ship, supply, x))
			{
				move(ild, num_amy, num_at, ship, supply, x, y);
			}
			else
			{
				x = 10;
				y = 9;
				num_amy = (ild[x].amy2.num);
				num_at = (ild[x].at2.num);
				ship = (ild[x].bt2.num);
				supply = (ild[x].sp.num);
				if (com_judge(ild, num_amy, num_at, ship, supply, x))
				{
					move(ild, num_amy, num_at, ship, supply, x, y);
				}
			}
		}
	}break;
	}
}
/*************************************************
Function：困难电脑人机
Input：
	1.struct island ild[]
	2.int round
Author:GRH
Output：1.struct island ild[]
*************************************************/
void difficult(struct island ild[], int round)
{
	int num_amy, num_at, ship, supply;
	int x, y;
	if (round > 5)
	{
		round = 5;
	}
	switch (round)
	{
	case(1):
	{
		x = 10;
		y = 8;
		num_amy = (ild[x].amy2.num);
		num_at = (ild[x].at2.num);
		ship = (ild[x].bt2.num);
		supply = (ild[x].sp.num);
		move(ild, num_amy, num_at, ship, supply, x, y);
	}break;
	case(2):
	{
		x = 8;
		y = 5;
		num_amy = (ild[x].amy2.num);
		num_at = (ild[x].at2.num);
		ship = (ild[x].bt2.num);
		supply = (ild[x].sp.num);
		move(ild, num_amy, num_at, ship, supply, x, y);
	}break;
	case(3):
	{
		x = 5;
		y = 2;
		num_amy = (ild[x].amy2.num);
		num_at = (ild[x].at2.num);
		ship = (ild[x].bt2.num);
		supply = (ild[x].sp.num);
		move(ild, num_amy, num_at, ship, supply, x, y);
	}break;
	case(4):
	{
		x = 2;
		y = 0;
		num_amy = (ild[x].amy2.num);
		num_at = (ild[x].at2.num);
		ship = (ild[x].bt2.num);
		supply = (ild[x].sp.num);
		move(ild, num_amy, num_at, ship, supply, x, y);
	}break;
	case(5):
	{
		x = 2;
		y = 0;
		num_amy = (ild[x].amy2.num);
		num_at = (ild[x].at2.num);
		ship = (ild[x].bt2.num);
		supply = (ild[x].sp.num);
		if (com_judge(ild, num_amy, num_at, ship, supply, x))
		{
			move(ild, num_amy, num_at, ship, supply, x, y);
		}
		else
		{
			x = 5;
			y = 2;
			num_amy = (ild[x].amy2.num);
			num_at = (ild[x].at2.num);
			ship = (ild[x].bt2.num);
			supply = (ild[x].sp.num);
			if (com_judge(ild, num_amy, num_at, ship, supply, x))
			{
				move(ild, num_amy, num_at, ship, supply, x, y);
			}
			else
			{
				x = 8;
				y = 5;
				num_amy = (ild[x].amy2.num);
				num_at = (ild[x].at2.num);
				ship = (ild[x].bt2.num);
				supply = (ild[x].sp.num);
				if (com_judge(ild, num_amy, num_at, ship, supply, x))
				{
					move(ild, num_amy, num_at, ship, supply, x, y);
				}
				else
				{
					x = 10;
					y = 8;
					num_amy = (ild[x].amy2.num);
					num_at = (ild[x].at2.num);
					ship = (ild[x].bt2.num);
					supply = (ild[x].sp.num);
					if (com_judge(ild, num_amy, num_at, ship, supply, x))
					{
						move(ild, num_amy, num_at, ship, supply, x, y);
					}
				}
			}
		}
	}break;
	}
}
/*************************************************
Function：电脑人机辅助判断函数
Input：
	1.struct island ild[]
	2.int round
Author:GRH
Output：1.struct island ild[]
*************************************************/
void more_com(struct island ild[], int round)
{

	int num_amy, num_at, ship, supply;
	int x, y;
	switch (round)
	{
	case(1):
	{
		num_amy = 0;
		num_at = 0;
		ship = 0;
		supply = 0;
		x = 10;
		y = 8;
		move(ild, num_amy, num_at, ship, supply, x, y);
	}break;
	case(2):
	{
		num_amy = 0;
		num_at = 0;
		ship = 0;
		supply = 0;
		x = 10;
		y = 8;
		move(ild, num_amy, num_at, ship, supply, x, y);
	}break;
	case(3):
	{
		num_amy = 0;
		num_at = 0;
		ship = 0;
		supply = 0;
		x = 10;
		y = 8;
		if (com_judge(ild, num_amy, num_at, ship, supply, x))
		{
			num_amy = 0;
			num_at = 0;
			ship = 0;
			supply = 0;
			x = 10;
			y = 8;
			if (com_judge(ild, num_amy, num_at, ship, supply, x))
			{

			}
			else
			{
				move(ild, num_amy, num_at, ship, supply, x, y);
			}
		}
		else
		{
			move(ild, num_amy, num_at, ship, supply, x, y);
		}
	}break;
	case(4):
	{
		num_amy = 0;
		num_at = 0;
		ship = 0;
		supply = 0;
		x = 10;
		y = 8;
		if (com_judge(ild, num_amy, num_at, ship, supply, x))
		{
			num_amy = 0;
			num_at = 0;
			ship = 0;
			supply = 0;
			x = 10;
			y = 8;
			if (com_judge(ild, num_amy, num_at, ship, supply, x))
			{

			}
			else
			{
				move(ild, num_amy, num_at, ship, supply, x, y);
			}
		}
		else
		{
			move(ild, num_amy, num_at, ship, supply, x, y);
		}
	}break;
	case(5):
	{
		num_amy = 0;
		num_at = 0;
		ship = 0;
		supply = 0;
		x = 10;
		y = 8;
		if (com_judge(ild, num_amy, num_at, ship, supply, x))
		{
			num_amy = 0;
			num_at = 0;
			ship = 0;
			supply = 0;
			x = 10;
			y = 8;
			if (com_judge(ild, num_amy, num_at, ship, supply, x))
			{

			}
			else
			{
				move(ild, num_amy, num_at, ship, supply, x, y);
			}
		}
		else
		{
			move(ild, num_amy, num_at, ship, supply, x, y);
		}
	}break;
	}
}
/*************************************************
Function：电脑人机辅助移动兵力函数
Input：
	1.struct island ild[], 
	2.int num_amy,
	3. int num_at, 
	4.int ship,
	5. int supply,
	6. int x, 
	7. int y
Author:GRH
Output：1.struct island ild[]
*************************************************/
void move(struct island ild[], int num_amy, int num_at, int ship, int supply, int x, int y)
{
	(ild[x].amy2.num) = (ild[x].amy2.num)- num_amy;
	(ild[y].amy2.num) = (ild[y].amy2.num)+num_amy;
	(ild[x].at2.num) = (ild[x].at2.num)-num_at;
	(ild[y].at2.num) = (ild[y].at2.num)+num_at;
	(ild[x].bt2.num) = (ild[x].bt2.num) - ship;
	(ild[y].bt2.num) = (ild[y].bt2.num) + ship;
	(ild[x].sp.num) = (ild[x].sp.num) - supply;
	(ild[y].sp.num) = (ild[y].sp.num) + supply;
}
/*************************************************
Function：电脑人机辅助判断函数
Input：
	1.struct island ild[],
	2.int num_amy,
	3. int num_at,
	4.int ship,
	5. int supply,
	6. int x,
	7. int y
Author:GRH
Output：1.struct island ild[]
*************************************************/
int  com_judge(struct island ild[], int num_amy, int ship, int num_at, int supply,int x)
{
	if (num_amy > (ild[x].amy2.num) || ship > (ild[x].bt2.num) || num_at > (ild[x].at2.num) || supply > (ild[x].sp.num))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}