#ifndef _RESERVECARD_H
#define _RESERVECARD_H

#include "GameData.h"
#include "UIRefresh.h"
#include "Splendor.h"
#include "ChooseCard.h"
#include "Judge.h"

/******************************************************************************************************************

										ReserveCard.h:

							������ѹ�Ʋ����������ڲ���Ҫ�õ��ĺ�����

	1.int �ж����p�Ƿ���λ�ý�cCardѹ�����ĺ������оͷ���1�����򷵻�0
			(���P�Ľṹ�������)

	2.void ��ҽ�cCard�ŵ��Լ���ѹ�������������лƽ����һ��
			(���P�Ľṹ�������,��ѡ�е���cCard,�����ϳ���CommonCoins)

	3.void ��ѹ�����������������������˳��
			�����P�Ľṹ���������
							��Ҫ������д��������

**************************************************************************************************************************/

//2.����ѹ�ƷŽ��������ĺ���
extern void Reserve(struct Player &p, DevCard &cCard, Coins &CommonCoins);

//���ⲿʹ�õ�ѹ�ƽӿ�
extern void ReserveCard(struct Player &p);

#endif // !_RESERVECARD_H