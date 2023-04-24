/*************************************************
FileName:page3.h
Author :
Main author :
Description：该模块为登入模块
FunctionList：
1.int p3(void);
2.void page3_screen(void);
3.void inputname(struct U *user, int x1, int y1);
4.void inputpassword(struct U *user, int x1, int y1);
5.void inputpassword1(char *p, int x1, int y1);
6.void inputphone(struct U *user, int x1, int y1);
7.void bright(int x1, int y1, int x2, int y2, int bkcolor);
8.int check_register(struct U *getdata2, char *cp);
9.int existence(struct U *user);
10.void intofile(struct U *user);
11.void page3light(int x1, int y1, char *s);
12.void page3recover(int x1, int y1, char *s);
********************************************************/


/*****************************************
page3.c
COPYRIGHT: 	chen tianyi
FUNCTION:   注册功能
******************************************/
#include"normal.h"
#include"page3.h"
/*********************************************
FUNCTION:p3
DESCRIPTION:用户注册
PARAMETERS:void
RETURN:page
***********************************************/
int p3(void)
{
	int page = 2;
	int mouse = 0;
	int flag = 0;
	int flag1 = 0;
	int flag2 = 0;
	char checkpw[10];
	struct U *user = (struct U *)malloc(sizeof(struct U));
	strcpy(user->name,"\0");
	strcpy(user->password,"\0");
	strcpy(user->money, "0");
	strcpy(user->phone, "\0");
	strcpy(checkpw,"\0");
	clrmous(MouseX,MouseY);
	delay(100);
	page3_screen();
	while(page == 2)
	{
		newmouse(&MouseX,&MouseY,&press);
		while(1)
		{
			if (MouseX > 280 && MouseY > 259 + 40 && MouseX < 348 && MouseY < 293 + 40)
			{
				mouse = 1;
				break;
			}
			else
			{
				mouse = 0;
				break;
			}
		}
		if (mouse_press(178, 75, 178 + 281, 75 + 22) == 1)
		{
			inputname(user, 178, 75);
		}
		else if (mouse_press(178, 139, 178 + 281, 139 + 22) == 1)
		{
			inputpassword(user, 178, 139);
		}
		else if (mouse_press(178, 203, 178 + 281, 203 + 22) == 1)
		{
			inputpassword1(checkpw, 178, 203);
		}
		else if (mouse_press(178, 267, 178 + 281, 267 + 22) == 1)
		{
			inputphone(user, 178, 267);
		}
		else if (mouse_press(280, 259 + 40, 348, 293 + 40) == 1)
		{
			flag1 = check_register(user, checkpw);
			if(flag1==3)
			{
				flag2 = existence(user);
			}
			if (flag1 == 3 && flag2 == 1)
			{
				puthz(270, 320 + 40, "注册成功", 24, 25, LIGHTBLUE);
				intofile(user);
				delay(1000);
				page = 0;
			}
		}
		else if (mouse_press(280, 259 + 40, 348, 293 + 40) == 2)
		{
			if (flag == 0)
			{
				page3light(280, 259 + 40, "注册");
				flag = 1;
			}
			continue;
		}
		else if(mouse_press(20,5,40,25) == 1)
		{ 
			page = 0;
		}
		else if(mouse_press(600,5,620,25) == 1)
		{
			page = CLOSE;
		}
		if (mouse == 0)
		{
			if (flag == 1)
			{
				page3recover(280, 259 + 40, "注册");
				flag = 0;
			}
		}
	}
    return page;
}
/*********************************************
FUNCTION:inputname
DESCRIPTION:输入用户名
PARAMETERS:struct U *user, int x1, int y1
RETURN:void
***********************************************/
void inputname(struct U *user, int x1, int y1)
{
	int i = 0;
	char t;
	char a[2];
	strcpy(user->name,"\0");
	clrmous(MouseX, MouseY);
	setfillstyle(SOLID_FILL, LIGHTGRAY);
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	bright(x1, y1, x1 + 281, y1 + 22, LIGHTGRAY);
	setcolor(BLUE);
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);
	settextjustify(LEFT_TEXT, TOP_TEXT);
	
	while (1)
	{
		t = bioskey(0);
		if (i < 10)
		{
			if (t != '\n'
				&& t != '\r'
				&& t != ' ')
			{
				if (t != '\b')
				{
					user->name[i] = t;
					a[0] = t;
					a[1] = '\0';
					user->name[i + 1] = '\0';
					outtextxy(2 + x1 + i * 10, y1 - 2, a);
					i++;
				}
				else if (t == '\b' && i > 0)
				{
					bar(x1 + i * 10 - 8, y1 , x1 + i * 10 + 4, y1 + 22);
					i--;
					user->name[i] = '\0';
				}
			}
			else
			{
				setfillstyle(SOLID_FILL, LIGHTGRAY);
				break;
			}
		}
		else if (i >= 10)
		{
			if (t != '\n'
				&& t != '\r'
				&& t != ' '
				&& t != 033)//Esc
			{
				if (t == '\b' && i > 0)
				{
					bar(x1 + i * 10 - 8, y1 , x1 + i * 10 + 4, y1 + 22);
					i--;
					user->name[i] = '\0';
				}
			}
			else
			{
				setfillstyle(SOLID_FILL, LIGHTGRAY);
				break;
			}
		}
	}
	bright(x1, y1, x1 + 281, y1 + 22, WHITE);
	outtextxy(x1 + 2, y1 - 2, user->name);
}
/*********************************************
FUNCTION:inputpassword
DESCRIPTION:输入密码
PARAMETERS:struct U *user, int x1, int y1
RETURN:void
***********************************************/
void inputpassword(struct U *user, int x1, int y1)
{
	int i = 0;
	char t;
	char a[2];
	strcpy(user->password,"\0");
	clrmous(MouseX, MouseY);
	setfillstyle(SOLID_FILL, LIGHTGRAY);
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	bright(x1, y1, x1 + 281, y1 + 22, LIGHTGRAY);
	setcolor(BLUE);
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2); 
	settextjustify(LEFT_TEXT, TOP_TEXT);
	
	while (1)
	{
		t = bioskey(0);
		if (i < 10)
		{
			if (t != '\n'
				&& t != '\r'
				&& t != ' ')
			{
				if (t != '\b')
				{
					user->password[i] = t;
					a[0] = t;
					a[1] = '\0';
					user->password[i + 1] = '\0';
					outtextxy(2 + x1 + i * 10, y1 - 2, a);
					i++;
				}
				else if (t == '\b' && i > 0)
				{
					bar(x1 + i * 10 - 8, y1 , x1 + i * 10 + 4, y1 + 22);
					i--;
					user->password[i] = '\0';
				}
			}
			else
			{
				setfillstyle(SOLID_FILL, LIGHTGRAY);
				break;
			}
		}
		else if (i >= 10)
		{
			if (t != '\n'
				&& t != '\r'
				&& t != ' ')
			{
				if (t == '\b' && i > 0)
				{
					bar(x1 + i * 10 - 8, y1 , x1 + i * 10 + 4, y1 + 22);
					i--;
					user->password[i] = '\0';
				}
			}
			else
			{
				setfillstyle(SOLID_FILL, LIGHTGRAY);
				break;
			}
		}
	}
	bright(x1, y1, x1 + 281, y1 + 22, WHITE);
	outtextxy(x1 + 2, y1 - 2, user->password);
}

/*********************************************
FUNCTION:inputpassword1
DESCRIPTION:输入确认密码
PARAMETERS:struct U *user, int x1, int y1
RETURN:void
***********************************************/
void inputpassword1(char *p, int x1, int y1)
{
	int i = 0;
	char t;
	char a[2];
	strcpy(p,"\0");
	clrmous(MouseX, MouseY);
	setfillstyle(SOLID_FILL, LIGHTGRAY);
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	bright(x1, y1, x1 + 281, y1 + 22, LIGHTGRAY);
	setcolor(BLUE);
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);
	settextjustify(LEFT_TEXT, TOP_TEXT);
	
	while (1)
	{
		t = bioskey(0);
		if (i < 10)
		{
			if (t != '\n'
				&& t != '\r'
				&& t != ' ')
			{
				if (t != '\b')
				{
					p[i] = t;
					a[0] = t;
					a[1] = '\0';
					p[i + 1] = '\0';
					outtextxy(2 + x1 + i * 10, y1 - 2, a);
					i++;
				}
				else if (t == '\b' && i > 0)
				{
					bar(x1 + i * 10 - 8, y1 , x1 + i * 10 + 4, y1 + 22);
					i--;
					p[i] = '\0';
				}
			}
			else
			{
				setfillstyle(SOLID_FILL, LIGHTGRAY);
				break;
			}
		}
		else if (i >= 10)
		{
			if (t != '\n'
				&& t != '\r'
				&& t != ' '
				&& t != 033)
			{
				if (t == '\b' && i > 0)
				{
					bar(x1 + i * 10 - 8, y1 , x1 + i * 10 + 4, y1 + 22);
					i--;
					p[i] = '\0';
				}
			}
			else
			{
				setfillstyle(SOLID_FILL, LIGHTGRAY);
				break;
			}
		}
	}
	bright(x1, y1, x1 + 281, y1 + 22, WHITE);
	outtextxy(x1 + 2, y1 - 2, p);
}

/*********************************************
FUNCTION:inputphone
DESCRIPTION:输入手机号
PARAMETERS:struct U *user, int x1, int y1
RETURN:void
***********************************************/
void inputphone(struct U *user, int x1, int y1)
{
	int i = 0;
	char t;
	char a[2];
	strcpy(user->phone,"\0");
	clrmous(MouseX, MouseY);
	setfillstyle(SOLID_FILL, LIGHTGRAY);
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	bright(x1, y1, x1 + 281, y1 + 22, LIGHTGRAY);
	setcolor(BLUE);
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);
	settextjustify(LEFT_TEXT, TOP_TEXT);
	
	while (1)
	{
		t = bioskey(0);
		if (i < 11)
		{
			if (t != '\n'
				&& t != '\r'
				&& t != ' ')
			{
				if (t != '\b')
				{
					user->phone[i] = t;
					a[0] = t;
					a[1] = '\0';
					user->phone[i + 1] = '\0';
					outtextxy(2 + x1 + i * 10, y1 - 2, a);
					i++;
				}
				else if (t == '\b' && i > 0)
				{
					bar(x1 + i * 10 - 8, y1 , x1 + i * 10 + 4, y1 + 22);
					i--;
					user->phone[i] = '\0';
				}
			}
			else
			{
				setfillstyle(SOLID_FILL, LIGHTGRAY);
				break;
			}
		}
		else if (i >= 11)
		{
			if (t != '\n'
				&& t != '\r'
				&& t != ' '
				&& t != 033)//Esc
			{
				if (t == '\b' && i > 0)
				{
					bar(x1 + i * 10 - 8, y1 , x1 + i * 10 + 4, y1 + 22);
					i--;
					user->phone[i] = '\0';
				}
			}
			else
			{
				setfillstyle(SOLID_FILL, LIGHTGRAY);
				break;
			}
		}
	}
	bright(x1, y1, x1 + 281, y1 + 22, WHITE);
	outtextxy(x1 + 2, y1 - 2, user->phone);
}

/*********************************************
FUNCTION:check_register
DESCRIPTION:检验各项数据是否输入正确
PARAMETERS:struct U *user, char *cp
RETURN:t
***********************************************/
int check_register(struct U *user, char *cp)
{
	int t = 0;
	int length, i;
	struct U *a1;

	if (strcmp(user->name, "\0") == 0)
	{
		puthz(450, 282 + 40, "用户名未输入", 16, 16, LIGHTBLUE);
		delay(1000);
		setfillstyle(SOLID_FILL, LIGHTCYAN);
		bar(450, 280 + 40, 650, 300 + 40);
		return 0;
	}

	else
	{
        t++;
	}
	
	if (strcmp(user->password, "\0") == 0)
	{
		puthz(450, 282 + 40, "密码未输入", 16, 16, LIGHTBLUE);
		delay(1000);
		setfillstyle(SOLID_FILL, LIGHTCYAN);
		bar(450, 280 + 40, 650, 300 + 40);
		return 0;
	}

	else
	{
        t++;
	}

	if (strcmp(cp, user->password) != 0)
	{
		puthz(450, 282 + 40, "密码不一致", 16, 16, LIGHTBLUE);
		delay(1000);
		setfillstyle(SOLID_FILL, LIGHTCYAN);
		bar(450, 280 + 40, 650, 300 + 40);
		return 0;
	}
	
	else
	{
		t++;
	}

	for (i = 0; i < 11; i++)
	{
		if (user->phone[i] > '9' || user->phone[i] < '0')
		{
			puthz(450, 282 + 40, "输入正确手机号", 16, 16, LIGHTBLUE);
			delay(1000);
			setfillstyle(SOLID_FILL, LIGHTCYAN);
			bar(450, 280 + 40, 650, 300 + 40);
			return 0;
		}
	}

	return t;
}

/*********************************************
FUNCTION:existence
DESCRIPTION:检验用户是否存在
PARAMETERS:struct U *user
RETURN:0/1
***********************************************/
int existence(struct U *user)
{
	FILE *fp = NULL;
	int length, i;
	struct U *u;

	if ((fp = fopen("database\\user.dat", "rb+")) == NULL)
	{
		outtextxy(320, 300, "file cannot be opened");
		delay(1000);
		exit(1);
	}

	fseek(fp, 0, 2);
	length = ftell(fp) / sizeof(struct U);
	
	for (i = 0; i < length; i++)
	{
		if ((u = (struct U*)malloc(sizeof(struct U))) == NULL)
		{
			printf("no enough memory");
			exit(1);
		}
		fseek(fp, i * sizeof(struct U), SEEK_SET);
		fread(u, sizeof(struct U), 1, fp);

		if (strcmp(u->name, user->name) == 0)
		{
			puthz(270, 320 + 40, "用户存在", 24, 24, LIGHTBLUE);
			delay(1500);
			setfillstyle(1, LIGHTCYAN);
			bar(260, 320 + 40, 370, 350 + 40);
			if (u != NULL)
			{
				free(u);
				u = NULL;
			}
			if (fclose(fp) != 0)
			{
				printf("\n 1 cannot close datatabase.");
				delay(3000);
				exit(1);
			}
			return 0;
		}

		free(u);
		u = NULL;
	}

	if (fclose(fp) != 0)
	{
		printf("\n 2 cannot close datatabase.");
		delay(3000);
		exit(1);
	}

	return 1;
}

/*********************************************
FUNCTION:intofile
DESCRIPTION:注册信息写入文件
PARAMETERS:struct U *user
RETURN:void
***********************************************/
void intofile(struct U *user)
{
	FILE *fp = NULL;

	if ((fp = fopen("database\\user.dat", "rb+")) == NULL)
	{
		printf("file cannot be opened222\n");
		exit(1);
	}
	
	fseek(fp, 0, SEEK_END); 
	fwrite(user, sizeof(struct U), 1, fp);

	if (user != NULL)
	{
		free(user);
		user = NULL;
	}

	if (fclose(fp) != 0)
	{
		printf("\n cannot close datatabase.");
		delay(3000);
		exit(1);
	}
}

/*********************************************
FUNCTION:bright
DESCRIPTION:点亮/恢复输入框
PARAMETERS:int x1,int y1,int x2,int y2,int bkcolor
RETURN:void
***********************************************/
void bright(int x1,int y1,int x2,int y2,int bkcolor)
{
	clrmous(MouseX, MouseY);
	setfillstyle(1, bkcolor);
	bar(x1, y1, x2, y2);
}

/*********************************************
FUNCTION:page3light
DESCRIPTION:按键亮框
PARAMETERS:int x1, int y1, char *s
RETURN:void
***********************************************/
void page3light(int x1, int y1, char *s)
{
	clrmous(MouseX, MouseY);
	setfillstyle(SOLID_FILL, BLUE);
	bar(x1, y1, x1 + 68, y1 + 34);
	puthz(x1 + 10, y1 + 5, s, 24, 26, WHITE);
}

/*********************************************
FUNCTION:page3recover
DESCRIPTION:按键恢复
PARAMETERS:int x1, int y1, char *s
RETURN:void
***********************************************/
void page3recover(int x1, int y1, char *s)
{
	clrmous(MouseX, MouseY);
	setfillstyle(SOLID_FILL, WHITE);
	bar(x1, y1, x1 + 68, y1 + 34);
	puthz(x1 + 10, y1 + 5, s, 24, 26, BLUE);
}

/*********************************************
FUNCTION:page3_screen
DESCRIPTION:注册界面
PARAMETERS:void
RETURN:void
***********************************************/
void page3_screen(void)
{
	cleardevice();
	
	setbkcolor(BLUE);

	setfillstyle(SOLID_FILL, WHITE);
	bar(178, 75, 178 + 281, 75 + 22);
	bar(178, 139, 178 + 281, 139 + 22);
	bar(178, 203, 178 + 281, 203 + 22);
	bar(178, 267, 178 + 281, 267 + 22);
	bar(280, 259 + 40, 348, 293 + 40);

	bar(105, 75, 100 + 70, 75 + 22);
	puthz(107,75,"账户",24,26,RED);

	bar(105, 139, 100 + 70, 139 + 22);
	puthz(107,139,"密码",24,26,RED);

	bar(50, 203, 50 + 120, 203 + 22);
	puthz(59,203,"确认密码",24,26,RED);

	bar(105, 267, 100 + 70, 267 + 22);
	puthz(107, 267, "手机", 24, 26, RED);

	puthz(290, 264 + 40, "注册", 24, 26, RED);

	setfillstyle(1, WHITE);
	bar(0, 450, 700, 500);
	
	setcolor(CYAN);
	setlinestyle(0,0,3);
	rectangle(600,5,620,25);
	line(600,5,620,25);
	line(620,5,600,25);

	rectangle(20,5,40,25);
	line(20,15,40,15);
	line(20,15,25,10);
	line(20,15,25,20);

}
