/*
��ͷ�ļ���������Ϸ׼��ʱ���õ��ĺ���
ʹ����Щ������ʵ�ֶ���Ϸ���ݵĳ�ʼ������λ����
*/

#include "Splendor.h"

/*==========================ջ�ĳ�ʼ��==============================*/
void InitStack1()		//һ����
{
	if (!ss1)
		exit(1);
	ss1->top = -1;
}
void InitStack2()		//������
{
	if (!ss2)
		exit(1);
	ss2->top = -1;
}
void InitStack3()		//������
{
	if (!ss3)
		exit(1);
	ss3->top = -1;
}

/*===========================��ջ===============================*/
void Push1()		//һ����
{
	int i;
	for (i = 0; i < 40; i++)
	{
		ss1->top = ss1->top + 1;
		ss1->stack[ss1->top] = devcard1[i];
	}
}
void Push2()		//������
{
	int i;
	for (i = 0; i < 30; i++)
	{
		ss2->top = ss2->top + 1;
		ss2->stack[ss2->top] = devcard2[i];
	}
}
void Push3()		//������
{
	int i;
	for (i = 0; i < 20; i++)
	{
		ss3->top = ss3->top + 1;
		ss3->stack[ss3->top] = devcard3[i];
	}
}

/*========================���ƶѵĲ���===========================*/
void ShuffleDev(struct DevCard *a, int n)	//ϴ�ƣ��΂��ƿ⣩
{
	struct DevCard tmp;					//�����R�r��
	int i, j, t = 1000;					//ϴ�Ƅ���1000��
	srand(unsigned(time(NULL)));		//�S�C�N��
	while (t--)							//ϴ��
	{
		i = rand() % n;
		j = rand() % n;
		tmp = a[i];
		a[i] = a[j];
		a[j] = tmp;
	}
}

void ShuffleNoble()//ϴ�ƣ����壩
{
	struct Noble tmp;					//�����R�r������
	int i, j, t = 1000;					//ϴ�Ƅ���1000��
	srand(unsigned(time(NULL)));		//�S�C�N��
	while (t--)							//ϴ��
	{
		i = rand() % 10;
		j = rand() % 10;
		tmp = noble[i];
		noble[i] = noble[j];
		noble[j] = tmp;
	}
}

void ShuffleAll()						//ϴ�ƣ������ƿ⣩
{
	ShuffleDev(devcard1, 40);
	ShuffleDev(devcard2, 30);
	ShuffleDev(devcard3, 20);
	ShuffleNoble();
}

void CardsInStack()						//�ƿ��뗣����Ϊ�ƶ�
{
	InitStack1();
	InitStack2();
	InitStack3();						//��ʼ�����З�
	Push1();
	Push2();
	Push3();							//�뗣
}

void PutNoble(int numOfPlayers)				//�������������ʼ�������ƶ�
{
	for (int i = 0; i < numOfPlayers + 1; i++)
	{
		CmmnNoble[i] = noble[i];
	}
}

/*=============================����������λ===============================*/
int FindtheVoid(DevCard &a)
{
	if (a.bonus != (Color)1 && a.bonus != (Color)2 && a.bonus != (Color)3 && a.bonus != (Color)4 && a.bonus != (Color)5 && a.bonus != (Color)6)
		return 0;	//û��
	else
		return 1;	//����
}

/*============================���ƣ�PutCard��=================================*/
void PutCard()	//����
{
	int i;
	for (i = 0; i < 4; i++)
	{
		if (!FindtheVoid(CmmnCard1[i]))		//��һ����λ
		{
			if (ss1->top != -1)
			{
				CmmnCard1[i] = ss1->stack[ss1->top];
				--ss1->top;
			}
			card1refresh(&CmmnCard1[i], i);
		}
		if (!FindtheVoid(CmmnCard2[i]))		//�������λ
		{
			if (ss2->top != -1)
			{
				CmmnCard2[i] = ss2->stack[ss2->top];
				--ss2->top;
			}
			card2refresh(&CmmnCard2[i], i);
		}
		if (!FindtheVoid(CmmnCard3[i]))		//��������λ
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