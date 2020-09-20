#ifndef _PURCHASECARD_H
#define _PURCHASECARD_H

#include "GameData.h"
#include "Splendor.h"
#include "ChooseCard.h"
#include "Judge.h"

/******************************************************************************************************************

										PurchaseCard.h:

							声明“买牌操作函数”内部需要用到的函数：

	1.void 让指针变量cCard指向order字符串代表的“桌面”上的牌，改变cCard就能改变“桌面”上被选的牌
			(cCard的地址, 一级牌放牌数组首地址, 二级牌放牌数组首地址, 三级牌放牌数组首地址, order首地址)

	2.void 让指针变量cCard指向order字符串代表的“玩家压牌区”上的牌，改变cCard就能改变“玩家压牌区”上被选的牌
			(cCard的地址, 输指令的玩家的结构体变量名, order首地址)

	3.int 判断玩家p是否能买cCard的函数，能买返回1，否则返回0
			(玩家P的结构体变量名,被选中的牌cCard)

	4.void 玩家p支付筹码买到了cCard，并将该牌写进玩家数据
			(玩家P的结构体变量名,被选中的牌cCard,桌面上筹码CommonCoins)

							
							不要在这里写变量声明

**************************************************************************************************************************/

//2.选中玩家输入的位置所指向的“玩家压牌区”上的牌的函数
extern void ChooseReservedCard( struct DevCard **, struct Player &p, char *);

//4.将已选牌写进玩家数据的函数
extern void Purchase(struct Player &p, DevCard &cCard,Coins &CommonCoins);

//5.整理压牌区的牌的函数
extern void ArrangeReservedCard(struct Player &p);

//选择买牌命令后的买牌操作（形参：玩家结构体变量名）
extern void PurchaseCard(struct Player &p);

#endif // !_PURCHASECARD_H