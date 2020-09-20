#ifndef _TITLEMENU_H
#define _TITLEMENU_H

#include <stdio.h>
#include <stdlib.h>
#include "RunGame.h"
#include "GameIntro.h"
#include "Drawer.h"

//游戏主界面初始化
extern void initgame();

//主界面操作
extern void TitleMenu();

//游戏说明界面
extern void gamexplain();

//游戏说明界面操作
extern void gamedeveloper();

#endif // !_TITLEMENU_H