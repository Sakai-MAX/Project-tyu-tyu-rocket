#pragma once
//*****************************************************************************
//  Include
//*****************************************************************************

#include "player.h"
#include "game.h"
#include "title.h"

//列挙体
enum
{
    kTitleInit,     //タイトル初期化
    kTitleUpdate,   //タイトル更新
    kGameInit,       //ゲーム初期化
    kGameUpdate      //ゲーム更新
};
//*****************************************************************************
//  Class
//*****************************************************************************
class Loop
{
private:
    Game game_;     //ゲームシーンクラス
    Title title_;     //タイトルシーンクラス
    int work_no_;       //作業番号


    Player player_;   // プレイヤークラス

    bool init( const HINSTANCE hInstance ); // 初期化
    void draw();    // 描画

public:
    Loop();     // コンストラクタ
    ~Loop();    // デストラクタ

    int update( const HINSTANCE hInstance ); // 更新処理
};