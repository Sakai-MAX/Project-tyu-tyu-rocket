#pragma once
//Include
#include "field.h"
#include "player.h"
#include "tyutyu.h"

//Class
class Game
{
private:
    Player player_;
    Field field_;
    Tyutyu tyutyu_;
    int time_count;
    int notime_count;
    int hit_count;
public:
    Game(); //�R���X�g���N�^
    ~Game();    //�f�X�g���N�^
    bool init();
    bool update();
    void draw();
    void destroy();
};