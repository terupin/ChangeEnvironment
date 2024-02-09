#pragma once
#include<DxLib.h>
#include<stdio.h>
#include<string.h>
#include <Windows.h>
#include"Game_Init.h"
#include"title.h"
#include"Stage_No.h"
#include"game.h"
#include"GOAL.h"
#include"Continue.h"
#include"fps.h"
// EffekseerForDXLib.hをインクルードします。
#include "EffekseerForDXLib.h"

//画面変更
typedef enum {
	TITLE,      //タイトル画面
	GAMECOHICE,   //ゲーム選択画面
	CONTINUE,  //コンテニュー画面
	GAMESTAGE, //ゲーム画面（増えていくかもしれない）………頑張れ俺…俺ならできる…
	GOAL,
}SCENE;

//ステージ面
typedef enum {
	FIRST,
	SECOND,
	THIRD,
	FOUR,
	FIVE,
	SIX,
	SEVEN,
	EIGHT
}STAGENOM;


#define	NUM_KEYS 256	//キーの最大数
#define WHITE_COLOR  GetColor(255, 255, 255)       //白色

#define FONTSIZE 30     //フォントサイズ

#define START_X  250   //タイトル横位置
#define START_Y  500   //タイトル縦位置

#define SCREEN_WIDTH  960   //ステージ横画面
#define SCREEN_HEIGHT 800   //ステージ縦画面

//マップチップ関係

#define MAP_SIZE_X 32   // マップチップXサイズ
#define MAP_SIZE_Y  32	// マップチップYサイズ
#define NUM_CHIP_X  10  // 横10種類
#define NUM_CHIP_Y  4   // 縦4種類
#define NUM_CHIP_ALL  NUM_CHIP_X * NUM_CHIP_Y // 40個
#define NUM_MAP_X  30   //マップチップサイズ*ステージ横画面
#define NUM_MAP_Y  25   //マップチップサイズ*ステージ縦画面


//キャラクター関係

#define CHARA_WIDTH 32   // マップチップXサイズ
#define CHARA_HEIGHT  32	// マップチップYサイズ
#define CHARA_CHIP_X  3   // 横3種類
#define CHARA_CHIP_Y  4   // 縦4種類
#define CHARA_CHIP_ALL  CHARA_CHIP_X*CHARA_CHIP_Y  //12種類
#define ACT_DIR_SLIDE CHARA_CHIP_X

#define CHARA_STRAT_X 32    //キャラのスタート位置＿X軸
#define CHARA_STRAT_Y 608  //キャラのスタート位置＿Y軸
#define MAX_MOTION_INDEX 4  // 0,1,2,1 の4種類 [0～3]までにするために用意
#define ACT_SPEED 20       //キャラクターの進むスピード

//環境変更の数　0～2の三種類…出来ればまだ増やす…頑張れ俺、ゲームなんてやってる暇ない
typedef enum {
	SPLING,  //春
	SUMMER,  //夏
	AUTUMN,  //秋
	WINTER,  //冬
}SEASON;
typedef enum {
	SUNNY,  //晴
	CLOUD,   //雲
	RAIN,   //雨
}WEATHER;
typedef enum {
	MONING,  //朝
	LUNCH,   //昼
	NIGHT,   //夜
}DAY;


//fps
#define FLAME 60

