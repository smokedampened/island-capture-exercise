/*************************************************
FileName:page.h
Author :
Main author :
Description����ģ��Ϊ����ģ��
FunctionList��
1 int p1(struct U *user);
2.void logname(struct U *user, int x1, int y1);
3.void logpassword(struct U *user, int x1, int y1);
4.int check_log(struct U *user);
5.void page1_screen(void);
6.void page1light(int x1, int y1, char *s);
7.void page1recover(int x1, int y1, char *s);
********************************************************/
/*****************************************
page1.c
COPYRIGHT: 	chen tianyi
FUNCTION:   ��¼����
******************************************/
#include "normal.h"
#include "page1.h"
#include "page3.h"
/*********************************************
FUNCTION:p1
DESCRIPTION:�û���¼
PARAMETERS:struct U *user
RETURN:page
***********************************************/
int p1(struct U *user)
{
	int page = 0;
	int flag1 = 0;//����û��Ƿ����
	int mouse = 0;//mouse�ڷ�Χ������1��������0
	int flag = 0;
	clrmous(MouseX,MouseY);
	delay(100);
	page1_screen(); 
	while(page == 0)
	{
		newmouse(&MouseX,&MouseY,&press);

		while(1)//һ����ѭ��
		{
			if (MouseX > 150 && MouseY > 275 && MouseX < 200 && MouseY < 305)
			{
				mouse = 1;
				break;
			}

			else if(MouseX > 230 && MouseY > 275 && MouseX < 280 && MouseY < 305)
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
		/*ע������*/
		 if(mouse_press(180, 165, 180 + 220, 165 + 30) == 1)
		{
			logname(user, 180, 165);
		}

		/*ע������*/
		else if(mouse_press(180, 220, 180 + 220, 220 + 30) == 1)
		{
			logpassword(user, 180, 220);
		}

		/*����û��Ƿ����*/
		else if (mouse_press(230, 275, 280, 305) == 1)
		{
			flag1 = check_log(user);

			if (flag1 == 2)
			{	
				puthz(270, 320, "��¼�ɹ�", 24, 25, WHITE);
				page = 3;
			}
		}

		/*�һ�ע������ѭ��*/
		else if (mouse_press(150, 275, 200, 305) == 2)
		{
			if (flag == 0)
			{
				page1light(150, 275, "ע��");
				flag = 1;
			}
			continue;
		}

		/*�һ���¼����ѭ��*/
		else if (mouse_press(230, 275, 280, 305) == 2)
		{
			if (flag == 0)
			{
				page1light(230, 275, "��¼");
				flag = 2;
			}
			continue;
		}

		else if (mouse_press(150, 275, 200, 305) == 1)
		{
			page = 2;
		}

		else if(mouse_press(600,5,620,25) == 1)
		{
			page = CLOSE;
		}

		if (mouse == 0)
		{
			if (flag == 1)
			{
				page1recover(150, 275, "ע��");
				flag = 0;
			}

			if (flag == 2)
			{
				page1recover(230, 275, "��¼");
				flag = 0;
			}
		}
	}
	return page;
}   
/*********************************************
FUNCTION:page1light
DESCRIPTION:��������
PARAMETERS:int x1,int y1,char*s
RETURN:void
***********************************************/
void page1light(int x1,int y1,char*s)
{
	clrmous(MouseX, MouseY);
	setfillstyle(SOLID_FILL, BLUE);
	bar(x1, y1, x1 + 50, y1 + 30);
	puthz(x1, y1 + 5, s, 24, 24, WHITE);
}
/*********************************************
FUNCTION:page1recover
DESCRIPTION:�����ָ�
PARAMETERS:int x1,int y1,char*s
RETURN:void
***********************************************/
void page1recover(int x1,int y1,char*s)
{
	clrmous(MouseX, MouseY);
	setfillstyle(SOLID_FILL, WHITE);
	bar(x1, y1, x1 + 50, y1 + 30);
	puthz(x1, y1 + 5, s, 24, 24, BLUE);
}
/*********************************************
FUNCTION:logname
DESCRIPTION:�����û���
PARAMETERS:struct U *user, int x1, int y1
RETURN:void
***********************************************/
void logname(struct U *user, int x1, int y1)
{
	int i = 0;
	char t = '\0';
	char a[2] = "\0";
	strcpy(user->name,"\0");
	clrmous(MouseX, MouseY);
	setfillstyle(SOLID_FILL, LIGHTGRAY);
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	bright(x1, y1, x1 + 220, y1 + 30, LIGHTGRAY);
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
				&& t != ' '
				&& t != 033)//Esc
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
	bright(x1, y1, x1 + 220, y1 + 30, WHITE);
	outtextxy(x1 + 2, y1 - 1, user->name);
}
/*********************************************
FUNCTION:logname
DESCRIPTION:��������
PARAMETERS:struct U *user, int x1, int y1
RETURN:void
***********************************************/
void logpassword(struct U *user, int x1, int y1)
{
	int i = 0;
	char t;
	char a[2];
	strcpy(user->password,"\0");
	clrmous(MouseX, MouseY);
	setfillstyle(SOLID_FILL, LIGHTGRAY);
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	bright(x1, y1, x1 + 220, y1 + 30, LIGHTGRAY);
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
				&& t != ' '
				&& t != 033)//Esc
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
				&& t != ' '
				&& t != 033)//Esc
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
	bright(x1, y1, x1 + 220, y1 + 30, WHITE);
	outtextxy(x1 + 2, y1 - 1, user->password);
}
/*********************************************
FUNCTION:check_log
DESCRIPTION:�����û��Ƿ����
PARAMETERS:struct U *user
RETURN:page
***********************************************/
int check_log(struct U *user)
{
	FILE *fp = NULL;
	int length = 0;
	int i = 0;
	int t = 0;
	struct U *u;

	if (strcmp(user->name, "\0") == 0)
	{
		puthz(300, 352, "δ�����û���", 24, 24, WHITE);
	}

	if (strcmp(user->password, "\0") == 0)
	{
		puthz(300, 380, "δ��������", 24, 24, WHITE);
	}
	
	if (strcmp(user->name, "\0") == 0 || strcmp(user->password, "\0") == 0)
	{
		return 0;
	}



	if ((fp = fopen("database\\user.dat", "rb+")) == NULL)
	{
		printf("file cannot be opened\n");
		exit(1);
	}

	fseek(fp, 0, 2);
	length = ftell(fp) / sizeof(struct U);

	for (i = 0; i < length; i++)
	{
		if ((u = (struct U *)malloc(sizeof(struct U))) == NULL)
		{
			printf("no enough memory");
			exit(1);
		}

		fseek(fp, i * sizeof(struct U), SEEK_SET);
		fread(u, sizeof(struct U), 1, fp);

		if (strcmp(u->name, user->name) == 0)
		{
			t++;

			if (strcmp(u->password, user->password) == 0)
			{
				t++;

				if (u != NULL)
				{
					free(u);
					u = NULL;
				}

				if (fclose(fp) != 0)
				{
					printf("\n cannot close datatabase.");
					delay(3000);
					exit(1);
				}

				return t;
			}

			else if(strcmp(u->password, user->password) != 0)
			{
				puthz(300, 436, "�������", 24, 24, WHITE);
				delay(1000);
				setfillstyle(SOLID_FILL, BLUE);
				bar(302, 436, 500, 460);

				
				if (fclose(fp) != 0)
				{
					printf("\n cannot close datatabase.");
					delay(3000);
					exit(1);
				}

				if (u != NULL)
				{
					free(u);
					u = NULL;
					return t;
				}
			}
		}

		free(u);
		u = NULL;
	}

	if (t == 0)
	{	
		puthz(300, 428, "�û�������", 24, 24, WHITE);
		delay(1000);
		setfillstyle(SOLID_FILL, BLUE);
		bar(302, 408, 500, 460);
		return t;
	}

	return t;
}
/*********************************************
FUNCTION:page1_screen
DESCRIPTION:��¼����
PARAMETERS:void
RETURN:void
***********************************************/
void page1_screen(void)
{
	cleardevice();
	putbmp(1, 1, "database\\drbj.bmp");
	setfillstyle(1,WHITE);
	bar(180, 100, 180 + 200, 100 + 40);
	puthz(200, 105, "�û���¼", 32, 36, RED);

	setlinestyle(0, 0, 3);
	setcolor(LIGHTBLUE);
	bar(180, 165, 180 + 220, 165 + 30);
	bar(123, 165, 123 + 50, 165 + 30);
	puthz(125, 170, "�˻�", 24, 24, RED);

	bar(180, 220, 180 + 220, 220 + 30);
	bar(123, 220, 123 + 50, 220 + 30);
	puthz(125, 225, "����", 24, 24, RED);

	bar(150, 275, 200, 305);
	puthz(150, 280, "ע��", 24, 24, RED);

	bar(230, 275, 280, 305);
	puthz(230, 280, "��¼", 24, 24, RED);

	puthz(440,160,"��", 48, 48, RED);//�ᵺ���ݣ�xx,xx,,xx,xx,��ɫ��
	puthz(520, 160, "��", 48, 48, RED);//�ᵺ����
	puthz(420, 240, "��", 48, 48, BROWN);//�ᵺ����
	puthz(540, 240, "��", 48, 48, BROWN);//�ᵺ����

	setcolor(CYAN);
	setlinestyle(0,0,3);
	rectangle(600,5,620,25);
	line(600,5,620,25);
	line(620,5,600,25);
}
