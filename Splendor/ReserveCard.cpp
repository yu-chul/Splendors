#include "ReserveCard.h"

/******************************************************************************************************************

										ReserveCard.cpp:

							ʵ�֡�ѹ�Ʋ����������ڲ���Ҫ�õ��ĺ�����

							����ͬ��ͷ�ļ�

							��Ҫ������д��������

**************************************************************************************************************************/


//2.����ѹ�ƷŽ��������ĺ���
void Reserve(struct Player &p, DevCard &cCard, Coins &CommonCoins)
{
	int i;
	for (i = 0; i < 3; i++)
	{
		if (FindtheVoid(p.devcard[i]) == 0)				//���ҿ�λ���пղ��еط�ѹ������	
		{
			if (CommonCoins.gold > 0)				//��������лƽ�
			{
				CommonCoins.gold -= 1;			//�������ƽ��һ
				p.coin_gold += 1;				//������ƽ��һ
				p.coin_total += 1;
				p.devcard[i] = cCard;		//����ѹ����
				cCard.bonus = (Color)0;		//�������϶�Ӧ�����
			}
			else									//�������û�лƽ�
			{
				p.devcard[i] = cCard;		//ֻ����ѹ����
				cCard.bonus = (Color)0;		//���������϶�Ӧ�����
			}
			break;										//ѹ���ƺ�ͽ�������
		}
	}
	if (i == 3)
		printf("���ı��������������޷�ѹ�ơ�");			//����һȦû�ط�ѹ�������ѹ������~
}

//���ⲿʹ�õ�ѹ�ƽӿ�
void ReserveCard(struct Player &p)						//ѡ������������ѹ�Ʋ������βΣ���ҽṹ���������
{
	int i, number = 0, letterABCD = 0;
	int flag = 0, Rflag = 0;
	char order[10];
	DevCard *ChosenCard = NULL;
	printf("���������������ķ�չ��֮��ţ�");
	do
	{
		pos(2, 23);
		gets_s(order, 10);
		clearMsgBox();
		for (i = 0; *(order + i) != '\0'; i++)
		{
			if (*(order + i) >= '1'&&*(order + i) <= '3')
				number += 1;
			if (*(order + i) >= 'a'&&*(order + i) <= 'd' || *(order + i) >= 'A'&&*(order + i) <= 'D')
				letterABCD += 1;
		}
		if (number == 1)
			if (letterABCD == 1)
				Rflag = 1;
		if (Rflag == 0)
			printf("���������������������룺");
		if (Rflag == 1)
		{
			ChooseCard(&ChosenCard, order);
			if(ReserveAreaEmpty(p)==1)
			{
				Reserve(p, *ChosenCard, coin);
				PutCard();
				printf("���ѳɹ�����һ�ŷ�չ����");
				Sleep(1000);
				clearMsgBox();
				flag = 1;
			}
			else
				printf("���ѹ����û��λ�ˣ�ֻ���ó����������Ӵ~\n");
		}
	} while (flag == 0);
}