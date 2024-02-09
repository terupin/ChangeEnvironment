#include"Stage_No.h"

extern char buf[NUM_KEYS];								//�L�[�{�[�h�̉����`�F�b�N�p
extern char buf_old[NUM_KEYS];							//�O�t���[���̃L�[�{�[�h�̉����`�F�b�N�p
extern int game_scene;
extern CHARA player;
extern int color;

int stage_nonber;
int stage_cos;

int stage_no(void)
{
	while (CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		stage_no_input(buf, buf_old);

		stage_no_update(buf, buf_old, &game_scene, &player, &stage_cos, &stage_nonber);

		stage_no_draw(&stage_cos);

		//���[�v�I������
		if (game_scene != GAMECOHICE)
		{
			break;	//���[�v�E�o
		}

		fps_wait();//�t���[���̑ҋ@���v�Z

	//����ʂ�\��ʂ����ւ���
		ScreenFlip();
	}
	return 0;

}

int stage_no_input(char *buf, char *buf_old)
{
	//�O�t���[���̃L�[�{�[�h���͏����m��
//���ꂪ�Ȃ��ƁA�������ςȂ��̎��ɔ������Ă��܂�
	memcpy(buf_old, buf, 256);

	//�L�[�{�[�h���͂̏����擾
	GetHitKeyStateAll(buf);

	return 0;
}

int stage_no_update(char *buf, char *buf_old, int *game_scene, CHARA *player, int *stage_cos, int *stage_nonber)
{
	//�J�[�\�������Ɉړ�
	if ((buf[KEY_INPUT_DOWN] == 1) && (buf_old[KEY_INPUT_DOWN] == 0))
	{
		//�J�[�\��No.�𑝂₷
		*stage_cos += 1;

		//�J�[�\�������Ɍ��E�������Ƃ�
		if (*stage_cos >= 8)
		{
			*stage_cos = EIGHT;
		}
	}
	if ((buf[KEY_INPUT_UP] == 1) && (buf_old[KEY_INPUT_UP] == 0))
	{
		//�J�[�\��No,�����炷
		*stage_cos -= 1;

		//�J�[�\������Ɍ��E�������Ƃ�
		if (*stage_cos <= -1)
		{
			*stage_cos = FIRST;
		}
	}
	//�Q�[����ʈړ�
	if ((buf[KEY_INPUT_RETURN] == 1) && (buf_old[KEY_INPUT_RETURN] == 0))
	{
		*stage_nonber = *stage_cos;
		*game_scene = GAMESTAGE;
	}

	return 0;
}

int stage_no_draw(int *stage_cos)
{
	//��ʏ���
	ClearDrawScreen();

	//�ύX������̏ڍו\��
	switch (*stage_cos)
	{
	case FIRST:
		DrawFormatString(300, 200, WHITE_COLOR, "��");
		break;
	case SECOND:
		DrawFormatString(300, 300, WHITE_COLOR, "��");
		break;
	case THIRD:
		DrawFormatString(300, 400, WHITE_COLOR, "��");
		break;
	case FOUR:
		DrawFormatString(300, 500, WHITE_COLOR, "��");
		break;
	case FIVE:
		DrawFormatString(500, 200, WHITE_COLOR, "��");
		break;
	case SIX:
		DrawFormatString(500, 300, WHITE_COLOR, "��");
		break;
	case SEVEN:
		DrawFormatString(500, 400, WHITE_COLOR, "��");
		break;
	case EIGHT:
		DrawFormatString(500, 500, WHITE_COLOR, "��");
		break;
	}

	DrawFormatString(300 + FONTSIZE * 1.5, 200, WHITE_COLOR, "1");
	DrawFormatString(300 + FONTSIZE * 1.5, 300, WHITE_COLOR, "2");
	DrawFormatString(300 + FONTSIZE * 1.5, 400, WHITE_COLOR, "3");
	DrawFormatString(300 + FONTSIZE * 1.5, 500, WHITE_COLOR, "4");
	DrawFormatString(500 + FONTSIZE * 1.5, 200, WHITE_COLOR, "5");
	DrawFormatString(500 + FONTSIZE * 1.5, 300, WHITE_COLOR, "6");
	DrawFormatString(500 + FONTSIZE * 1.5, 400, WHITE_COLOR, "7");
	DrawFormatString(500 + FONTSIZE * 1.5, 500, WHITE_COLOR, "8");

	return 0;
}



