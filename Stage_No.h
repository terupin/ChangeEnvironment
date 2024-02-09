#pragma once

#include<DxLib.h>
#include"main.h"
#include"fps.h"
#include"Game_Init.h"

int stage_no(void);
int stage_no_input(char *buf, char *buf_old);
int stage_no_update(char*buf, char* buf_old, int *game_scene, CHARA *player, int *stage_cos, int *stage_nonber);
int stage_no_draw(int *stage_cos);