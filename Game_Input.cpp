#include"main.h"
#include"Game_Input.h"

//キーボード入力の情報を取得
extern char buf[NUM_KEYS];								//キーボードの押下チェック用
extern char buf_old[NUM_KEYS];							//前フレームのキーボードの押下チェック用

int game_input(void)
{
	key_input(buf, buf_old);

	return 0;
}

int key_input(char *buf, char *buf_old)
{

	//前フレームのキーボード入力情報を確保
	//これがないと、押しっぱなしの時に反応してしまう
	memcpy(buf_old, buf, 256);

	//キーボード入力の情報を取得
	GetHitKeyStateAll(buf);

	return 0;

}