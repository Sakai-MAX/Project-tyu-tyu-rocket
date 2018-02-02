//Include
#include "field.h"
#include "texture.h"
#include "sprite.h"
#include "error.h"
#include "keyinput.h"
#include "release.h"
#include "player.h"

//�萔
const int kTileSize = 72;   //�^�C���T�C�Y

float ac = 0;
float wc = 0;
float sc = 0;
float dc = 0;
int atx = 10;
int aty = 5;

float wct = 0;

//�R���X�g���N�^
Field::Field()
{
    texture_ = NULL;
    tiles_ = NULL;
    width_ = 0;
    height_ = 0;
    //�J�[�\�[��
    trim_.top = 0L;
    trim_.left = 669L;
    trim_.right = 714L;
    trim_.bottom = 47L;
    direction_ = SpriteEffects_None;
}

//������
bool Field::init()
{
    //�e�N�X�`���̓ǂݍ���
    if( !(texture_ = Texture::load( L"tyutyu2.png" )) )
    {
        //�G���[
        return false;

    }

    //FMF�t�@�C������f�[�^��ǂݍ���
    FILE* fp = fopen( "map2.fmf", "rb" );

    //�t�@�C�������������m�F
    if( !fp )
    {
        //�G���[
        Error::showDialog( L"fmf�t�@�C�����J���܂���ł���" );
        return false;
    }

    //�擪����8Byte�|�C���^���ړ�
    fseek( fp, 8L, SEEK_SET );

    //�}�b�v�̉����Əc�����擾
    fread( &width_, sizeof( int ), 1, fp );
    fread( &height_, sizeof( int ), 1, fp );

    //�^�C�������̃������𓮓I�m��
    tiles_ = new Tile[ width_ * height_ ];

    //�������m�ۂł�����
    if( !tiles_ )
    {
        //�G���[
        Error::showDialog( L"�^�C���������̊m�ۂɎ��s���܂���" );
        return false;
    }

    //ID�擾�̂��߂̃w�b�_�������X�L�b�v
    fseek( fp, 20L, SEEK_SET );

    for( int i = 0; i < width_ * height_; i++ )
    {
        tiles_[ i ].position.x = 380.0F;
        tiles_[ i ].position.y = 30.0F;
        //ID�̎擾
        fread( &tiles_[ i ].id, sizeof( char ), 1, fp );

        //�`��͈͂̐ݒ�
        tiles_[ i ].trim.left = tiles_[ i ].id % 16 * kTileSize;
        tiles_[ i ].trim.top = tiles_[ i ].id / 16 * kTileSize;
        tiles_[ i ].trim.right = tiles_[ i ].trim.left + kTileSize;
        tiles_[ i ].trim.bottom = tiles_[ i ].trim.top + kTileSize;

        //���W�ݒ�
        tiles_[ i ].position.x += static_cast<float>(kTileSize * (i % width_));
        tiles_[ i ].position.y += static_cast<float>(kTileSize * (i / width_));
    }

    //�t�@�C�������
    fclose( fp );



    return true;

}

//�X�V����
void Field::update()
{

    // ���͏�Ԃ��擾
    auto key = KeyInput::getState();
    auto key_tracker = KeyInput::getTracker();
    pos = Player::position_go;
    
}

//�`��
void Field::draw()
{
    for( int i = 0; i < width_ * height_; i++ )
    {
        Sprite::Draw( texture_, tiles_[ i ].position, &tiles_[ i ].trim );
    }
    //���̂�
    Sprite::Draw(
    texture_,
    pos,
    &trim_,
    60,
    0.0F,
    direction_,
    Vector2( 1.0F, 1.0F ),
    Vector2( 32.0F, 32.0F )
    );
}

//�j��
void Field::destroy()
{
    //�e�N�X�`���̉��
    SAFE_RELEASE( texture_ );

}


//�f�X�g���N�^
Field::~Field()
{
    destroy();
}