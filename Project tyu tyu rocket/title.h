#pragma once
//Class
class Title
{
private:
    ID3D11ShaderResourceView * texture_;   //�e�N�X�`��
    SpriteEffects             direction_; // �X�v���C�g�G�t�F�N�g�i�����j


    Vector2 position_;
    Vector2 position2_;
    Vector2 position3_;
    Vector2 position4_;
    Vector2 position5_;

    RECT trim_;
    RECT trim2_;
    RECT trim3_;
    RECT trim4_;
    RECT trim5_;

    float rx1;
    float ry1;
    float rx2;
    float ry2;
    float rx3;
    float ry3;
    float rx4;
    float ry4;


    bool ret;

    bool thn;  // �ҋ@�J�E���g
    int  txc;    // �����x

public:
    Title();            //�R���X�g���N�^
    ~Title();           //�f�X�g���N�^
    bool init();        //������
    bool update();      //�X�V����
    void draw();         //�j��
    void destroy();     //�j��
};