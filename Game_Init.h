#pragma once
#include "DxLib.h"

//構造体
struct CHARA
{
	float chara_move_x;    // キャラの位置のX軸
	float chara_move_y;    // キャラの位置のY軸
	float speed;  //移動速度
	float yadd;  //高さ
	float gravity; //重さ
	float old_x;	// 前回のX位置
	float old_y;   // 前回のX位置
	int chara_act[12];  //キャラ画像分割
	int act_motion[4]; //モーション画像
	int act_index;   //何番のモーション画像を描画するか
	int act_dir;  //何列目のキャラ画像

};

int map_init(void);
int chara_init(CHARA *player);
int game_init(void);

