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
#ifndef _PAGE3_H_
#define _PAGE3_H_
int p3(void);
void page3_screen(void);
void inputname(struct U *user, int x1, int y1);
void inputpassword(struct U *user, int x1, int y1);
void inputpassword1(char *p, int x1, int y1);
void inputphone(struct U *user, int x1, int y1);
void bright(int x1, int y1, int x2, int y2, int bkcolor);
int check_register(struct U *getdata2, char *cp);
int existence(struct U *user);
void intofile(struct U *user);
void page3light(int x1, int y1, char *s);
void page3recover(int x1, int y1, char *s);

#endif