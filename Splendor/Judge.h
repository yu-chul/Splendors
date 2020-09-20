#ifndef _POPCOMMEND_H
#define _POPCOMMEND_H

#include "GameData.h"
#include "Splendor.h"

extern int JudgeToBuy(struct Player &p, DevCard &cCard);//判断是否能买已选牌的函数

extern int ReserveAreaEmpty(struct Player &p);			//判断是否能压牌的函数，也能来决定是否显示选项（形参：玩家结构体变量名）

extern int PopCommend_TakeCoins(struct Player &p);		//判断该玩家能否拿筹码，来决定是否显示选项（形参：玩家结构体变量名）

extern int PopCommend_PurchaseCard(struct Player &p);	//判断该玩家能否能买牌，来决定是否显示选项（形参：玩家结构体变量名）

#endif // !_POPCOMMEND_H

