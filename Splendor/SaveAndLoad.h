#ifndef _SAVEGAME_H
#define _SAVEGAME_H

#include "GameData.h"

extern int SaveGame(int);//存档用函数( 形参：玩家数组中的常量表达式（就是那个[i]：0，1，2，3) ）

extern int LoadGame();//读取用函数
#endif
