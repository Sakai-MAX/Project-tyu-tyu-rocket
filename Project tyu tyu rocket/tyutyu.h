#pragma once
//*****************************************************************************
//  Class
//*****************************************************************************
class Tyutyu
{
private:
    ID3D11ShaderResourceView* texture_; // �V�F�[�_���\�[�X�r���[
    ID3D11ShaderResourceView* texture_Mk2;
    SpriteEffects direction_;   // �X�v���C�g�G�t�F�N�g�i�����j
    Vector2 position_;          // ���W
    Vector2 position_Mk2;
    RECT    trim_;              // �`��͈�
    RECT    trimMk2_;
    RECT    trimMk3_;
    RECT    trimMk4_;
    RECT    trimMk5_;
    RECT    trimMk6_;
    RECT    trimMk7_;
    RECT    trimMk8_;

public:
    Tyutyu();       // �R���X�g���N�^
    ~Tyutyu();      // �f�X�g���N�^
    bool init();   // ������
    void update(); // �X�V����
    void draw();   // �`��
    void destroy(); //�j��
};