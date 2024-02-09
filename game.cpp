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

	//ゲームシーンの繰り返し
	while (CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		game_input();

		game_update();

		game_draw();

		//ループ終了判定
		if (game_scene != GAMESTAGE)
		{
			break;	//ループ脱出
		}

		fps_wait();//フレームの待機を計算

	//裏画面を表画面を入れ替える
		ScreenFlip();

	}
	return 0;
}



