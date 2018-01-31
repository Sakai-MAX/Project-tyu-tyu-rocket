#include "game.h"
#include "keyinput.h"

//コンストラクタ
Game::Game()
{
}

//初期化
bool Game::init()
{
    //メンバクラス初期化
    if( !field_.init() )      return false;
    if( !player_.init() )     return false;


    return true;
}

//更新処理
bool Game::update()
{
    field_.update();
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
    player_.draw();
}

//破棄
void Game::destroy()
{
    field_.destroy();
    player_.destroy();
}

//デストラクタ
Game::~Game()
{
    destroy();
}
