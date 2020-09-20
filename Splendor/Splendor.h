#ifndef _SPLENDOR_H
#define _SPLENDOR_H

/*
该头文件定义了游戏准备时所用到的函数
使用这些函数以实现对游戏数据的初始化及就位操作
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "GameData.h"
#include "UIRefresh.h"

/*==========================栈的初始化==============================*/
extern void InitStack1();		//一级卡

extern void InitStack2();		//二级卡

extern void InitStack3();		//三级卡

/*===========================入栈===============================*/
extern void Push1();		//一级卡

extern void Push2();		//二级卡

extern void Push3();		//三级卡

/*========================对牌堆（发展卡与贵族）的操作===========================*/
extern void ShuffleDev(struct DevCard*, int);		//洗牌（單個牌库）

extern void ShuffleNoble();				//洗牌（贵族）

extern void ShuffleAll();				//洗牌（所有牌库）

extern void CardsInStack();				//牌库入棧，成为牌堆

extern void PutNoble(int);				//根据玩家数量初始化贵族牌堆

/*=============================找置牌区空位===============================*/
extern int FindtheVoid(DevCard &a);

/*============================补牌（PutCard）=================================*/
extern void PutCard();		//补牌

#endif