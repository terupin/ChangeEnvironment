#include"main.h"

int snow;
int sakura;
int leaf;
int rain;
int cloud;
int sun;
int fire;

int chip[NUM_CHIP_ALL]; //マップチップの数
//プレイヤー設定
CHARA player = { CHARA_STRAT_X, CHARA_STRAT_Y, 4.00, 0, 1, 0, 0, {0,1,2,3,4,5,6,7,8,9,10,11}, { 0, 1, 2, 1}, 0, 2 };

int game_init(void)
{
	map_init();
	chara_init(&player);


	return 0;
}

int map_init(void)
{
	//マップチップの分割
	LoadDivGraph("マップチップ.bmp", NUM_CHIP_ALL, NUM_CHIP_X, NUM_CHIP_Y, MAP_SIZE_X, MAP_SIZE_Y, chip);

	return 0;
}
int chara_init(CHARA *player)
{
	//キャラのロード設定（ファイル名,全部の絵の数, 横の数, 縦の数,キャラの横サイズ, キャラの縦サイズ,配列の名前)
	LoadDivGraph("syuzinnkou.png", CHARA_CHIP_ALL, CHARA_CHIP_X, CHARA_CHIP_Y, CHARA_WIDTH, CHARA_HEIGHT, player->chara_act);

	return 0;
}
