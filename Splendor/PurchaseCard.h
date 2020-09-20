#ifndef _PURCHASECARD_H
#define _PURCHASECARD_H

#include "GameData.h"
#include "Splendor.h"
#include "ChooseCard.h"
#include "Judge.h"

/******************************************************************************************************************

										PurchaseCard.h:

							���������Ʋ����������ڲ���Ҫ�õ��ĺ�����

	1.void ��ָ�����cCardָ��order�ַ�������ġ����桱�ϵ��ƣ��ı�cCard���ܸı䡰���桱�ϱ�ѡ����
			(cCard�ĵ�ַ, һ���Ʒ��������׵�ַ, �����Ʒ��������׵�ַ, �����Ʒ��������׵�ַ, order�׵�ַ)

	2.void ��ָ�����cCardָ��order�ַ�������ġ����ѹ�������ϵ��ƣ��ı�cCard���ܸı䡰���ѹ�������ϱ�ѡ����
			(cCard�ĵ�ַ, ��ָ�����ҵĽṹ�������, order�׵�ַ)

	3.int �ж����p�Ƿ�����cCard�ĺ��������򷵻�1�����򷵻�0
			(���P�Ľṹ�������,��ѡ�е���cCard)

	4.void ���p֧����������cCard����������д���������
			(���P�Ľṹ�������,��ѡ�е���cCard,�����ϳ���CommonCoins)

							
							��Ҫ������д��������

**************************************************************************************************************************/

//2.ѡ����������λ����ָ��ġ����ѹ�������ϵ��Ƶĺ���
extern void ChooseReservedCard( struct DevCard **, struct Player &p, char *);

//4.����ѡ��д��������ݵĺ���
extern void Purchase(struct Player &p, DevCard &cCard,Coins &CommonCoins);

//5.����ѹ�������Ƶĺ���
extern void ArrangeReservedCard(struct Player &p);

//ѡ���������������Ʋ������βΣ���ҽṹ���������
extern void PurchaseCard(struct Player &p);

#endif // !_PURCHASECARD_H