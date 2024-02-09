#include"Game_Update.h"

int change_e = 0;  //矢印表示
int envir = -1;  //細部環境内容決定
int cus = -1;
int season_c = SEASON::SPLING;
int weather_c = WEATHER::SUNNY;
int day_c = DAY::LUNCH;
int now_season = SEASON::SPLING;
int now_weather = WEATHER::SUNNY;
int now_day = DAY::MONING;
float x = 300.0f;
float y = 300.0f;
int no_up = 1;//地面にいるか
int effect_go = 1;//エフェクトを一回だけ読むため

//キーボード入力の情報を取得
extern char buf[NUM_KEYS];								//キーボードの押下チェック用
extern char buf_old[NUM_KEYS];							//前フレームのキーボードの押下チェック用
extern int no_up;
extern int game_scene;
extern int stage_nonber;

//エフェクト
extern int snow;
extern int sakura;
extern int leaf;
extern int rain;
extern int cloud;
extern int effect_go;
extern int sun;
extern int fire;

//マップ情報
extern int data_1[];
extern int data_2[];
extern int data_3[];
extern int data_4[];
extern int data1_2_1[];
extern int data1_2_2[];
extern int data1_2_3[];
extern int data1_2_4[];
extern int data1_3_1[];
extern int data1_3_2[];
extern int data1_3_3[];
extern int data1_3_4[];
extern int data1_4_1[];
extern int data1_4_2[];
extern int data1_4_3[];
extern int data1_4_4[];
extern int data1_5_1[];
extern int data1_5_2[];
extern int data1_5_3[];
extern int data1_5_4[];
extern int data1_6_1[];
extern int data1_6_2[];
extern int data1_6_3[];
extern int data1_6_4[];
extern int data1_7_1[];
extern int data1_7_2[];
extern int data1_7_3[];
extern int data1_7_4[];
extern int data1_8_1[];
extern int data1_8_2[];
extern int data1_8_3[];
extern int data1_8_4[];


extern CHARA player;

int game_update(void)
{
	cus_update(buf, buf_old, &change_e, &envir, &cus, &season_c, &weather_c, &day_c);
	diside(buf, buf_old, &change_e, &envir, &cus, &season_c, &weather_c, &day_c);
	chara_update(buf, buf_old, &player, &weather_c, &day_c, &game_scene);
	map_col(&player, &game_scene, &season_c, &stage_nonber);

	return 0;
}

int cus_update(char *buf, char *buf_old, int *change_e, int *envir, int *cus, int *season_c, int *weather_c, int *day_c)
{

	//文字表示
	if ((buf[KEY_INPUT_M] == 1) && (buf_old[KEY_INPUT_M] == 0))
	{
		*cus = 0;
	}

	//季節・天候・昼夜の隣のカーソル
	if (*cus == 0)
	{
		//カーソルを下に移動
		if ((buf[KEY_INPUT_DOWN] == 1) && (buf_old[KEY_INPUT_DOWN] == 0))
		{
			//カーソルNo.を増やす
			*change_e += 1;

			//カーソルが下に限界が来たとき
			if (*change_e >= 3)
			{
				*change_e = 2;
			}
		}
		if ((buf[KEY_INPUT_UP] == 1) && (buf_old[KEY_INPUT_UP] == 0))
		{
			//カーソルNo,を減らす
			*change_e -= 1;

			//カーソルが上に限界が来たとき
			if (*change_e <= -1)

			{
				*change_e = 0;
			}
		}

		//コマンド決定
		if ((buf[KEY_INPUT_RIGHT] == 1) && (buf_old[KEY_INPUT_RIGHT] == 0))
		{
			*cus = 1;

			if (*change_e == 0)
			{
				*envir = 0;
				*change_e = 0;
			}
			if (*change_e == 1)
			{
				*envir = 1;
				*change_e = 0;
			}
			if (*change_e == 2)
			{
				*envir = 2;
				*change_e = 0;
			}

		}
	}

	//季節
	if (*cus == 1 && *envir == 0)
	{
		//カーソルを下に移動
		if ((buf[KEY_INPUT_DOWN] == 1) && (buf_old[KEY_INPUT_DOWN] == 0))
		{
			//カーソルNo.を増やす
			*change_e += 1;

			//カーソルが下に限界が来たとき
			if (*change_e >= 4)
			{
				*change_e = 3;
			}
		}
		else if ((buf[KEY_INPUT_UP] == 1) && (buf_old[KEY_INPUT_UP] == 0))
		{
			//カーソルNo,を減らす
			*change_e -= 1;

			//カーソルが上に限界が来たとき
			if (*change_e <= -1)
			{
				*change_e = 0;
			}
		}
	}

	//天候
	if (*cus == 1 && *envir == 1)
	{
		//カーソルを下に移動
		if ((buf[KEY_INPUT_DOWN] == 1) && (buf_old[KEY_INPUT_DOWN] == 0))
		{
			//カーソルNo.を増やす
			*change_e += 1;

			//カーソルが下に限界が来たとき
			if (*change_e >= 3)
			{
				*change_e = 2;
			}
		}
		else if ((buf[KEY_INPUT_UP] == 1) && (buf_old[KEY_INPUT_UP] == 0))
		{
			//カーソルNo,を減らす
			*change_e -= 1;

			//カーソルが上に限界が来たとき
			if (*change_e <= -1)
			{
				*change_e = 0;
			}
		}

	}

	//昼夜
	if (*cus == 1 && *envir == 2)
	{
		//カーソルを下に移動
		if ((buf[KEY_INPUT_DOWN] == 1) && (buf_old[KEY_INPUT_DOWN] == 0))
		{
			//カーソルNo.を増やす
			*change_e += 1;

			//カーソルが下に限界が来たとき
			if (*change_e >= 3)
			{
				*change_e = 2;
			}
		}
		else if ((buf[KEY_INPUT_UP] == 1) && (buf_old[KEY_INPUT_UP] == 0))
		{
			//カーソルNo,を減らす
			*change_e -= 1;

			//カーソルが上に限界が来たとき
			if (*change_e <= -1)
			{
				*change_e = 0;
			}

		}
	}

	//コマンドを一つ戻る
	if (buf[KEY_INPUT_BACK] == 1 && buf_old[KEY_INPUT_BACK] == 0)
	{
		*cus -= 1;
		if (*cus < -1)
		{
			*cus = -1;
		}
	}
	return 0;
}

int diside(char *buf, char *buf_old, int *change_e, int *envir, int *cus, int *season_c, int *weather_c, int *day_c)
{
	//季節決定
	if ((buf[KEY_INPUT_RETURN] == 1) && (buf_old[KEY_INPUT_RETURN] == 0) && *cus == 1 && *envir == 0)
	{

		for (int i = 0; i <= SEASON::WINTER; i++)
		{
			if (*change_e == i)
			{
				*season_c = i;
			}
		}
		if (*season_c != now_season)
		{
			effect_go = 0;
			now_season = *season_c;
		}
	}

	//天候決定
	if ((buf[KEY_INPUT_RETURN] == 1) && (buf_old[KEY_INPUT_RETURN] == 0) && *cus == 1 && *envir == 1)
	{
		for (int i = 0; i <= WEATHER::RAIN; i++)
		{
			if (*change_e == i)
			{
				*weather_c = i;
			}
		}
	}
	if (now_weather != *weather_c)
	{
		effect_go = 0;
		now_weather = *weather_c;
	}

	//昼夜決定
	if ((buf[KEY_INPUT_RETURN] == 1) && (buf_old[KEY_INPUT_RETURN] == 0) && *cus == 1 && *envir == 2)
	{
		for (int i = 0; i <= DAY::NIGHT; i++)
		{
			if (*change_e == i)
			{
				*day_c = i;
				//背景の色を変更
				switch (*day_c)
				{
				case MONING:
					SetBackgroundColor(175, 238, 238);
					break;
				case LUNCH:
					SetBackgroundColor(0, 255, 255);
					break;
				case NIGHT:
					SetBackgroundColor(0, 0, 128);
					break;
				}
			}
		}
	}
	if (now_day != *day_c)
	{
		now_day = *day_c;
		effect_go = 0;
	}

	// Effekseerにより再生中のエフェクトを更新する。
	UpdateEffekseer2D();

	return 0;
}

int chara_update(char *buf, char *buf_old, CHARA *player, int *weather_c, int *day_c, int *game_scene)
{
	int act_wait = ACT_SPEED;

	//一個前の位置を記憶
	player->old_x = player->chara_move_x;
	player->old_y = player->chara_move_y;

	if (player->yadd > 30)
	{
		player->yadd = 30;
	}

	//ADキーで左右操作、spaceキーでジャンプをする
	if (buf[KEY_INPUT_D] == 1)
	{
		switch (*weather_c)
		{
		case SUNNY:
			player->chara_move_x += player->speed;
			break;
		case CLOUD:
			player->chara_move_x += player->speed * 2;
			break;
		case RAIN:
			player->chara_move_x += player->speed / 2;
			break;
		}
		player->act_dir = 2;
	}
	if (buf[KEY_INPUT_A] == 1)
	{
		switch (*weather_c)
		{
		case SUNNY:
			player->chara_move_x -= player->speed;
			break;
		case CLOUD:
			player->chara_move_x -= player->speed * 2;
			break;
		case RAIN:
			player->chara_move_x -= player->speed / 2;
			break;
		}
		player->act_dir = 1;
	}
	if ((buf[KEY_INPUT_SPACE] == 1) && (buf_old[KEY_INPUT_SPACE] == 0) && (no_up) == 1)  //ジャンプ
	{
		no_up = 0;
		switch (*day_c)
		{
		case MONING:
			player->yadd = -12.00f;
			break;
		case LUNCH:
			player->yadd = -10.00f;
			break;
		case NIGHT:
			player->yadd = -7.00f;
			break;
		}
	}

	player->chara_move_y += player->yadd;
	player->yadd += 0.5f;

	// yadd を -30 ～ 30 に収める
	player->yadd = (std::min)(30.0f, (std::max)(-30.0f, player->yadd));

	//キャラアニメ更新
	if (--act_wait <= 0)
	{
		player->act_index++;
		act_wait = ACT_SPEED;
		player->act_index %= MAX_MOTION_INDEX;  //どの番号の画像を映しているか
	}
	if (player->chara_move_y > SCREEN_HEIGHT)
	{
		*game_scene = CONTINUE;
	}


	return 0;

}

int map_col(CHARA *player, int *game_scene, int *season_c, int *stage_nonber)
{
	// ブロックの当たり判定
	for (int j = 0; j < NUM_MAP_Y; j++)
	{
		for (int i = 0; i < NUM_MAP_X; i++)
		{
			int no;
			//ステージの何面を当たり判定をしているか
			switch (*stage_nonber)
			{
			case FIRST:
				switch (*season_c)
				{
				case SEASON::SPLING:
					no = data_1[i + j * NUM_MAP_X];
					break;
				case SEASON::SUMMER:
					no = data_2[i + j * NUM_MAP_X];
					break;
				case SEASON::AUTUMN:
					no = data_3[i + j * NUM_MAP_X];
					break;
				case SEASON::WINTER:
					no = data_4[i + j * NUM_MAP_X];
					break;
				}
				break;
			case SECOND:
				switch (*season_c)
				{
				case SEASON::SPLING:
					no = data1_2_1[i + j * NUM_MAP_X];
					break;
				case SEASON::SUMMER:
					no = data1_2_2[i + j * NUM_MAP_X];
					break;
				case SEASON::AUTUMN:
					no = data1_2_3[i + j * NUM_MAP_X];
					break;
				case SEASON::WINTER:
					no = data1_2_4[i + j * NUM_MAP_X];
					break;
				}
				break;
			case THIRD:
				switch (*season_c)
				{
				case SEASON::SPLING:
					no = data1_3_1[i + j * NUM_MAP_X];
					break;
				case SEASON::SUMMER:
					no = data1_3_2[i + j * NUM_MAP_X];
					break;
				case SEASON::AUTUMN:
					no = data1_3_3[i + j * NUM_MAP_X];
					break;
				case SEASON::WINTER:
					no = data1_3_4[i + j * NUM_MAP_X];
					break;
				}
				break;
			case FOUR:
				switch (*season_c)
				{
				case SEASON::SPLING:
					no = data1_4_1[i + j * NUM_MAP_X];
					break;
				case SEASON::SUMMER:
					no = data1_4_2[i + j * NUM_MAP_X];
					break;
				case SEASON::AUTUMN:
					no = data1_4_3[i + j * NUM_MAP_X];
					break;
				case SEASON::WINTER:
					no = data1_4_4[i + j * NUM_MAP_X];
					break;
				}
				break;
			case FIVE:
				switch (*season_c)
				{
				case SEASON::SPLING:
					no = data1_5_1[i + j * NUM_MAP_X];
					break;
				case SEASON::SUMMER:
					no = data1_5_2[i + j * NUM_MAP_X];
					break;
				case SEASON::AUTUMN:
					no = data1_5_3[i + j * NUM_MAP_X];
					break;
				case SEASON::WINTER:
					no = data1_5_4[i + j * NUM_MAP_X];
					break;
				}
				break;
			case SIX:
				switch (*season_c)
				{
				case SEASON::SPLING:
					no = data1_6_1[i + j * NUM_MAP_X];
					break;
				case SEASON::SUMMER:
					no = data1_6_2[i + j * NUM_MAP_X];
					break;
				case SEASON::AUTUMN:
					no = data1_6_3[i + j * NUM_MAP_X];
					break;
				case SEASON::WINTER:
					no = data1_6_4[i + j * NUM_MAP_X];
					break;
				}
				break;
			case SEVEN:
				switch (*season_c)
				{
				case SEASON::SPLING:
					no = data1_7_1[i + j * NUM_MAP_X];
					break;
				case SEASON::SUMMER:
					no = data1_7_2[i + j * NUM_MAP_X];
					break;
				case SEASON::AUTUMN:
					no = data1_7_3[i + j * NUM_MAP_X];
					break;
				case SEASON::WINTER:
					no = data1_7_4[i + j * NUM_MAP_X];
					break;
				}
				break;
			case EIGHT:
				switch (*season_c)
				{
				case SEASON::SPLING:
					no = data1_8_1[i + j * NUM_MAP_X];
					break;
				case SEASON::SUMMER:
					no = data1_8_2[i + j * NUM_MAP_X];
					break;
				case SEASON::AUTUMN:
					no = data1_8_3[i + j * NUM_MAP_X];
					break;
				case SEASON::WINTER:
					no = data1_8_4[i + j * NUM_MAP_X];
					break;
				}
				break;
			}

			if (no >= 0 && no <= 20)
			{
				if (CheckHit(i * MAP_SIZE_X, j *  MAP_SIZE_Y, MAP_SIZE_X, MAP_SIZE_Y, player->chara_move_x, player->chara_move_y, CHARA_WIDTH, CHARA_HEIGHT))
				{
					no_up = 1;

					if (player->chara_move_y >= player->old_y) //地形よりも上からあたっているか
					{
						if (j*MAP_SIZE_Y - CHARA_HEIGHT >= player->old_y)
						{
							//地形に上からあたっている
							player->old_y = j * MAP_SIZE_Y - CHARA_HEIGHT;
							player->chara_move_y = player->old_y;
							player->yadd = 0.0f;
						}
						else
						{
							//地形の横からあたっている
							int _x = (std::max)(player->chara_move_x, player->old_x);
							_x /= MAP_SIZE_X;
							_x *= MAP_SIZE_X;
							player->chara_move_x = _x;
							player->old_x = _x;
							no_up = 0;
						}
					}
					// 下から当たっているかチェック
					else if (player->chara_move_y < player->old_y)
					{
						// 地形よりも下から当たっているかチェックする
						if ((j + 1)*MAP_SIZE_Y <= player->old_y)
						{
							//地形に下からあたっている
							player->old_y = (j + 1)*MAP_SIZE_Y;
							player->chara_move_y = player->old_y;
							player->yadd = 0.0f;
							no_up = 0;
						}
						else
						{
							// 地形の横から当たっている
							int _x = (std::max)(player->chara_move_x, player->old_x);
							_x /= MAP_SIZE_X;
							_x *= MAP_SIZE_X;
							player->chara_move_x = _x;
							player->old_x = _x;
							no_up = 0;
						}
					}
				}
			}
			if (no == 21)
			{
				if (CheckHit(i * MAP_SIZE_X, j *  MAP_SIZE_Y, MAP_SIZE_X, MAP_SIZE_Y, player->chara_move_x, player->chara_move_y, CHARA_WIDTH, CHARA_HEIGHT))
				{
					*game_scene = GOAL;
				}
			}
		}
	}
	return 0;
}

// 当たり判定を行う関数
// キャラ 左x1上 y1 横幅 w1 縦幅 h1
// 壁　左x2 上y2 横幅 w2  縦幅 h2
int CheckHit(float x1, float y1, float w1, float h1, float x2, float y2, float w2, float h2)
{
	float L1 = x1;        //左
	float R1 = x1 + w1;   //右（左＋横幅）
	float L2 = x2;        //左
	float R2 = x2 + w2;   //左（左＋横幅）

	if (R1 <= L2)
		return 0;
	if (R2 <= L1)
		return 0;

	float U1 = y1;      // 上
	float D1 = y1 + h1; // 下(上+縦幅)
	float U2 = y2;      // 上
	float D2 = y2 + h2; // 下(上+縦幅

	if (D1 <= U2)
		return 0;
	if (D2 <= U1)
		return 0;

	//それ以外は当たる
	return 1;
}






