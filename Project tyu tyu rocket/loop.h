#pragma once
//*****************************************************************************
//  Include
//*****************************************************************************

#include "player.h"
#include "game.h"
#include "title.h"

//�񋓑�
enum
{
    kTitleInit,     //�^�C�g��������
    kTitleUpdate,   //�^�C�g���X�V
    kGameInit,       //�Q�[��������
    kGameUpdate      //�Q�[���X�V
};
//*****************************************************************************
//  Class
//*****************************************************************************
class Loop
{
private:
    Game game_;     //�Q�[���V�[���N���X
    Title title_;     //�^�C�g���V�[���N���X
    int work_no_;       //��Ɣԍ�


    Player player_;   // �v���C���[�N���X

    bool init( const HINSTANCE hInstance ); // ������
    void draw();    // �`��

public:
    Loop();     // �R���X�g���N�^
    ~Loop();    // �f�X�g���N�^

    int update( const HINSTANCE hInstance ); // �X�V����
};