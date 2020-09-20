#include "Judge.h"


int JudgeToBuy(struct Player &p, DevCard &cCard)//�ж��Ƿ�������ѡ�Ƶĺ���
{
	int flag = 1;
	if (FindtheVoid(cCard) == 1)
	{
		if (cCard.white > p.bonus_white + p.coin_white || cCard.blue > p.bonus_blue + p.coin_blue || cCard.green > p.bonus_green + p.coin_green || cCard.red > p.bonus_red + p.coin_red || cCard.black > p.bonus_black + p.coin_black)
			//���Ȳ��ƻƽ��ж����г���������Ƿ��ѡ���ƵĴ�
		{
			int TDV = 0;						//���ƻƽ���Ҳ�ĳ�����ֵ
			if (cCard.white > p.bonus_white + p.coin_white)		//��ɫ��Ӧ
			{
				TDV += cCard.white - (p.bonus_white + p.coin_white);

			}
			if (cCard.blue > p.bonus_blue + p.coin_blue)		//��ɫ��Ӧ
			{
				TDV += cCard.blue - (p.bonus_blue + p.coin_blue);

			}
			if (cCard.green > p.bonus_green + p.coin_green)		//��ɫ��Ӧ
			{
				TDV += cCard.green - (p.bonus_green + p.coin_green);

			}
			if (cCard.red > p.bonus_red + p.coin_red)		//��ɫ��Ӧ
			{
				TDV += cCard.red - (p.bonus_red + p.coin_red);

			}
			if (cCard.black > p.bonus_black + p.coin_black)		//��ɫ��Ӧ
			{
				TDV += cCard.black - (p.bonus_black + p.coin_black);;

			}
			if (TDV > p.coin_gold)						//�����Ļ��ټ����ϻƽ������Ҳ�ĳ�����ֵ������һƽ�
				flag = 0;					//���������

		}
		else flag = 1;
	}
	else flag = 0;
	return flag;
}

int ReserveAreaEmpty(struct Player &p)//�ж��Ƿ���ѹ��ѡ�Ƶĺ���,Ҳ���������Ƿ���ʾѡ��βΣ���ҽṹ���������
{
	int i;
	for (i = 0; i < 3; i++)
	{
		if (FindtheVoid(p.devcard[i]) == 0)
			return 1;
	}
	return 0;
}

int PopCommend_TakeCoins(struct Player &p)	//�жϸ�����ܷ��ó��룬�������Ƿ���ʾѡ��βΣ���ҽṹ���������
{
	int differentcoin = 0;	//��¼��ͬ��ɫ�ĳ���
	if (coin.white > 0)
		differentcoin += 1;
	if (coin.blue > 0)
		differentcoin += 1;
	if (coin.green > 0)
		differentcoin += 1;
	if (coin.red > 0)
		differentcoin += 1;
	if (coin.black > 0)
		differentcoin += 1;
	if (coin.white > 3 || coin.blue > 3 || coin.green > 3 || coin.red > 3 || coin.black > 3)
		return 1;			//��һ����ɫ�ĳ�����������3���ܵ�������
	if (differentcoin >= 3)
		return 1;			//��������в�ͬ��ɫ�����������֣����ܵ�������
	return 0;				//�����ж�δ�ܴ������޷���������
}

int PopCommend_PurchaseCard(struct Player &p)	//�жϸ�����ܷ������ƣ��������Ƿ���ʾѡ��βΣ���ҽṹ���������
{
	int i;
	for (i = 0; i < 4; i++)				//������ܷ��������ϵ���
	{
		if (JudgeToBuy(p, CmmnCard1[i]) == 1)
			return 1;
		if (JudgeToBuy(p, CmmnCard2[i]) == 1)
			return 1;
		if (JudgeToBuy(p, CmmnCard3[i]) == 1)
			return 1;
	}
	for (i = 0; i < 3; i++)				//������ܷ�������ѹ���������
		if (JudgeToBuy(p, p.devcard[i]) == 1)
			return 1;
	return 0;							//�����ж�δ�ܴ������޷���������
}