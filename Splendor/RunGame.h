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

//从头开始游戏
extern void rungame();

//从存档开始游戏
extern void rungameFromData();

//游戏界面初始化
extern void init();

//游戏人数选择界面
extern void numberchoose();

//游戏结束界面
extern void endgame(int);

//游戏回合
extern int turn(int);

/*pos(20, 2); printf("◆"); pos(25, 2); printf("3");
pos(20, 3); printf("●3"); pos(24, 3); printf("●3");
pos(20, 4); printf("●3"); pos(24, 4); printf("●3");*/

#endif // !_RUNGAME_H