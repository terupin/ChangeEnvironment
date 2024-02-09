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
	//��ʏ���
	ClearDrawScreen();

	//���F
	unsigned int color = GetColor(255, 255, 255);

	extern int change_e;
	extern int envir;
	extern int cus;
	extern CHARA player;



	map_draw(&season_c);//�}�b�v
	character_draw(&player);  //�L����
	command(color, change_e, envir, cus);

	return 0;
}

int command(int color, int change_e, int envir, int cus)
{
	//�R�}���h�ꏊ
	int com_scene = 0;
	int lun = 0;  //�����̈ʒu

	//���؂�ւ��R�}���h�\��
	if (cus == 0)
	{
		//�ύX�����
		DrawFormatString(FONTSIZE, com_scene, color, "�G��");
		DrawFormatString(FONTSIZE, com_scene + MAP_SIZE_X, color, "�V��");
		DrawFormatString(FONTSIZE, com_scene + MAP_SIZE_X * 2, color, "����");

		//�ύX������̖��\��
		switch (change_e)
		{
		case 0:
			DrawFormatString(0, com_scene, color, "��");
			break;
		case 1:
			DrawFormatString(0, com_scene += MAP_SIZE_X, color, "��");
			break;

		case 2:
			DrawFormatString(0, com_scene += MAP_SIZE_X * 2, color, "��");
			break;

		}
	}

	if (cus == 1) {
		switch (envir)
		{
		case 0:
			DrawFormatString(FONTSIZE * 4, lun, color, "�t");
			DrawFormatString(FONTSIZE * 4, lun += MAP_SIZE_X, color, "��");
			DrawFormatString(FONTSIZE * 4, lun += MAP_SIZE_X, color, "�H");
			DrawFormatString(FONTSIZE * 4, lun += MAP_SIZE_X, color, "�~");
			break;
		case 1:
			DrawFormatString(FONTSIZE * 4, lun, color, "��");
			DrawFormatString(FONTSIZE * 4, lun += MAP_SIZE_X, color, "�_");
			DrawFormatString(FONTSIZE * 4, lun += MAP_SIZE_X, color, "�J");
			break;

		case 2:
			DrawFormatString(FONTSIZE * 4, lun, color, "��");
			DrawFormatString(FONTSIZE * 4, lun += MAP_SIZE_X, color, "��");
			DrawFormatString(FONTSIZE * 4, lun += MAP_SIZE_X, color, "��");

			break;

		}
		//�ύX������̏ڍו\��
		switch (change_e)
		{
		case 0:
			DrawFormatString(FONTSIZE * 2.5, com_scene, color, "��");
			break;
		case 1:
			DrawFormatString(FONTSIZE * 2.5, com_scene += MAP_SIZE_X, color, "��");
			break;

		case 2:
			DrawFormatString(FONTSIZE * 2.5, com_scene += MAP_SIZE_X * 2, color, "��");
			break;
		case 3:
			DrawFormatString(FONTSIZE * 2.5, com_scene += MAP_SIZE_X * 3, color, "��");
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

