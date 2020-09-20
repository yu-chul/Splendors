/*
该头文件定义了游戏准备时所用到的函数
使用这些函数以实现对游戏数据的初始化及就位操作
*/

#include "Splendor.h"

/*==========================栈的初始化==============================*/
void InitStack1()		//一级卡
{
	if (!ss1)
		exit(1);
	ss1->top = -1;
}
void InitStack2()		//二级卡
{
	if (!ss2)
		exit(1);
	ss2->top = -1;
}
void InitStack3()		//三级卡
{
	if (!ss3)
		exit(1);
	ss3->top = -1;
}

/*===========================入栈===============================*/
void Push1()		//一级卡
{
	int i;
	for (i = 0; i < 40; i++)
	{
		ss1->top = ss1->top + 1;
		ss1->stack[ss1->top] = devcard1[i];
	}
}
void Push2()		//二级卡
{
	int i;
	for (i = 0; i < 30; i++)
	{
		ss2->top = ss2->top + 1;
		ss2->stack[ss2->top] = devcard2[i];
	}
}
void Push3()		//三级卡
{
	int i;
	for (i = 0; i < 20; i++)
	{
		ss3->top = ss3->top + 1;
		ss3->stack[ss3->top] = devcard3[i];
	}
}

/*========================对牌堆的操作===========================*/
void ShuffleDev(struct DevCard *a, int n)	//洗牌（單個牌库）
{
	struct DevCard tmp;					//創建臨時牌
	int i, j, t = 1000;					//洗牌動作1000次
	srand(unsigned(time(NULL)));		//隨機種子
	while (t--)							//洗牌
	{
		i = rand() % n;
		j = rand() % n;
		tmp = a[i];
		a[i] = a[j];
		a[j] = tmp;
	}
}

void ShuffleNoble()//洗牌（贵族）
{
	struct Noble tmp;					//創建臨時贵族牌
	int i, j, t = 1000;					//洗牌動作1000次
	srand(unsigned(time(NULL)));		//隨機種子
	while (t--)							//洗牌
	{
		i = rand() % 10;
		j = rand() % 10;
		tmp = noble[i];
		noble[i] = noble[j];
		noble[j] = tmp;
	}
}

void ShuffleAll()						//洗牌（所有牌库）
{
	ShuffleDev(devcard1, 40);
	ShuffleDev(devcard2, 30);
	ShuffleDev(devcard3, 20);
	ShuffleNoble();
}

void CardsInStack()						//牌库入棧，成为牌堆
{
	InitStack1();
	InitStack2();
	InitStack3();						//初始化所有棧
	Push1();
	Push2();
	Push3();							//入棧
}

void PutNoble(int numOfPlayers)				//根据玩家数量初始化贵族牌堆
{
	for (int i = 0; i < numOfPlayers + 1; i++)
	{
		CmmnNoble[i] = noble[i];
	}
}

/*=============================找置牌区空位===============================*/
int FindtheVoid(DevCard &a)
{
	if (a.bonus != (Color)1 && a.bonus != (Color)2 && a.bonus != (Color)3 && a.bonus != (Color)4 && a.bonus != (Color)5 && a.bonus != (Color)6)
		return 0;	//没牌
	else
		return 1;	//有牌
}

/*============================补牌（PutCard）=================================*/
void PutCard()	//补牌
{
	int i;
	for (i = 0; i < 4; i++)
	{
		if (!FindtheVoid(CmmnCard1[i]))		//填一级牌位
		{
			if (ss1->top != -1)
			{
				CmmnCard1[i] = ss1->stack[ss1->top];
				--ss1->top;
			}
			card1refresh(&CmmnCard1[i], i);
		}
		if (!FindtheVoid(CmmnCard2[i]))		//填二级牌位
		{
			if (ss2->top != -1)
			{
				CmmnCard2[i] = ss2->stack[ss2->top];
				--ss2->top;
			}
			card2refresh(&CmmnCard2[i], i);
		}
		if (!FindtheVoid(CmmnCard3[i]))		//填三级牌位
		{
			if (ss3->top != -1)
			{
				CmmnCard3[i] = ss3->stack[ss3->top];
				--ss3->top;
			}
			card3refresh(&CmmnCard3[i], i);
		}
	}
}