#include "player.h"
#include "direct3d.h"
#include "texture.h"
#include "keyinput.h"
#include "sprite.h"
#include "release.h"
#include"font.h"
#include "title.h"

bool Player::ret;
bool Player::syuuryou;
bool Player::doku;

//*****************************************************************************
//  �萔
//*****************************************************************************
float rotation = 0.0F;
bool chase = true;  // �ǐՃt���O
const float radius = 32.0F;     //���a



                                //*****************************************************************************
                                //  �R���X�g���N�^
                                //*****************************************************************************
Player::Player()
{
    rx = (rand() % 1220) + 30.0F;
    ry = (rand() % 650) + 30.0F;
    rx2 = (rand() % 1220) + 30.0F;
    ry2 = (rand() % 650) + 30.0F;
    texture_ = NULL;
    position_ = Vector2( 46.0F, 424.0F );
    position2_ = Vector2( rx, ry );
    position3_ = Vector2( 0.0F, 0.0F );
    position4_ = Vector2( rx2, ry2 );
    message_vec_ = Vector2( 550.0F, 480.0F + 35.0F ); // ���b�Z�[�W�`��ʒu
    terget_position_ = Vector2( 200.0F, 370.0F );
    clear_position_ = Vector2( 210.0F, 100.0F );

    direction_ = SpriteEffects_None;

    clear_trim_ = { 256L ,85L, (256L + 256L), (55L + 120L) };
    message_trim_ = { 256L ,55L, (256L + 256L), (55L + 30L) };

    //��
    trim_.top = 450L;
    trim_.left = 390L;
    trim_.right = 450L;
    trim_.bottom = 511L;

    //���̂�1
    trim2_.top = 448L;
    trim2_.left = 196L;
    trim2_.right = 255L;
    trim2_.bottom = 511L;

    //���̂�2
    trim3_.top = 448L;
    trim3_.left = 260L;
    trim3_.right = 322L;
    trim3_.bottom = 511L;

    //�ˌ�
    shooting_ = false;
    i = 0;
    j = 0;

    // �I�ɓ����������ǂ���
    terget_hit_flag_ = false;

    terget_radius_ = 32.0F;   // �^�[�Q�b�g�̔��a
    ball_radius_ = 9.0F;    // �C�e�̔��a

    hit_count = 0;      //�q�b�g�J�E���g

    crad = 0.0F;

    Player::ret = true;    //�߂�l�p
    Player::syuuryou = true;
    Player::doku = true;

}

//*****************************************************************************
//  ������
//*****************************************************************************
bool Player::init()
{
    // �e�N�X�`���̓ǂݍ���
    if( !(texture_ = Texture::load( L"���̂����̒jex.png" )) )
    {
        // �G���[
        return false;
    }

    return true;
}

//*****************************************************************************
//  �X�V����
//*****************************************************************************
bool Player::update()
{

    //���̂��̏o���|�C���g�����_��
    rx = (rand() % 1220) + 30.0F;
    ry = (rand() % 650) + 30.0F;

    rx2 = (rand() % 1220) + 30.0F;
    ry2 = (rand() % 650) + 30.0F;


    //��
    trim_.top = 450L;
    trim_.left = 390L;
    trim_.right = 450L;
    trim_.bottom = 511L;

    //���͂��擾
    auto key = KeyInput::getState();
    auto key_tracker = KeyInput::getTracker();
    // �p�x���v�Z(�߂�l�̓��W�A��)
    rad = atan2( y, -x );
    // �������v�Z
    length = hypot( x, y );

    // �E�N���b�N���ꂽ��ǐՂ��Ȃ�(������x�����ꂽ�猳�ɖ߂�j

    return Player::syuuryou;
}
//*****************************************************************************
//  �`��
//*****************************************************************************
void Player::draw()
{
    // �X�v���C�g�`��
    auto key = KeyInput::getState();
    auto key_tracker = KeyInput::getTracker();

    //���̂�
    Sprite::Draw(
        texture_,
        position2_,
        &trim2_,
        255,
        0.0F,
        direction_,
        Vector2( 1.0F, 1.0F ),
        Vector2( 32.0F, 32.0F )
    );
    //���̂�2
    Sprite::Draw(
        texture_,
        position4_,
        &trim3_,
        255,
        0.0F,
        direction_,
        Vector2( 1.0F, 1.0F ),
        Vector2( 32.0F, 32.0F )
    );

    //��
    Sprite::Draw(
        texture_,
        position_,
        &trim_,
        255,
        0.0F,
        direction_,
        Vector2( 1.0F, 1.0F ),
        Vector2( 30.0F, 30.0F )
    );
}

void Player::destroy()
{
    //�e�N�X�`���ƃ������̉��
    SAFE_RELEASE( texture_ );
}

//*****************************************************************************
//  �f�X�g���N�^
//*****************************************************************************
Player::~Player()
{
    destroy();
}