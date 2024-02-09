#include"main.h"

int game_scene = TITLE;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//����������
	ChangeWindowMode(TRUE);

	if (DxLib_Init() == -1)
	{
		return -1;
	}

	// �t���X�N���[���E�C���h�E�̐؂�ւ��Ń��\�[�X��������̂�h���B
	SetChangeScreenModeGraphicsSystemResetFlag(FALSE);


	//�_�u���o�b�t�@�J�n
	SetDrawScreen(DX_SCREEN_BACK);

	//��ʂ̑傫��
	SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32);

	//�`��͈͂̐ݒ�
	SetDrawArea(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

	int color = WHITE_COLOR;

	game_init();

	while (CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		switch (game_scene)
		{
		case TITLE:
			title();
			break;
		case GAMECOHICE:
			stage_no();
			break;
		case GAMESTAGE:
			game();
			break;
		case CONTINUE:
			conti();
			break;
		case GOAL:
			goal();
			break;
		}

	}

	DxLib_End();

	return 0;

}



