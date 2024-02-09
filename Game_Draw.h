#pragma once
#include"DxLib.h"
#include"Game_Init.h"

int game_draw(void);
int character_draw(CHARA *player);
int command(int color, int change_e,int envir,int cus);
int effect_draw(void);