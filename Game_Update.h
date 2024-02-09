#pragma once
#include "DxLib.h"
#include"main.h"
#include"Game_Init.h"
#include"Game_Input.h"
#include"Map.h"

int game_update(void);
int cus_update(char *buf, char *buf_old,int *change_e, int *envir, int *cus, int *season_c, int *weather_c, int *day_c);
int chara_update(char *buf, char *buf_old, CHARA *player,int *weather_c,int *day_c, int *game_scene);
int CheckHit(float x1, float y1, float w1, float h1, float x2, float y2, float w2, float h2);
int map_col(CHARA *player,int *game_sceme, int *season_c,int *stage_nonber);
int diside(char *buf, char *buf_old, int *change_e, int *envir, int *cus, int *season_c, int *weather_c, int *day_c);