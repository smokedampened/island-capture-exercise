/********************************************************
FileName:renew.c
Author:
Main author :
Description����ģ��Ϊ����ģ�飬һ��ģ�飬�ṩ����������ݵĸ��ºͳ�ʼ��
FunctionList��
	1.void renewgame(struct island ild[])
	2.void design(struct island* pt)
	3.void renew(struct island* pt)
	4.void begin(struct island* pt1, struct island* pt2)
	5.void  g_selfdesign(struct island ild[])
	6.void selfdesign(struct island ild[])
********************************************************/
#ifndef __RENEW__
#define __RENEW__
void renewgame(struct island ild[]);
void design(struct island* pt);
void renew(struct island* pt);
void begin(struct island* pt1, struct island* pt2);
void  g_selfdesign(struct island ild[]);
void selfdesign(struct island ild[]);
#endif