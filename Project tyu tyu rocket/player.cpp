#include "player.h"
#include "direct3d.h"
#include "texture.h"
#include "keyinput.h"
#include "sprite.h"
#include "release.h"
#include"font.h"
#include "title.h"

bool Player::ret;
bool Player::syuuryou;
bool Player::doku;

//*****************************************************************************
//  定数
//*****************************************************************************
float rotation = 0.0F;
bool chase = true;  // 追跡フラグ
const float radius = 32.0F;     //半径



                                //*****************************************************************************
                                //  コンストラクタ
                                //*****************************************************************************
Player::Player()
{
    rx = (rand() % 1220) + 30.0F;
    ry = (rand() % 650) + 30.0F;
    rx2 = (rand() % 1220) + 30.0F;
    ry2 = (rand() % 650) + 30.0F;
    texture_ = NULL;
    position_ = Vector2( 46.0F, 424.0F );
    position2_ = Vector2( rx, ry );
    position3_ = Vector2( 0.0F, 0.0F );
    position4_ = Vector2( rx2, ry2 );
    message_vec_ = Vector2( 550.0F, 480.0F + 35.0F ); // メッセージ描画位置
    terget_position_ = Vector2( 200.0F, 370.0F );
    clear_position_ = Vector2( 210.0F, 100.0F );

    direction_ = SpriteEffects_None;

    clear_trim_ = { 256L ,85L, (256L + 256L), (55L + 120L) };
    message_trim_ = { 256L ,55L, (256L + 256L), (55L + 30L) };

    //手
    trim_.top = 450L;
    trim_.left = 390L;
    trim_.right = 450L;
    trim_.bottom = 511L;

    //きのこ1
    trim2_.top = 448L;
    trim2_.left = 196L;
    trim2_.right = 255L;
    trim2_.bottom = 511L;

    //きのこ2
    trim3_.top = 448L;
    trim3_.left = 260L;
    trim3_.right = 322L;
    trim3_.bottom = 511L;

    //射撃
    shooting_ = false;
    i = 0;
    j = 0;

    // 的に当たったかどうか
    terget_hit_flag_ = false;

    terget_radius_ = 32.0F;   // ターゲットの半径
    ball_radius_ = 9.0F;    // 砲弾の半径

    hit_count = 0;      //ヒットカウント

    crad = 0.0F;

    Player::ret = true;    //戻り値用
    Player::syuuryou = true;
    Player::doku = true;

}

//*****************************************************************************
//  初期化
//*****************************************************************************
bool Player::init()
{
    // テクスチャの読み込み
    if( !(texture_ = Texture::load( L"きのこ狩りの男ex.png" )) )
    {
        // エラー
        return false;
    }

    return true;
}

//*****************************************************************************
//  更新処理
//*****************************************************************************
bool Player::update()
{

    //きのこの出現ポイントランダム
    rx = (rand() % 1220) + 30.0F;
    ry = (rand() % 650) + 30.0F;

    rx2 = (rand() % 1220) + 30.0F;
    ry2 = (rand() % 650) + 30.0F;


    //手
    trim_.top = 450L;
    trim_.left = 390L;
    trim_.right = 450L;
    trim_.bottom = 511L;

    //入力を取得
    auto key = KeyInput::getState();
    auto key_tracker = KeyInput::getTracker();
    // 角度を計算(戻り値はラジアン)
    rad = atan2( y, -x );
    // 長さを計算
    length = hypot( x, y );

    // 右クリックされたら追跡しない(もう一度押されたら元に戻る）

    return Player::syuuryou;
}
//*****************************************************************************
//  描画
//*****************************************************************************
void Player::draw()
{
    // スプライト描画
    auto key = KeyInput::getState();
    auto key_tracker = KeyInput::getTracker();

    //きのこ
    Sprite::Draw(
        texture_,
        position2_,
        &trim2_,
        255,
        0.0F,
        direction_,
        Vector2( 1.0F, 1.0F ),
        Vector2( 32.0F, 32.0F )
    );
    //きのこ2
    Sprite::Draw(
        texture_,
        position4_,
        &trim3_,
        255,
        0.0F,
        direction_,
        Vector2( 1.0F, 1.0F ),
        Vector2( 32.0F, 32.0F )
    );

    //手
    Sprite::Draw(
        texture_,
        position_,
        &trim_,
        255,
        0.0F,
        direction_,
        Vector2( 1.0F, 1.0F ),
        Vector2( 30.0F, 30.0F )
    );
}

void Player::destroy()
{
    //テクスチャとメモリの解放
    SAFE_RELEASE( texture_ );
}

//*****************************************************************************
//  デストラクタ
//*****************************************************************************
Player::~Player()
{
    destroy();
}