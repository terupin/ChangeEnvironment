#pragma once
#include<DxLib.h>
#include<stdio.h>
#include<string.h>
#include <Windows.h>
#include"Game_Init.h"
#include"title.h"
#include"Stage_No.h"
#include"game.h"
#include"GOAL.h"
#include"Continue.h"
#include"fps.h"
// EffekseerForDXLib.h���C���N���[�h���܂��B
#include "EffekseerForDXLib.h"

//��ʕύX
typedef enum {
	TITLE,      //�^�C�g�����
	GAMECOHICE,   //�Q�[���I�����
	CONTINUE,  //�R���e�j���[���
	GAMESTAGE, //�Q�[����ʁi�����Ă�����������Ȃ��j�c�c�c�撣�ꉴ�c���Ȃ�ł���c
	GOAL,
}SCENE;

//�X�e�[�W��
typedef enum {
	FIRST,
	SECOND,
	THIRD,
	FOUR,
	FIVE,
	SIX,
	SEVEN,
	EIGHT
}STAGENOM;


#define	NUM_KEYS 256	//�L�[�̍ő吔
#define WHITE_COLOR  GetColor(255, 255, 255)       //���F

#define FONTSIZE 30     //�t�H���g�T�C�Y

#define START_X  250   //�^�C�g�����ʒu
#define START_Y  500   //�^�C�g���c�ʒu

#define SCREEN_WIDTH  960   //�X�e�[�W�����
#define SCREEN_HEIGHT 800   //�X�e�[�W�c���

//�}�b�v�`�b�v�֌W

#define MAP_SIZE_X 32   // �}�b�v�`�b�vX�T�C�Y
#define MAP_SIZE_Y  32	// �}�b�v�`�b�vY�T�C�Y
#define NUM_CHIP_X  10  // ��10���
#define NUM_CHIP_Y  4   // �c4���
#define NUM_CHIP_ALL  NUM_CHIP_X * NUM_CHIP_Y // 40��
#define NUM_MAP_X  30   //�}�b�v�`�b�v�T�C�Y*�X�e�[�W�����
#define NUM_MAP_Y  25   //�}�b�v�`�b�v�T�C�Y*�X�e�[�W�c���


//�L�����N�^�[�֌W

#define CHARA_WIDTH 32   // �}�b�v�`�b�vX�T�C�Y
#define CHARA_HEIGHT  32	// �}�b�v�`�b�vY�T�C�Y
#define CHARA_CHIP_X  3   // ��3���
#define CHARA_CHIP_Y  4   // �c4���
#define CHARA_CHIP_ALL  CHARA_CHIP_X*CHARA_CHIP_Y  //12���
#define ACT_DIR_SLIDE CHARA_CHIP_X

#define CHARA_STRAT_X 32    //�L�����̃X�^�[�g�ʒu�QX��
#define CHARA_STRAT_Y 608  //�L�����̃X�^�[�g�ʒu�QY��
#define MAX_MOTION_INDEX 4  // 0,1,2,1 ��4��� [0�`3]�܂łɂ��邽�߂ɗp��
#define ACT_SPEED 20       //�L�����N�^�[�̐i�ރX�s�[�h

//���ύX�̐��@0�`2�̎O��ށc�o����΂܂����₷�c�撣�ꉴ�A�Q�[���Ȃ�Ă���Ă�ɂȂ�
typedef enum {
	SPLING,  //�t
	SUMMER,  //��
	AUTUMN,  //�H
	WINTER,  //�~
}SEASON;
typedef enum {
	SUNNY,  //��
	CLOUD,   //�_
	RAIN,   //�J
}WEATHER;
typedef enum {
	MONING,  //��
	LUNCH,   //��
	NIGHT,   //��
}DAY;


//fps
#define FLAME 60

