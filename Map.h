#pragma once

#include <algorithm>
#include"DxLib.h"
#include"Game_Init.h"
#include"main.h"
#include"Game_Init.h"
#include"Game_Input.h"
#include"Game_Update.h"

#define NOMINMAX // std::min/std::max�𐳂������삳���邽��

int map_draw(int *season_c);
int map_stage(int i, int j, int *season_c, int *draw_chip,int *stage_nonber);

