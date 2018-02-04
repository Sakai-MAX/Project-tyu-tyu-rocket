#include "player.h"
#include "direct3d.h"
#include "texture.h"
#include "keyinput.h"
#include "padinput.h"
#include "sprite.h"
#include "release.h"
#include"font.h"
#include "title.h"
#include "field.h"

//�߂�l����
bool Player::ret;
bool Player::syuuryou;
bool Player::doku;
Vector2 Player::position_go;

//*****************************************************************************
//  �萔
//*****************************************************************************

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

    //�J�[�\�[��
    trim_.top = 0L;
    trim_.left = 669L;
    trim_.right = 714L;
    trim_.bottom = 47L;


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
    if( !(texture_ = Texture::load( L"TYUTYU10.png" )) )
    {
        // �G���[
        return false;
    }


    //�^�C�������̃������𓮓I�m��
    return true;
}

//*****************************************************************************
//  �X�V����
//*****************************************************************************
bool Player::update()
{
    //���͂��擾
    auto key = KeyInput::getState();
    auto key_tracker = KeyInput::getTracker();
    auto pad = PadInput::getTracker();
    auto kaiten = PadInput::State();
    x = kaiten.thumbSticks.leftX;
    y = kaiten.thumbSticks.leftY;
	//�J�[�\����
	Player::position_go = position_;

    //�A�i���O���͂�����ꍇ�݈̂ړ�
    if( x != 0.0F || y != 0.0F )
    {

        //�p�x���v�Z�i�߂�l�̓��W�A���j
        float rad = atan2( y, x );

        //�������v�Z
        float length = hypot( x, y );

        //�ړ�
        position_.x += cos( rad ) * length * 10.0F;
        position_.y -= sin( rad ) * length * 10.0F;

    }


    ////////////////////  A�{�^��  //////////////////////
    if( key_tracker.pressed.Z || pad.a == GamePad::ButtonStateTracker::HELD )
    {
   
    }

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
    /*Sprite::Draw(
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
    );*/

    //�J�[�\��
    Sprite::Draw(
        texture_,
        position_,
        &trim_,
        255,
        0.0F,
        direction_,
        Vector2( 1.0F, 1.0F ),
        Vector2( 0.0F, 0.0F )
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