#include"main.h"
#include"game.h"
#include"Game_Init.h"
#include"Game_Input.h"
#include"Game_Update.h"
#include"Game_Draw.h"
#include"fps.h"

extern int game_scene;

int game(void)
{
	SetBackgroundColor(0, 255, 255);

	//�Q�[���V�[���̌J��Ԃ�
	while (CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		game_input();

		game_update();

		game_draw();

		//���[�v�I������
		if (game_scene != GAMESTAGE)
		{
			break;	//���[�v�E�o
		}

		fps_wait();//�t���[���̑ҋ@���v�Z

	//����ʂ�\��ʂ����ւ���
		ScreenFlip();

	}
	return 0;
}



