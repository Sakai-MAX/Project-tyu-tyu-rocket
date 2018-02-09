#pragma once
//*****************************************************************************
//  Class
//*****************************************************************************
class Tyutyu
{
private:
    ID3D11ShaderResourceView* texture_;     //�e�N�X�`��
    ID3D11ShaderResourceView* texture2_;     //�e�N�X�`��2
    ID3D11ShaderResourceView* texture3_;     //�e�N�X�`��3
    ID3D11ShaderResourceView* texture4_;     //�e�N�X�`��4
    ID3D11ShaderResourceView* texture5_;     //�e�N�X�`��5
    ID3D11ShaderResourceView* texture6_;     //�e�N�X�`��6
    ID3D11ShaderResourceView* texture7_;     //�e�N�X�`��7
    ID3D11ShaderResourceView* texture8_;     //�e�N�X�`��8
    ID3D11ShaderResourceView* texture9_;     //�e�N�X�`��9

    SpriteEffects direction_;   // �X�v���C�g�G�t�F�N�g�i�����j
    Vector2 position_;          // ���W
    Vector2 terget_position_;   // �I�̍��W
    Vector2 copy_ball_position_;// �C�e�̍��W�i�R�s�[�j
    Vector2 clear_position_;   // �N���A�̍��W
    Vector2 message_vec_;      // ���b�Z�[�W���W

    RECT    trim_;              // �J�[�\��
    RECT    trim2_;             // �J�[�\��������
    RECT    trim3_;
    RECT    trim4_;
    RECT    trim5_;
    RECT    clear_trim_;        // �N���A�̕`��͈�
    RECT    message_trim_;      // ���b�Z�[�W�`��͈�

    LONG   anime_no;                       //�`��NUM
    LONG  anime_counter;                   // �`��J�E���^�[

    bool atx;
    bool aty;
    bool btx;
    bool bty;


    bool    shooting_;
    bool    terget_hit_flag_;

    float   kMoveSpeed;

    float a;
    float w;
    float s;
    float d;


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

public:
    Tyutyu();       // �R���X�g���N�^
    ~Tyutyu();      // �f�X�g���N�^
    bool init();   // ������
    bool update(); // �X�V����
    void draw();   // �`��
    void destroy(); //�j��
};