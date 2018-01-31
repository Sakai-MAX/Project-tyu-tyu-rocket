#pragma once
//*****************************************************************************
//  Class
//*****************************************************************************
#include "title.h"
class Player
{
private:
    ID3D11ShaderResourceView* texture_;     //テクスチャ
    ID3D11ShaderResourceView* texture2_;
    SpriteEffects direction_;   // スプライトエフェクト（向き）
    Vector2 position_;          // 座標
    Vector2 position2_;
    Vector2 position3_;
    Vector2 position4_;
    Vector2 terget_position_;   // 的の座標
    Vector2 copy_ball_position_;// 砲弾の座標（コピー）
    Vector2 clear_position_;   // クリアの座標
    Vector2 message_vec_;      // メッセージ座標

    RECT    trim_;              // 描画範囲
    RECT    trim2_;
    RECT    trim3_;
    RECT    trim4_;
    RECT    trim5_;
    RECT    clear_trim_;        // クリアの描画範囲
    RECT    message_trim_;      // メッセージ描画範囲


    bool    shooting_;
    bool    terget_hit_flag_;
    float rotate_;
    float crad;
    float   terget_radius_;     // ターゲットの半径
    float   ball_radius_;       // 砲弾の半径

    float x, y;
    float rad;
    float length;
    float length2;
    int count;
    int count2;
    int i;
    int j;
    float ry;
    float rx;
    float ry2;
    float rx2;
    int randam;

    int hit_count;

    Title title_;

public:
    Player();       // コンストラクタ
    ~Player();      // デストラクタ
    bool init();   // 初期化
    bool update(); // 更新処理
    void draw();   // 描画
    void destroy(); //破棄
    static bool ret;    //戻り値用
    static bool doku;
    static bool syuuryou;

};