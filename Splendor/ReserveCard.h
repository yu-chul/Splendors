#ifndef _RESERVECARD_H
#define _RESERVECARD_H

#include "GameData.h"
#include "UIRefresh.h"
#include "Splendor.h"
#include "ChooseCard.h"
#include "Judge.h"

/******************************************************************************************************************

										ReserveCard.h:

							声明“压牌操作函数”内部需要用到的函数：

	1.int 判断玩家p是否有位置将cCard压过来的函数，有就返回1，否则返回0
			(玩家P的结构体变量名)

	2.void 玩家将cCard放到自己的压牌区，桌面上有黄金就拿一个
			(玩家P的结构体变量名,被选中的牌cCard,桌面上筹码CommonCoins)

	3.void 将压牌区里的牌整理至由左至右顺序
			（玩家P的结构体变量名）
							不要在这里写变量声明

**************************************************************************************************************************/

//2.将已压牌放进玩家区域的函数
extern void Reserve(struct Player &p, DevCard &cCard, Coins &CommonCoins);

//供外部使用的压牌接口
extern void ReserveCard(struct Player &p);

#endif // !_RESERVECARD_H