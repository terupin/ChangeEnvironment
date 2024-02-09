#include"main.h"
#include"fps.h"
#include"title.h"

extern int game_scene;
//�L�[�{�[�h���͂̏����擾
char buf[NUM_KEYS];								//�L�[�{�[�h�̉����`�F�b�N�p
char buf_old[NUM_KEYS];							//�O�t���[���̃L�[�{�[�h�̉����`�F�b�N�p

int title_update(char*buf, char* buf_old, int *game_scene);


int title(void)
{


	//�S�ẴL�[������Ԃ��擾
	int CheckHitKeyAll(int CheckType = DX_CHECKINPUT_ALL);

	//�J�[�\��������
	int cus = 0;

	while (CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		title_input(buf, buf_old);

		title_update(buf, buf_old, &game_scene);

		title_draw();

		//���[�v�I������
		if (game_scene != TITLE)
		{
			break;	//���[�v�E�o
		}

		fps_wait();//�t���[���̑ҋ@���v�Z

	//����ʂ�\��ʂ����ւ���
		ScreenFlip();
	}
	return 0;
}

int title_input(char*buf, char* buf_old)
{
	//�O�t���[���̃L�[�{�[�h���͏����m��
		//���ꂪ�Ȃ��ƁA�������ςȂ��̎��ɔ������Ă��܂�
	memcpy(buf_old, buf, 256);

	//�L�[�{�[�h���͂̏����擾
	GetHitKeyStateAll(buf);
	return 0;
}

int title_update(char*buf, char* buf_old, int *game_scene)
{
	//�Q�[����ʈړ�
	if ((buf[KEY_INPUT_RETURN] == 1) && (buf_old[KEY_INPUT_RETURN] == 0))
	{
		//ROM���o������A�Q�[���I����ʂɕύX����
		*game_scene = GAMECOHICE;
	}

	return 0;
}

int title_draw(void)
{
	//��ʏ���
	ClearDrawScreen();

	SetFontSize(FONTSIZE);

	SetBackgroundColor(0, 0, 0);


	DrawFormatString(350, 300, WHITE_COLOR, "Change-Enviornment");
	DrawFormatString(START_X, START_Y, WHITE_COLOR, "ENTER�L�[�������ā@PLAY START");
	DrawFormatString(START_X, START_Y + FONTSIZE, WHITE_COLOR, "ESC�L�[�������ā@CLOSE");

	return 0;
}