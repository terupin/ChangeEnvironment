#include"main.h"
#include"fps.h"
#include"title.h"

extern int game_scene;
//キーボード入力の情報を取得
char buf[NUM_KEYS];								//キーボードの押下チェック用
char buf_old[NUM_KEYS];							//前フレームのキーボードの押下チェック用

int title_update(char*buf, char* buf_old, int *game_scene);


int title(void)
{


	//全てのキー押下状態を取得
	int CheckHitKeyAll(int CheckType = DX_CHECKINPUT_ALL);

	//カーソル初期化
	int cus = 0;

	while (CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		title_input(buf, buf_old);

		title_update(buf, buf_old, &game_scene);

		title_draw();

		//ループ終了判定
		if (game_scene != TITLE)
		{
			break;	//ループ脱出
		}

		fps_wait();//フレームの待機を計算

	//裏画面を表画面を入れ替える
		ScreenFlip();
	}
	return 0;
}

int title_input(char*buf, char* buf_old)
{
	//前フレームのキーボード入力情報を確保
		//これがないと、押しっぱなしの時に反応してしまう
	memcpy(buf_old, buf, 256);

	//キーボード入力の情報を取得
	GetHitKeyStateAll(buf);
	return 0;
}

int title_update(char*buf, char* buf_old, int *game_scene)
{
	//ゲーム画面移動
	if ((buf[KEY_INPUT_RETURN] == 1) && (buf_old[KEY_INPUT_RETURN] == 0))
	{
		//ROMが出来次第、ゲーム選択画面に変更する
		*game_scene = GAMECOHICE;
	}

	return 0;
}

int title_draw(void)
{
	//画面消去
	ClearDrawScreen();

	SetFontSize(FONTSIZE);

	SetBackgroundColor(0, 0, 0);


	DrawFormatString(350, 300, WHITE_COLOR, "Change-Enviornment");
	DrawFormatString(START_X, START_Y, WHITE_COLOR, "ENTERキーを押して　PLAY START");
	DrawFormatString(START_X, START_Y + FONTSIZE, WHITE_COLOR, "ESCキーを押して　CLOSE");

	return 0;
}