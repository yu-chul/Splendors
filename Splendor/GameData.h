/*
该头文件定义了游戏过程中所用到的数据类型以及底层数据变量
譬如牌库、牌堆等在游戏开始前就已经
*/

#ifndef _GAMEDATA_H 
#define _GAMEDATA_H

#include <stdio.h>
#include <stdlib.h>

/*============================各项数据类型/结构体数组定义=============================*/
enum Color { white = 1, blue, green, red, black }; //发展卡颜色枚举类型定义

//定义发展卡的结构体类型
struct DevCard
{
	enum Color bonus;			//发展卡宝石加成
	int point;					//发展卡声望点数
	int white;
	int blue;
	int green;
	int red;
	int black;					//发展卡价格
};

//定义贵族的结构体类型
struct Noble
{
	int white;
	int blue;
	int green;
	int red;
	int black;
};

//定义玩家信息结构体类型
struct Player							
{
	int coin_white;
	int coin_blue;
	int coin_green;
	int coin_red;
	int coin_black;
	int coin_gold;
	int coin_total;
	int bonus_white;
	int bonus_blue;
	int bonus_green;
	int bonus_red;
	int bonus_black;
	int points;
	struct DevCard devcard[3];
};

//定义牌桌筹码结构体类型及唯一变量coins
struct Coins							
{
	int white;
	int blue;
	int green;
	int red;
	int black;
	int gold;
};

/*===========================定义三种栈的存储结构（各级别发展卡的牌堆）=======================*/
typedef struct		//一级卡40张
{
	DevCard stack[40];
	int top;
} SqStack1;

typedef struct		//二级卡30张
{
	DevCard stack[30];
	int top;
} SqStack2;

typedef struct		//三级卡20张
{
	DevCard stack[20];
	int top;
} SqStack3;

/*================================游戏底层数据变量声明=================================*/
//声明玩家
extern struct Player player[4];

//声明当前玩家数量
extern int numOfPlayer;

//声明各级别发展卡库
extern struct DevCard devcard1[40], devcard2[30], devcard3[20];

//定义1级牌，2级牌，3级牌的桌面放牌区
extern DevCard CmmnCard1[4], CmmnCard2[4], CmmnCard3[4];

//为存储各等级卡堆的栈分配空间
extern SqStack1 *ss1;		//一级卡堆
extern SqStack2 *ss2;		//二级卡堆
extern SqStack3 *ss3;		//三级卡堆

//声明牌桌筹码变量
extern Coins coin;

//声明贵族牌库
extern struct Noble noble[10];

//声明桌面贵族
extern struct Noble CmmnNoble[5];

//声明贵族拜访玩家之标签
extern int Noble1byWho;
extern int Noble2byWho;
extern int Noble3byWho;
extern int Noble4byWho;
extern int Noble5byWho;

#endif