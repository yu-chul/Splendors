#include "GameData.h"

//发展卡级别1牌库定义
struct DevCard devcard1[40] =
{
	{ Color(white),1,0,0,4,0,0 },{ Color(white),0,0,1,1,1,1 },
	{ Color(white),0,0,2,0,0,2 },{ Color(white),0,3,1,0,0,1 },
	{ Color(green),0,0,1,0,2,2 },{ Color(blue),0,0,1,3,1,0 },
	{ Color(blue),0,1,0,1,2,1 },{ Color(red),0,2,1,1,0,1 },
	{ Color(black),0,2,0,2,0,0 },{ Color(blue),0,0,0,2,0,2 },
	{ Color(black),0,0,0,1,3,1 },{ Color(blue),0,1,0,1,1,1 },
	{ Color(blue),1,0,0,0,4,0 },{ Color(white),0,1,2,1,1 },
	{ Color(green),0,1,3,1,0,0 },{ Color(black),0,0,0,3,0,0 },
	{ Color(black),0,2,2,0,1,0 },{ Color(white),0,0,0,0,2,1 },
	{ Color(red),0,3,0,0,0,0 },{ Color(red),0,2,0,0,2,0 },
	{ Color(green),0,2,1,0,0,0 },{ Color(red),1,4,0,0,0,0 },
	{ Color(blue),0,1,0,2,2,0 },{ Color(blue),0,1,0,0,0,2 },
	{ Color(red),0,2,0,1,0,2 },{ Color(black),0,1,1,1,1,0 },
	{ Color(black),0,1,2,1,1,0 },{ Color(black),1,0,4,0,0,0 },
	{ Color(black),0,0,0,2,1,0 },{ Color(green),0,0,0,0,3,0 },
	{ Color(green),0,0,2,0,2,0 },{ Color(green),1,0,0,0,0,4 },
	{ Color(green),0,1,1,0,1,1 },{ Color(green),0,1,1,0,1,2 },
	{ Color(red),0,0,2,1,0,0 },{ Color(red),0,1,0,0,1,3 },
	{ Color(white),0,0,3,0,0,0 },{ Color(blue),0,0,0,0,0,3 },
	{ Color(red),0,1,1,1,0,1 },{ Color(white),0,0,2,2,0,1 }
};

//发展卡级别2牌库定义
struct DevCard devcard2[30] =
{
	{ Color(white),2,0,0,0,5,0 },{ Color(white),3,6,0,0,0,0 },
	{ Color(blue),2,5,3,0,0,0 },{ Color(white),2,0,0,0,5,3 },
	{ Color(blue),1,0,2,2,3,0 },{ Color(green),2,4,2,0,0,1 },
	{ Color(blue),1,0,2,3,0,3 },{ Color(green),1,3,0,2,3,0 },
	{ Color(green),1,2,3,0,0,2 },{ Color(green),3,0,0,6,0,0 },
	{ Color(green),2,0,0,5,0,0 },{ Color(red),2,3,0,0,0,5 },
	{ Color(white),2,0,0,1,4,2 },{ Color(red),1,0,3,0,2,3 },
	{ Color(red),2,1,4,2,0,0 },{ Color(black),2,5,0,0,0,0 },
	{ Color(black),1,3,0,3,0,2 },{ Color(blue),2,2,0,0,1,4 },
	{ Color(black),1,3,2,2,0,0 },{ Color(red),1,2,0,0,2,3 },
	{ Color(blue),3,0,6,0,0,0 },{ Color(white),1,0,0,3,2,2 },
	{ Color(black),2,0,0,5,3,0 },{ Color(black),2,0,1,4,2,0 },
	{ Color(black),3,0,0,0,0,6 },{ Color(white),1,2,3,0,3,0 },
	{ Color(green),2,0,5,3,0,0 },{ Color(red),2,0,0,0,0,5 },
	{ Color(blue),2,0,5,0,0,0 },{ Color(red),3,0,0,0,6,0 }
};

//发展卡级别3牌库定义
struct DevCard devcard3[20] =
{
	{ Color(black),4,0,0,3,6,3 },{ Color(red),4,0,0,7,0,0 },
	{ Color(blue),5,7,3,0,0,0 },{ Color(blue),3,3,0,3,3,5 },
	{ Color(white),4,0,0,0,0,7 },{ Color(white),4,3,0,0,3,6 },
	{ Color(red),4,0,3,6,3,0 },{ Color(red),5,0,0,7,3,0 },
	{ Color(green),4,3,6,3,0,0 },{ Color(green),4,0,7,0,0,0 },
	{ Color(green),3,5,3,0,3,3 },{ Color(green),5,0,7,3,0,0 },
	{ Color(white),3,0,3,3,5,3 },{ Color(black),3,3,3,5,3,0 },
	{ Color(blue),4,7,0,0,0,0 },{ Color(black),5,0,0,0,7,3 },
	{ Color(blue),4,6,3,0,0,3 },{ Color(white),5,3,0,0,0,7 },
	{ Color(red),3,3,5,3,0,3 },{ Color(black),4,0,0,0,7,0 }
};

//为存储各等级卡堆的栈分配空间
SqStack1 *ss1 = (SqStack1*)malloc(sizeof(SqStack1));		//為一级卡堆分配空間
SqStack2 *ss2 = (SqStack2*)malloc(sizeof(SqStack2));		//為二级卡堆分配空間
SqStack3 *ss3 = (SqStack3*)malloc(sizeof(SqStack3));		//為三级卡堆分配空間

//定义1级牌，2级牌，3级牌的桌面放牌区
DevCard CmmnCard1[4], CmmnCard2[4], CmmnCard3[4];

//声明玩家
struct Player player[4];

//声明当前玩家数量
int numOfPlayer;

//定义贵族牌库
struct Noble noble[10] =
{
	{ 4,4,0,0,0 }, { 4,0,0,0,4 }, { 0,4,4,0,0 }, { 0,0,4,4,0 }, { 0,0,0,4,4 },
	{ 3,3,3,0,0 }, { 3,3,0,0,3 }, { 3,0,0,3,3 }, { 0,3,3,3,0 }, { 0,0,3,3,3 }
};

//初始化桌面贵族牌位，首元素-1代表该牌位为空
struct Noble CmmnNoble[5] =
{
	{-1,-1,-1,-1,-1}, { -1,-1,-1,-1,-1 }, { -1,-1,-1,-1,-1 }, { -1,-1,-1,-1,-1 }, { -1,-1,-1,-1,-1 }
};

//初始化贵族拜访玩家之标签
int Noble1byWho = -1;
int Noble2byWho = -1;
int Noble3byWho = -1;
int Noble4byWho = -1;
int Noble5byWho = -1;

//定义牌桌筹码变量
Coins coin;