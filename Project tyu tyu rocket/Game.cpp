#include "game.h"
#include "keyinput.h"

//�R���X�g���N�^
Game::Game()
{
   // tyutyu_ = new Tyutyu[ 100 ];
}

//������
bool Game::init()
{
    //�����o�N���X������
    if( !field_.init() )      return false;
    if( !tyutyu_.init() )    return false;
    if( !player_.init() )     return false;



    return true;
}

//�X�V����
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

//�`��
void Game::draw()
{
    field_.draw();
    tyutyu_.draw();
    player_.draw();

}

//�j��
void Game::destroy()
{
    field_.destroy();
    tyutyu_.destroy();
    player_.destroy();

}

//�f�X�g���N�^
Game::~Game()
{
    destroy();
}
