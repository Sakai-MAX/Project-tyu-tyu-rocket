//////////////////////////////
// ���b�Z�[�W�{�b�N�X�̕\�� //
//////////////////////////////
#include"error.h"

void Error::showDialog( wchar_t* Message )
{
    //�����Ŏ󂯎�������b�Z�[�W��\��
    MessageBox(
        NULL,                   //�E�B���h�E�n���h��
        Message,                //�\�����郁�b�Z�[�W
        L"ERROR",               //�^�C�g���ɕ\�����镶����
        MB_OK | MB_ICONERROR | MB_ICONSTOP | MB_TASKMODAL );   //�_�C�A���O�^�C�v
}

