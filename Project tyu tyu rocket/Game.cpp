#include "game.h"
#include "keyinput.h"
#include "font.h"
//#include "player.h"

//コンストラクタ
Game::Game()
{
}

//初期化
bool Game::init()
{
    //メンバクラス初期化
    // if( !field_.init() )      return false;
    //int i = 0;
    //雪クラス初期化
    /* while( i < 20 )
    {
    if( !player_[ i ].init() )
    {
    //エラー
    return 0;
    }
    i++;
    }*/
    time_count = 60;
    notime_count = 0;
    hit_count = 0;
    return true;
}

//更新処理
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

//描画
void Game::draw()
{
    //field_.draw();
    player_.draw();
    // アルファ値確認用(Debug)
    wchar_t str[ _MAX_PATH ];
    swprintf_s( str, L"get count: %d", hit_count );
    Font::draw( str, Vector2( 0.0F, 0.0F ) );

    swprintf_s( str, L"time: %d", time_count );
    Font::draw( str, Vector2( 0.0F, 25.0F ) );
}

//破棄
void Game::destroy()
{
    //field_.destroy();
    player_.destroy();
}

//デストラクタ
Game::~Game()
{
    destroy();
}
