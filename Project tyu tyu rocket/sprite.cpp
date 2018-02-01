#include "sprite.h"
#include "direct3d.h"
#include "player.h"
#include "error.h"


//////////////////////
//  �@���̂̐錾�@�@//
//////////////////////
SpriteBatch* Sprite::sprite_;


//////////////////
//  �@�������@�@//
//////////////////
bool Sprite::init()
{
    sprite_ = new SpriteBatch( Direct3D::getContext() );

    // �������m�ۃ`�F�b�N
    if( !sprite_ )
    {
        // �G���[
        Error::showDialog( L"�X�v���C�g�o�b�`�̃������m�ۂɎ��s���܂����B" );
        return false;
    }

    return true;
}


////////////////
//  �@�j���@�@//
////////////////
void Sprite::destroy()
{
    delete[] sprite_;
}


//////////////////////////////
//  �@�X�v���C�g�`��J�n�@�@//
//////////////////////////////
void Sprite::Begin()
{
    sprite_->Begin( SpriteSortMode_Deferred, Direct3D::getStates()->NonPremultiplied() );
}


//////////////////////////////
//  �@�X�v���C�g�`��I���@�@//
//////////////////////////////
void Sprite::End()
{
    sprite_->End();
}


////////////////////////////
//    �X�v���C�g�̕`��@�@//
////////////////////////////
void Sprite::Draw(
    ID3D11ShaderResourceView* Texture, const Vector2& Position, const RECT* pRect, const int Alpha,
    const float Rotation, const SpriteEffects Effect, const Vector2& Scale, const Vector2& Origin, const float Depth )
{
    Color color( 1.0F, 1.0F, 1.0F, static_cast<float>(Alpha) / 255.0F );        //�Ō�̐�����ς���Ɠ����ł���

// �`��
    sprite_->Draw(
        Texture,       // �V�F�[�_���\�[�X�r���[�̃|�C���^
        Position,      // ���W
        pRect,         // �`��͈�
        color, // �J���[
        Rotation,      // ��]�l�i���W�A���j
        Origin,        // �A���J�[�|�C���g
        Scale,         // �g�k
        Effect,        // �X�v���C�g�G�t�F�N�g
        Depth );       // �[�x�l
}
