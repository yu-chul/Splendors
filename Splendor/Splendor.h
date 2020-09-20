#ifndef _SPLENDOR_H
#define _SPLENDOR_H

/*
��ͷ�ļ���������Ϸ׼��ʱ���õ��ĺ���
ʹ����Щ������ʵ�ֶ���Ϸ���ݵĳ�ʼ������λ����
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "GameData.h"
#include "UIRefresh.h"

/*==========================ջ�ĳ�ʼ��==============================*/
extern void InitStack1();		//һ����

extern void InitStack2();		//������

extern void InitStack3();		//������

/*===========================��ջ===============================*/
extern void Push1();		//һ����

extern void Push2();		//������

extern void Push3();		//������

/*========================���ƶѣ���չ������壩�Ĳ���===========================*/
extern void ShuffleDev(struct DevCard*, int);		//ϴ�ƣ��΂��ƿ⣩

extern void ShuffleNoble();				//ϴ�ƣ����壩

extern void ShuffleAll();				//ϴ�ƣ������ƿ⣩

extern void CardsInStack();				//�ƿ��뗣����Ϊ�ƶ�

extern void PutNoble(int);				//�������������ʼ�������ƶ�

/*=============================����������λ===============================*/
extern int FindtheVoid(DevCard &a);

/*============================���ƣ�PutCard��=================================*/
extern void PutCard();		//����

#endif