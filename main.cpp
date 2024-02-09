#include"main.h"

int game_scene = TITLE;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//初期化処理
	ChangeWindowMode(TRUE);

	if (DxLib_Init() == -1)
	{
		return -1;
	}

	// フルスクリーンウインドウの切り替えでリソースが消えるのを防ぐ。
	SetChangeScreenModeGraphicsSystemResetFlag(FALSE);


	//ダブルバッファ開始
	SetDrawScreen(DX_SCREEN_BACK);

	//画面の大きさ
	SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32);

	//描画範囲の設定
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



