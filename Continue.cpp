#include"Continue.h"

extern int season_c;
extern int weather_c;
extern int day_c;
extern char buf[NUM_KEYS];								//キーボードの押下チェック用
extern char buf_old[NUM_KEYS];							//前フレームのキーボードの押下チェック用
extern int game_scene;
extern CHARA player;

int conti(void)
{
	while (CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		conti_input(buf, buf_old);

		conti_update(buf, buf_old, &game_scene, &player, &season_c, &weather_c, &day_c);

		conti_draw();

		//ループ終了判定
		if (game_scene != CONTINUE)
		{
			break;	//ループ脱出
		}

		fps_wait();//フレームの待機を計算

	//裏画面を表画面を入れ替える
		ScreenFlip();
	}

	return 0;
}

int conti_input(char *buf, char *buf_old)
{
	//前フレームのキーボード入力情報を確保
	//これがないと、押しっぱなしの時に反応してしまう
	memcpy(buf_old, buf, 256);

	//キーボード入力の情報を取得
	GetHitKeyStateAll(buf);
	return 0;
}

int conti_update(char*buf, char* buf_old, int *game_scene, CHARA *player, int *season_c, int *weather_c, int *day_c)
{
	//コンテニュー画面移動
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


	return 0;
}

int conti_draw(void)
{
	//画面消去
	ClearDrawScreen();

	SetFontSize(FONTSIZE);

	SetBackgroundColor(0, 0, 0);

	DrawFormatString(400, 200, WHITE_COLOR, "GAME OVER");
	DrawFormatString(START_X, START_Y, WHITE_COLOR, "ENTERキーを押して　STAGE SELECT");
	DrawFormatString(START_X, START_Y + FONTSIZE, WHITE_COLOR, "ESCキーを押して　CLOSE");

	return 0;
}