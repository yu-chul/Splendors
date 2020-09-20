#ifndef _POPCOMMEND_H
#define _POPCOMMEND_H

#include "GameData.h"
#include "Splendor.h"

extern int JudgeToBuy(struct Player &p, DevCard &cCard);//�ж��Ƿ�������ѡ�Ƶĺ���

extern int ReserveAreaEmpty(struct Player &p);			//�ж��Ƿ���ѹ�Ƶĺ�����Ҳ���������Ƿ���ʾѡ��βΣ���ҽṹ���������

extern int PopCommend_TakeCoins(struct Player &p);		//�жϸ�����ܷ��ó��룬�������Ƿ���ʾѡ��βΣ���ҽṹ���������

extern int PopCommend_PurchaseCard(struct Player &p);	//�жϸ�����ܷ������ƣ��������Ƿ���ʾѡ��βΣ���ҽṹ���������

#endif // !_POPCOMMEND_H

