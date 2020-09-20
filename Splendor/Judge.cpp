#include "Judge.h"


int JudgeToBuy(struct Player &p, DevCard &cCard)//判断是否能买已选牌的函数
{
	int flag = 1;
	if (FindtheVoid(cCard) == 1)
	{
		if (cCard.white > p.bonus_white + p.coin_white || cCard.blue > p.bonus_blue + p.coin_blue || cCard.green > p.bonus_green + p.coin_green || cCard.red > p.bonus_red + p.coin_red || cCard.black > p.bonus_black + p.coin_black)
			//首先不计黄金，判断手中筹码加声望是否比选中牌的大
		{
			int TDV = 0;						//不计黄金，玩家差的筹码总值
			if (cCard.white > p.bonus_white + p.coin_white)		//白色对应
			{
				TDV += cCard.white - (p.bonus_white + p.coin_white);

			}
			if (cCard.blue > p.bonus_blue + p.coin_blue)		//蓝色对应
			{
				TDV += cCard.blue - (p.bonus_blue + p.coin_blue);

			}
			if (cCard.green > p.bonus_green + p.coin_green)		//绿色对应
			{
				TDV += cCard.green - (p.bonus_green + p.coin_green);

			}
			if (cCard.red > p.bonus_red + p.coin_red)		//红色对应
			{
				TDV += cCard.red - (p.bonus_red + p.coin_red);

			}
			if (cCard.black > p.bonus_black + p.coin_black)		//黑色对应
			{
				TDV += cCard.black - (p.bonus_black + p.coin_black);;

			}
			if (TDV > p.coin_gold)						//不够的话再计算上黄金，如果玩家差的筹码总值大于玩家黄金
				flag = 0;					//你就买不了牌

		}
		else flag = 1;
	}
	else flag = 0;
	return flag;
}

int ReserveAreaEmpty(struct Player &p)//判断是否能压已选牌的函数,也能来决定是否显示选项（形参：玩家结构体变量名）
{
	int i;
	for (i = 0; i < 3; i++)
	{
		if (FindtheVoid(p.devcard[i]) == 0)
			return 1;
	}
	return 0;
}

int PopCommend_TakeCoins(struct Player &p)	//判断该玩家能否拿筹码，来决定是否显示选项（形参：玩家结构体变量名）
{
	int differentcoin = 0;	//记录不同颜色的筹码
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
		return 1;			//有一种颜色的筹码数量大于3就能弹出命令
	if (differentcoin >= 3)
		return 1;			//如果场上有不同颜色筹码至少三种，就能弹出命令
	return 0;				//上述判断未能触发就无法弹出命令
}

int PopCommend_PurchaseCard(struct Player &p)	//判断该玩家能否能买牌，来决定是否显示选项（形参：玩家结构体变量名）
{
	int i;
	for (i = 0; i < 4; i++)				//看玩家能否买桌面上的牌
	{
		if (JudgeToBuy(p, CmmnCard1[i]) == 1)
			return 1;
		if (JudgeToBuy(p, CmmnCard2[i]) == 1)
			return 1;
		if (JudgeToBuy(p, CmmnCard3[i]) == 1)
			return 1;
	}
	for (i = 0; i < 3; i++)				//看玩家能否买自已压牌区里的牌
		if (JudgeToBuy(p, p.devcard[i]) == 1)
			return 1;
	return 0;							//上述判断未能触发就无法弹出命令
}