/*
��ͷ�ļ���������Ϸ���������õ������������Լ��ײ����ݱ���
Ʃ���ƿ⡢�ƶѵ�����Ϸ��ʼǰ���Ѿ�
*/

#ifndef _GAMEDATA_H 
#define _GAMEDATA_H

#include <stdio.h>
#include <stdlib.h>

/*============================������������/�ṹ�����鶨��=============================*/
enum Color { white = 1, blue, green, red, black }; //��չ����ɫö�����Ͷ���

//���巢չ���Ľṹ������
struct DevCard
{
	enum Color bonus;			//��չ����ʯ�ӳ�
	int point;					//��չ����������
	int white;
	int blue;
	int green;
	int red;
	int black;					//��չ���۸�
};

//�������Ľṹ������
struct Noble
{
	int white;
	int blue;
	int green;
	int red;
	int black;
};

//���������Ϣ�ṹ������
struct Player							
{
	int coin_white;
	int coin_blue;
	int coin_green;
	int coin_red;
	int coin_black;
	int coin_gold;
	int coin_total;
	int bonus_white;
	int bonus_blue;
	int bonus_green;
	int bonus_red;
	int bonus_black;
	int points;
	struct DevCard devcard[3];
};

//������������ṹ�����ͼ�Ψһ����coins
struct Coins							
{
	int white;
	int blue;
	int green;
	int red;
	int black;
	int gold;
};

/*===========================��������ջ�Ĵ洢�ṹ��������չ�����ƶѣ�=======================*/
typedef struct		//һ����40��
{
	DevCard stack[40];
	int top;
} SqStack1;

typedef struct		//������30��
{
	DevCard stack[30];
	int top;
} SqStack2;

typedef struct		//������20��
{
	DevCard stack[20];
	int top;
} SqStack3;

/*================================��Ϸ�ײ����ݱ�������=================================*/
//�������
extern struct Player player[4];

//������ǰ�������
extern int numOfPlayer;

//����������չ����
extern struct DevCard devcard1[40], devcard2[30], devcard3[20];

//����1���ƣ�2���ƣ�3���Ƶ����������
extern DevCard CmmnCard1[4], CmmnCard2[4], CmmnCard3[4];

//Ϊ�洢���ȼ����ѵ�ջ����ռ�
extern SqStack1 *ss1;		//һ������
extern SqStack2 *ss2;		//��������
extern SqStack3 *ss3;		//��������

//���������������
extern Coins coin;

//���������ƿ�
extern struct Noble noble[10];

//�����������
extern struct Noble CmmnNoble[5];

//��������ݷ����֮��ǩ
extern int Noble1byWho;
extern int Noble2byWho;
extern int Noble3byWho;
extern int Noble4byWho;
extern int Noble5byWho;

#endif