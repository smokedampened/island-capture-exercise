/********************************************************
FileName:progress.c
Author:
Main author :
Description����ģ��Ϊ�ṹ��ģ�飬һ��ģ�飬��ʼ������ؽṹ��
FunctionList��
	1 void ownership1(struct island ild[])
	2.void ownership2(struct island ild[])
	3.int inputposin(int x1, int y1)
	4.int ild_select()
	5.void rebuit(struct island* pt)
	6.int judge(int a, int b)
********************************************************/
#ifndef __STRUCTER__
#define __STRUCTER__

typedef struct Dtaamy//amy 
{
	int num;//the number of amy����
	int atk;//the hurt rate coused by amy�˺���
	int rate;//the transport rate of amy������
	int atk_dst;
}Dta_amy;

typedef struct Dtaat
{
	int num;	//the number of at����
	int atk;	//the hurt rate coused by at�˺���
	int rate;	//the transport rate of at������
	int atk_dst;
}Dta_at;

typedef struct Dtabt
{
	int num;	//the number of bt����
	int ts_rate;//the content of at������
	int pos;
}Dta_bt;

typedef struct Dtasp
{
	double defes;		//the defence of island������ֵ
	int num;		//the number of sp in island����
}Dta_sp;

 struct island
{
	int id1;
	int id2;//judge the island is whose
	char name[20];
	Dta_amy amy1;//the related information of amyA in this land
	Dta_amy amy2;//the related information of amyBin this land
	Dta_at at1;//the related information of atA in this land
	Dta_at at2;//the related information of atB in this land
	Dta_bt bt1;//the related information of shioA in this land
	Dta_bt bt2;//the related information of shipB in this land
	Dta_sp sp;//the related information of sp in this land
};
#endif