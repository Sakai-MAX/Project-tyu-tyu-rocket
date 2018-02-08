#include "player.h"
#include "direct3d.h"
#include "texture.h"
#include "keyinput.h"
#include "padinput.h"
#include "sprite.h"
#include "release.h"
#include "font.h"
#include "title.h"
#include "field.h"
#include "tyutyu.h"

//�߂�l����
/*bool Player::ret;
bool Player::syuuryou;
bool Player::doku;
Vector2 Player::position_go;

//*****************************************************************************
//  �萔
//*****************************************************************************

//*****************************************************************************
//  �R���X�g���N�^
//*****************************************************************************
Tyutyu::Tyutyu()
{
    rx = (rand() % 1220) + 30.0F;
    ry = (rand() % 650) + 30.0F;
    rx2 = (rand() % 1220) + 30.0F;
    ry2 = (rand() % 650) + 30.0F;
    texture_ = NULL;
    position_ = Vector2( 956.0F, 390.0F );
    position_at_ = Vector2( 36.0F, 36.0F );
    position2_ = Vector2( 884.0F, 318.0F );
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

    //�J�[�\�[��������
    trim2_.top = 144L;
    trim2_.left = 72L;
    trim2_.right = 144L;
    trim2_.bottom = 216L;


    terget_radius_ = 32.0F;   // �^�[�Q�b�g�̔��a
    ball_radius_ = 9.0F;    // �C�e�̔��a

    hit_count = 0;      //�q�b�g�J�E���g

    crad = 0.0F;

    //�v���X���J�E���^�[
    atx = false;
    aty = false;

    //�}�C�i�X���J�E���^�[
    btx = false;
    bty = false;

    Player::ret = true;    //�߂�l�p
    Player::syuuryou = true;
    Player::doku = true;

}

//*****************************************************************************
//  ������
//*****************************************************************************
bool Tyutyu::init()
{
    // �e�N�X�`���̓ǂݍ���
    if( !(texture_ = Texture::load( L"������۹�āi�{�[�h�ǉ��j.png" )) )
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
bool Tyutyu::update()
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
        position_.x += cos( rad ) * length;
        position_.y -= sin( rad ) * length;
        position_at_.x += cos( rad ) * length;
        position_at_.y -= sin( rad ) * length;
    }


    //�J�[�\���ړ�����
    if( position_at_.x > 72.0F )
    {
        position_at_.x = 0.0F;
        position2_.x += 72.0F;
    }

    if( position_at_.y > 72.0F )
    {
        position_at_.y = 0.0F;
        position2_.y += 72.0F;
    }

    if( position_at_.x < 0.0F )
    {
        position_at_.x = 72.0F;
        position2_.x -= 72.0F;
    }

    if( position_at_.y < 0.0F )
    {
        position_at_.y = 72.0F;
        position2_.y -= 72.0F;
    }

    ////////////////////  A�{�^��  //////////////////////
    if( key_tracker.pressed.Z || pad.a == GamePad::ButtonStateTracker::PRESSED )
    {

    }

    ////////////////////  ��  ///////////////////// 
    if( key.Up || pad.dpadUp == GamePad::ButtonStateTracker::PRESSED )
    {
        position2_.y -= 72.0F;
        position_.y -= 72.0F;
    }

    ////////////////////  ��  //////////////////////
    if( key.Down || pad.dpadDown == GamePad::ButtonStateTracker::PRESSED )
    {
        position2_.y += 72.0F;
        position_.y += 72.0F;
    }

    ///////////////////   ��   ////////////////////
    if( key.Left || pad.dpadLeft == GamePad::ButtonStateTracker::PRESSED )
    {
        position2_.x -= 72.0F;
        position_.x -= 72.0F;
    }

    ///////////////////   �E   ////////////////////
    if( key.Right || pad.dpadRight == GamePad::ButtonStateTracker::PRESSED )
    {
        position2_.x += 72.0F;
        position_.x += 72.0F;
    }

    // �p�x���v�Z(�߂�l�̓��W�A��)
    rad = atan2( y, -x );
    // �������v�Z
    length = hypot( x, y );

    // �E�N���b�N���ꂽ��ǐՂ��Ȃ�(������x�����ꂽ�猳�ɖ߂�j

    return Tyutyu::syuuryou;
}
//*****************************************************************************
//  �`��
//*****************************************************************************
void Tyutyu::draw()
{
    // �X�v���C�g�`��
    auto key = KeyInput::getState();
    auto key_tracker = KeyInput::getTracker();

    //�J�[�\��������
    Sprite::Draw(
        texture_,
        position2_,
        &trim2_,
        255,
        0.0F,
        direction_,
        Vector2( 1.0F, 1.0F ),
        Vector2( 0.0F, 0.0F )
    );

    //�J�[�\��
    Sprite::Draw(
        texture_,
        position_,
        &trim_,
        255,
        0.0F,
        direction_,
        Vector2( 1.0F, 1.0F ),
        Vector2( 36.0F, 36.0F )
    );
}

void Tyutyu::destroy()
{
    //�e�N�X�`���ƃ������̉��
    SAFE_RELEASE( texture_ );
}

//*****************************************************************************
//  �f�X�g���N�^
//*****************************************************************************
Tyutyu::~Tyutyu()
{
    destroy();
}*/