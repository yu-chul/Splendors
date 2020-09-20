#ifndef _RUNGAME_H
#define _RUNGAME_H

#include "TitleMenu.h"
#include "UIRefresh.h"
#include "Splendor.h"
#include "GameData.h"
#include "Judge.h"
#include "PurchaseCard.h"
#include "TakeCoins.h"
#include "TakeNoble.h"
#include "ReserveCard.h"
#include "SaveAndLoad.h"

//��ͷ��ʼ��Ϸ
extern void rungame();

//�Ӵ浵��ʼ��Ϸ
extern void rungameFromData();

//��Ϸ�����ʼ��
extern void init();

//��Ϸ����ѡ�����
extern void numberchoose();

//��Ϸ��������
extern void endgame(int);

//��Ϸ�غ�
extern int turn(int);

/*pos(20, 2); printf("��"); pos(25, 2); printf("3");
pos(20, 3); printf("��3"); pos(24, 3); printf("��3");
pos(20, 4); printf("��3"); pos(24, 4); printf("��3");*/

#endif // !_RUNGAME_H