#include "game.h"
#include "keyinput.h"

//コンストラクタ
Game::Game()
{
   // tyutyu_ = new Tyutyu[ 100 ];
}

//初期化
bool Game::init()
{
    //メンバクラス初期化
    if( !field_.init() )      return false;
    if( !tyutyu_.init() )    return false;
    if( !player_.init() )     return false;



    return true;
}

//更新処理
bool Game::update()
{
    field_.update();
    tyutyu_.update();
    player_.update();


    auto key = KeyInput::getTracker();
    if( Player::ret == false )
    {
        return false;
    }

    return true;
}

//描画
void Game::draw()
{
    field_.draw();
    tyutyu_.draw();
    player_.draw();

}

//破棄
void Game::destroy()
{
    field_.destroy();
    tyutyu_.destroy();
    player_.destroy();

}

//デストラクタ
Game::~Game()
{
    destroy();
}
