#include "game.h"
#include "keyinput.h"
#include "font.h"
//#include "player.h"

//�R���X�g���N�^
Game::Game()
{
}

//������
bool Game::init()
{
    //�����o�N���X������
    // if( !field_.init() )      return false;
    //int i = 0;
    //��N���X������
    /* while( i < 20 )
    {
    if( !player_[ i ].init() )
    {
    //�G���[
    return 0;
    }
    i++;
    }*/
    time_count = 60;
    notime_count = 0;
    hit_count = 0;
    return true;
}

//�X�V����
bool Game::update()
{
    // field_.update();
    player_.update();

    auto key = KeyInput::getTracker();
    if( Player::ret == false )
    {
        hit_count++;

        Player::ret = true;
    }


    if( Player::doku == false )
    {
        hit_count -= 3;

        Player::doku = true;
    }

    notime_count++;
    if( notime_count >= 60 )
    {
        time_count--;
        notime_count = 0;
    }
    if( time_count <= -1 )
    {
        return false;
    }
    return true;

}

//�`��
void Game::draw()
{
    //field_.draw();
    player_.draw();
    // �A���t�@�l�m�F�p(Debug)
    wchar_t str[ _MAX_PATH ];
    swprintf_s( str, L"get count: %d", hit_count );
    Font::draw( str, Vector2( 0.0F, 0.0F ) );

    swprintf_s( str, L"time: %d", time_count );
    Font::draw( str, Vector2( 0.0F, 25.0F ) );
}

//�j��
void Game::destroy()
{
    //field_.destroy();
    player_.destroy();
}

//�f�X�g���N�^
Game::~Game()
{
    destroy();
}
