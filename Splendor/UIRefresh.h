#ifndef _UIREFRESH_H
#define _UIREFRESH_H

#include "TitleMenu.h"
#include "GameData.h"

//玩家信息刷新
extern void playerefresh(int n);

//桌面一级牌刷新
extern void card1refresh(DevCard *, int);

//桌面二级牌刷新
extern void card2refresh(DevCard *, int);

//桌面三级牌刷新
extern void card3refresh(DevCard *, int);

//筹码刷新
extern void coinrefresh();

//押牌区刷新
extern int regionrefresh(int);

//贵族初始刷新
extern void noblefresh1(int);

//贵族获得刷新
extern void noblefresh2(int, int);

//清空消息框
extern void clearMsgBox();

//高亮可买牌
extern void HighlightPurchasableCard(struct Player &p);

//刷新桌面置牌区牌外框
extern void CardOutlineRefresh();

#endif