#pragma once
#include"DxLib.h"
#include"main.h"

int conti(void);
int conti_input(char *buf, char *buf_old);
int conti_update(char*buf, char* buf_old, int *game_scene, CHARA *player, int *season_c, int *weather_c, int *day_c);
int conti_draw(void);