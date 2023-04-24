/*************************************************
FileName:page.h
Author :
Main author :
Description：该模块为登入模块
FunctionList：
1 int p1(struct U *user);
2.void logname(struct U *user, int x1, int y1);
3.void logpassword(struct U *user, int x1, int y1);
4.int check_log(struct U *user);
5.void page1_screen(void);
6.void page1light(int x1, int y1, char *s);
7.void page1recover(int x1, int y1, char *s);
********************************************************/
#ifndef _PAGE1_H_
#define _PAGE1_H_

int p1(struct U *user);
void logname(struct U *user, int x1, int y1);
void logpassword(struct U *user, int x1, int y1);
int check_log(struct U *user);
void page1_screen(void);
void page1light(int x1, int y1, char *s);
void page1recover(int x1, int y1, char *s);
int p0(void);

#endif