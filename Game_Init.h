#pragma once
#include "DxLib.h"

//�\����
struct CHARA
{
	float chara_move_x;    // �L�����̈ʒu��X��
	float chara_move_y;    // �L�����̈ʒu��Y��
	float speed;  //�ړ����x
	float yadd;  //����
	float gravity; //�d��
	float old_x;	// �O���X�ʒu
	float old_y;   // �O���X�ʒu
	int chara_act[12];  //�L�����摜����
	int act_motion[4]; //���[�V�����摜
	int act_index;   //���Ԃ̃��[�V�����摜��`�悷�邩
	int act_dir;  //����ڂ̃L�����摜

};

int map_init(void);
int chara_init(CHARA *player);
int game_init(void);

