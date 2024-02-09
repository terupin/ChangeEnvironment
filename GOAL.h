#pragma once

#include<DxLib.h>
#include"main.h"
#include"fps.h"
#include"Game_Init.h"

int goal(void);
int goal_input(char *buf, char *buf_old);
int goal_update(char*buf, char* buf_old, int *game_scene, CHARA *player, int *now_season, int *now_weather, int *now_day);
int goal_draw(void);
