#include"Stage_No.h"

extern char buf[NUM_KEYS];								//キーボードの押下チェック用
extern char buf_old[NUM_KEYS];							//前フレームのキーボードの押下チェック用
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

		//ループ終了判定
		if (game_scene != GAMECOHICE)
		{
			break;	//ループ脱出
		}

		fps_wait();//フレームの待機を計算

	//裏画面を表画面を入れ替える
		ScreenFlip();
	}
	return 0;

}

int stage_no_input(char *buf, char *buf_old)
{
	//前フレームのキーボード入力情報を確保
//これがないと、押しっぱなしの時に反応してしまう
	memcpy(buf_old, buf, 256);

	//キーボード入力の情報を取得
	GetHitKeyStateAll(buf);

	return 0;
}

int stage_no_update(char *buf, char *buf_old, int *game_scene, CHARA *player, int *stage_cos, int *stage_nonber)
{
	//カーソルを下に移動
	if ((buf[KEY_INPUT_DOWN] == 1) && (buf_old[KEY_INPUT_DOWN] == 0))
	{
		//カーソルNo.を増やす
		*stage_cos += 1;

		//カーソルが下に限界が来たとき
		if (*stage_cos >= 8)
		{
			*stage_cos = EIGHT;
		}
	}
	if ((buf[KEY_INPUT_UP] == 1) && (buf_old[KEY_INPUT_UP] == 0))
	{
		//カーソルNo,を減らす
		*stage_cos -= 1;

		//カーソルが上に限界が来たとき
		if (*stage_cos <= -1)
		{
			*stage_cos = FIRST;
		}
	}
	//ゲーム画面移動
	if ((buf[KEY_INPUT_RETURN] == 1) && (buf_old[KEY_INPUT_RETURN] == 0))
	{
		*stage_nonber = *stage_cos;
		*game_scene = GAMESTAGE;
	}

	return 0;
}

int stage_no_draw(int *stage_cos)
{
	//画面消去
	ClearDrawScreen();

	//変更する環境の詳細表示
	switch (*stage_cos)
	{
	case FIRST:
		DrawFormatString(300, 200, WHITE_COLOR, "→");
		break;
	case SECOND:
		DrawFormatString(300, 300, WHITE_COLOR, "→");
		break;
	case THIRD:
		DrawFormatString(300, 400, WHITE_COLOR, "→");
		break;
	case FOUR:
		DrawFormatString(300, 500, WHITE_COLOR, "→");
		break;
	case FIVE:
		DrawFormatString(500, 200, WHITE_COLOR, "→");
		break;
	case SIX:
		DrawFormatString(500, 300, WHITE_COLOR, "→");
		break;
	case SEVEN:
		DrawFormatString(500, 400, WHITE_COLOR, "→");
		break;
	case EIGHT:
		DrawFormatString(500, 500, WHITE_COLOR, "→");
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



