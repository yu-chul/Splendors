#ifndef _UIREFRESH_H
#define _UIREFRESH_H

#include "TitleMenu.h"
#include "GameData.h"

//�����Ϣˢ��
extern void playerefresh(int n);

//����һ����ˢ��
extern void card1refresh(DevCard *, int);

//���������ˢ��
extern void card2refresh(DevCard *, int);

//����������ˢ��
extern void card3refresh(DevCard *, int);

//����ˢ��
extern void coinrefresh();

//Ѻ����ˢ��
extern int regionrefresh(int);

//�����ʼˢ��
extern void noblefresh1(int);

//������ˢ��
extern void noblefresh2(int, int);

//�����Ϣ��
extern void clearMsgBox();

//����������
extern void HighlightPurchasableCard(struct Player &p);

//ˢ�����������������
extern void CardOutlineRefresh();

#endif