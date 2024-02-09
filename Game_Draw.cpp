#include "DxLib.h"
#include"main.h"
#include"Game_Init.h"
#include"Game_Draw.h"
#include"Map.h"

extern int season_c;
extern int weather_c;
extern int day_c;
extern int snow;
extern int sakura;
extern int leaf;
extern int rain;
extern int cloud;
extern int effect_go;
extern int sun;
extern int fire;

int game_draw(void)
{
	//画面消去
	ClearDrawScreen();

	//白色
	unsigned int color = GetColor(255, 255, 255);

	extern int change_e;
	extern int envir;
	extern int cus;
	extern CHARA player;



	map_draw(&season_c);//マップ
	character_draw(&player);  //キャラ
	command(color, change_e, envir, cus);

	return 0;
}

int command(int color, int change_e, int envir, int cus)
{
	//コマンド場所
	int com_scene = 0;
	int lun = 0;  //文字の位置

	//環境切り替えコマンド表示
	if (cus == 0)
	{
		//変更する環境
		DrawFormatString(FONTSIZE, com_scene, color, "季節");
		DrawFormatString(FONTSIZE, com_scene + MAP_SIZE_X, color, "天候");
		DrawFormatString(FONTSIZE, com_scene + MAP_SIZE_X * 2, color, "昼夜");

		//変更する環境の矢印表示
		switch (change_e)
		{
		case 0:
			DrawFormatString(0, com_scene, color, "→");
			break;
		case 1:
			DrawFormatString(0, com_scene += MAP_SIZE_X, color, "→");
			break;

		case 2:
			DrawFormatString(0, com_scene += MAP_SIZE_X * 2, color, "→");
			break;

		}
	}

	if (cus == 1) {
		switch (envir)
		{
		case 0:
			DrawFormatString(FONTSIZE * 4, lun, color, "春");
			DrawFormatString(FONTSIZE * 4, lun += MAP_SIZE_X, color, "夏");
			DrawFormatString(FONTSIZE * 4, lun += MAP_SIZE_X, color, "秋");
			DrawFormatString(FONTSIZE * 4, lun += MAP_SIZE_X, color, "冬");
			break;
		case 1:
			DrawFormatString(FONTSIZE * 4, lun, color, "晴");
			DrawFormatString(FONTSIZE * 4, lun += MAP_SIZE_X, color, "雲");
			DrawFormatString(FONTSIZE * 4, lun += MAP_SIZE_X, color, "雨");
			break;

		case 2:
			DrawFormatString(FONTSIZE * 4, lun, color, "朝");
			DrawFormatString(FONTSIZE * 4, lun += MAP_SIZE_X, color, "昼");
			DrawFormatString(FONTSIZE * 4, lun += MAP_SIZE_X, color, "夜");

			break;

		}
		//変更する環境の詳細表示
		switch (change_e)
		{
		case 0:
			DrawFormatString(FONTSIZE * 2.5, com_scene, color, "→");
			break;
		case 1:
			DrawFormatString(FONTSIZE * 2.5, com_scene += MAP_SIZE_X, color, "→");
			break;

		case 2:
			DrawFormatString(FONTSIZE * 2.5, com_scene += MAP_SIZE_X * 2, color, "→");
			break;
		case 3:
			DrawFormatString(FONTSIZE * 2.5, com_scene += MAP_SIZE_X * 3, color, "→");
			break;
		}

	}
	return 0;
}

int character_draw(CHARA *player)
{

	int motion_index = player->act_motion[player->act_index];

	DrawGraph(player->chara_move_x, player->chara_move_y, player->chara_act[motion_index + player->act_dir * ACT_DIR_SLIDE], TRUE);

	return 0;
}

int chenge(void)
{
	switch (season_c)
	{
	case SEASON::SPLING:
		;
		break;
	case SEASON::SUMMER:
		;
		break;
	case SEASON::AUTUMN:
		;
		break;
	case SEASON::WINTER:
		;
		break;
	}
	switch (weather_c)
	{
	case WEATHER::SUNNY:
		;
		break;
	case WEATHER::CLOUD:
		;
		break;
	case WEATHER::RAIN:
		;
		break;
	}

	return 0;
}

