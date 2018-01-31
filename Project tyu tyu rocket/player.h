#pragma once
//*****************************************************************************
//  Class
//*****************************************************************************
#include "title.h"
class Player
{
private:
    ID3D11ShaderResourceView* texture_;     //�e�N�X�`��
    ID3D11ShaderResourceView* texture2_;
    SpriteEffects direction_;   // �X�v���C�g�G�t�F�N�g�i�����j
    Vector2 position_;          // ���W
    Vector2 position2_;
    Vector2 position3_;
    Vector2 position4_;
    Vector2 terget_position_;   // �I�̍��W
    Vector2 copy_ball_position_;// �C�e�̍��W�i�R�s�[�j
    Vector2 clear_position_;   // �N���A�̍��W
    Vector2 message_vec_;      // ���b�Z�[�W���W

    RECT    trim_;              // �`��͈�
    RECT    trim2_;
    RECT    trim3_;
    RECT    trim4_;
    RECT    trim5_;
    RECT    clear_trim_;        // �N���A�̕`��͈�
    RECT    message_trim_;      // ���b�Z�[�W�`��͈�


    bool    shooting_;
    bool    terget_hit_flag_;
    float rotate_;
    float crad;
    float   terget_radius_;     // �^�[�Q�b�g�̔��a
    float   ball_radius_;       // �C�e�̔��a

    float x, y;
    float rad;
    float length;
    float length2;
    int count;
    int count2;
    int i;
    int j;
    float ry;
    float rx;
    float ry2;
    float rx2;
    int randam;

    int hit_count;

    Title title_;

public:
    Player();       // �R���X�g���N�^
    ~Player();      // �f�X�g���N�^
    bool init();   // ������
    bool update(); // �X�V����
    void draw();   // �`��
    void destroy(); //�j��
    static bool ret;    //�߂�l�p
    static bool doku;
    static bool syuuryou;

};