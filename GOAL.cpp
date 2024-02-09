#include"GOAL.h"

extern int season_c;
extern int weather_c;
extern int day_c;
extern char buf[NUM_KEYS];								//�L�[�{�[�h�̉����`�F�b�N�p
extern char buf_old[NUM_KEYS];							//�O�t���[���̃L�[�{�[�h�̉����`�F�b�N�p
extern int game_scene;
extern CHARA player;

int goal(void)
{


	while (CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		goal_input(buf, buf_old);

		goal_update(buf, buf_old, &game_scene, &player, &season_c, &weather_c, &day_c);

		goal_draw();

		//���[�v�I������
		if (game_scene != GOAL)
		{
			break;	//���[�v�E�o
		}

		fps_wait();//�t���[���̑ҋ@���v�Z

	//����ʂ�\��ʂ����ւ���
		ScreenFlip();
	}
	return 0;

}

int goal_input(char *buf, char *buf_old)
{

	//�O�t���[���̃L�[�{�[�h���͏����m��
	//���ꂪ�Ȃ��ƁA�������ςȂ��̎��ɔ������Ă��܂�
	memcpy(buf_old, buf, 256);

	//�L�[�{�[�h���͂̏����擾
	GetHitKeyStateAll(buf);

	return 0;

}

int goal_update(char*buf, char* buf_old, int *game_scene, CHARA *player, int *season_c, int *weather_c, int *day_c)
{
	//�Q�[���N���A��ʈړ�
	if ((buf[KEY_INPUT_RETURN] == 1) && (buf_old[KEY_INPUT_RETURN] == 0))
	{
		*game_scene = GAMECOHICE;
	}

	player->chara_move_x = CHARA_STRAT_X;
	player->chara_move_y = CHARA_STRAT_Y;
	*season_c = SEASON::SPLING;
	*weather_c = WEATHER::SUNNY;
	*day_c = DAY::LUNCH;

	return 0;
}
int goal_draw(void)
{
	//��ʏ���
	ClearDrawScreen();

	SetFontSize(FONTSIZE);

	SetBackgroundColor(0, 0, 0);

	DrawFormatString(400, 200, WHITE_COLOR, "GAME CLERA");
	DrawFormatString(START_X, START_Y, WHITE_COLOR, "ENTER�L�[�������ā@STAGE SELECT");
	DrawFormatString(START_X, START_Y + FONTSIZE, WHITE_COLOR, "ESC�L�[�������ā@CLOSE");

	return 0;
}

