#include"main.h"
#include"Game_Input.h"

//�L�[�{�[�h���͂̏����擾
extern char buf[NUM_KEYS];								//�L�[�{�[�h�̉����`�F�b�N�p
extern char buf_old[NUM_KEYS];							//�O�t���[���̃L�[�{�[�h�̉����`�F�b�N�p

int game_input(void)
{
	key_input(buf, buf_old);

	return 0;
}

int key_input(char *buf, char *buf_old)
{

	//�O�t���[���̃L�[�{�[�h���͏����m��
	//���ꂪ�Ȃ��ƁA�������ςȂ��̎��ɔ������Ă��܂�
	memcpy(buf_old, buf, 256);

	//�L�[�{�[�h���͂̏����擾
	GetHitKeyStateAll(buf);

	return 0;

}