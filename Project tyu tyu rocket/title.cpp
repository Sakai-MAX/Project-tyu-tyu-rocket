#include "direct3d.h"
#include "texture.h"
#include "keyinput.h"
#include "sprite.h"
#include "release.h"
#include "title.h"
#include "padinput.h"


//�R���X�g���N�^
Title::Title()
{

    texture_ = NULL;
    position_ = Vector2( 360.0F, 320.0F );
    position2_ = Vector2( 78.0F, 456.0F );
    position3_ = Vector2( 500.0F, 500.0F );
    position4_ = Vector2( 1000.0F, 700.0F );
    position5_ = Vector2( 800.0F, 200.0F );
    trim_.top = 0L;
    trim_.left = 0L;
    trim_.right = 512L;
    trim_.bottom = 100L;
    trim2_.top = 448L;
    trim2_.left = 196L;
    trim2_.right = 255L;
    trim2_.bottom = 511L;
    trim3_.top = 448L;
    trim3_.left = 260L;
    trim3_.right = 322L;
    trim3_.bottom = 511L;
    trim4_.top = 448L;
    trim4_.left = 323L;
    trim4_.right = 385L;
    trim4_.bottom = 511L;
    trim5_.top = 330L;
    trim5_.left = 0L;
    trim5_.right = 64L;
    trim5_.bottom = 380L;
    direction_ = SpriteEffects_None;
    ret = true;
    thn = false;  // �ҋ@�J�E���g
    txc = 300;    // �����x
}

//������
bool Title::init()
{

    //�e�N�X�`���̓ǂݍ���
    if( !(texture_ = Texture::load( L"���̂����̒jex.png" )) )
    {
        //�G���[
        return false;
    }

    return true;

}

//�X�V����
bool Title::update()
{
    ret = true;    //�߂�l�p

    rx1 = (rand() % 1220) + 30.0F;
    ry1 = (rand() % 650) + 30.0F;
    rx2 = (rand() % 1220) + 30.0F;
    ry2 = (rand() % 650) + 30.0F;
    rx3 = (rand() % 1220) + 30.0F;
    ry3 = (rand() % 650) + 30.0F;
    rx4 = (rand() % 1220) + 30.0F;
    ry4 = (rand() % 650) + 30.0F;

    position2_.x = rx1;
    position2_.y = ry1;
    position3_.x = rx2;
    position3_.y = ry2;
    position4_.x = rx3;
    position4_.y = ry3;
    position5_.x = rx4;
    position5_.y = ry4;

    auto key = KeyInput::getState();
    auto key_tracker = KeyInput::getTracker();
    auto pad = PadInput::getTracker();

    //�X�y�[�X�L�[��A�{�^�����������ꂽ��A�^�C�g���V�[�����I��
    if( key.Z || pad.a == GamePad::ButtonStateTracker::HELD )
    {
        thn = true;

    }

    if( thn == true )
    {
        txc -= 8;
    }

    if( txc < 0 )
    {
        ret = false;
    }
    return ret;



}

//�`��
void Title::draw()
{
    Sprite::Draw(
        texture_,
        position2_,
        &trim2_,
        txc,
        0.0F,
        direction_,
        Vector2( 1.0F, 1.0F ),
        Vector2( 32.0F, 32.0F ) );

    Sprite::Draw(
        texture_,
        position3_,
        &trim3_,
        txc,
        0.0F,
        direction_,
        Vector2( 1.0F, 1.0F ),
        Vector2( 32.0F, 32.0F ) );

    Sprite::Draw(
        texture_,
        position4_,
        &trim4_,
        txc,
        0.0F,
        direction_,
        Vector2( 1.0F, 1.0F ),
        Vector2( 32.0F, 32.0F ) );

    Sprite::Draw(
        texture_,
        position5_,
        &trim5_,
        txc,
        0.0F,
        direction_,
        Vector2( 1.0F, 1.0F ),
        Vector2( 32.0F, 32.0F ) );

    Sprite::Draw( texture_, position_, &trim_, txc );



}

//�j��
void Title::destroy()
{
    //�e�N�X�`���̉��
    texture_->Release();
}

//�f�X�g���N�^
Title::~Title()
{
    //�e�N�X�`���̉��
    destroy();
}