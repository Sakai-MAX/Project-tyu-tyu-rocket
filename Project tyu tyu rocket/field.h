#pragma once
//���O���
using namespace DirectX;

//struct
struct Tile
{
    Vector2 position;       //���W
    RECT    trim;           //�`��͈�
    int     id;             //ID

                            //�R���X�g���N�^
    Tile()
    {
        position = Vector2( 0.0F );
        trim = RECT{ 0 };
        id = 0;
    }
};

//class
class Field
{
private:
    ID3D11ShaderResourceView* texture_;     //�e�N�X�`��
    Tile* tiles_;       //�^�C���\���̃|�C���^
    int width_, height_;        //�}�b�v�����A�c���i���j
    Vector2  pos;
	Vector2  position_;
    SpriteEffects direction_;   // �X�v���C�g�G�t�F�N�g�i�����j
    RECT    trim_;              // �`��͈�
	RECT    trim2_;              // �`��͈�

	float ac;
	float wc;
	float sc;
	float dc;
	int atx;
	int aty;

	float wct;
public:
    Field();            //�R���X�g���N�^
    ~Field();           //�f�X�g���N�^

    bool init();        //������
    void update();      //�X�V����
    void draw();        //�`��
    void destroy();

};