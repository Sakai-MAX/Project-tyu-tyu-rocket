#include "player.h"
#include "direct3d.h"
#include "texture.h"
#include "keyinput.h"
#include "padinput.h"
#include "sprite.h"
#include "release.h"
#include "font.h"
#include "title.h"
#include "field.h"

//戻り値召喚
bool Player::ret;
bool Player::syuuryou;
bool Player::doku;
Vector2 Player::position_go;

//*****************************************************************************
//  定数
//*****************************************************************************

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
    position_ = Vector2( 956.0F, 390.0F );
    position_at_ = Vector2( 0.0F, 0.0F );
    position2_ = Vector2( 884.0F, 318.0F );
    position3_ = Vector2( 0.0F, 0.0F );
    position4_ = Vector2( rx2, ry2 );
    message_vec_ = Vector2( 550.0F, 480.0F + 35.0F ); // メッセージ描画位置
    terget_position_ = Vector2( 200.0F, 370.0F );
    clear_position_ = Vector2( 210.0F, 100.0F );

    direction_ = SpriteEffects_None;

    clear_trim_ = { 256L ,85L, (256L + 256L), (55L + 120L) };
    message_trim_ = { 256L ,55L, (256L + 256L), (55L + 30L) };

    //カーソール
    trim_.top = 0L;
    trim_.left = 669L;
    trim_.right = 714L;
    trim_.bottom = 47L;

    //カーソールかっこ
    trim2_.top = 144L;
    trim2_.left = 72L;
    trim2_.right = 144L;
    trim2_.bottom = 216L;


    terget_radius_ = 32.0F;   // ターゲットの半径
    ball_radius_ = 9.0F;    // 砲弾の半径

    hit_count = 0;      //ヒットカウント

    crad = 0.0F;

    atx = false;
    aty = false;

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
    if( !(texture_ = Texture::load( L"TYUTYU10.png" )) )
    {
        // エラー
        return false;
    }


    //タイル個数分のメモリを動的確保
    return true;
}

//*****************************************************************************
//  更新処理
//*****************************************************************************
bool Player::update()
{
    //入力を取得
    auto key = KeyInput::getState();
    auto key_tracker = KeyInput::getTracker();
    auto pad = PadInput::getTracker();
    auto kaiten = PadInput::State();
    x = kaiten.thumbSticks.leftX;
    y = kaiten.thumbSticks.leftY;
	//カーソル帯
	Player::position_go = position_;

    //アナログ入力がある場合のみ移動
    if( x != 0.0F || y != 0.0F )
    {

        //角度を計算（戻り値はラジアン）
        float rad = atan2( y, x );

        //長さを計算
        float length = hypot( x, y );

        //移動
        position_.x += cos( rad ) * length * 10.0F;
        position_.y -= sin( rad ) * length * 10.0F;
        position_at_.x += cos( rad ) * length * 10.0F;
        position_at_.y -= sin( rad ) * length * 10.0F;
    }

    
    //カーソル移動判定
    if( atx == false && position_at_.x >= 36)
    {
        atx = true;
        position_at_.x = 0;
        position2_.x += 72.0F;
    }

    if( aty == false && position_at_.y >= 36 )
    {
        aty = true;

        position_at_.y = 0;
        position2_.y += 72.0F;
    }

    if( atx == false && position_at_.x <= -36 )
    {
        atx = true;
        position_at_.x = 0;
        position2_.x -= 72.0F;
    }

    if( aty == false && position_at_.y <= -36 )
    {
        aty = true;
        position_at_.y = 0;
        position2_.y -= 72.0F;
    }

    if( atx == true && position_at_.x >= 72 )
    {
        position_at_.x = 0;
        position2_.x += 72.0F;
    }

    if( aty == true && position_at_.y >= 72 )
    {
        position_at_.y = 0;
        position2_.y += 72.0F;
    }

    if( atx == true && position_at_.x <= -72 )
    {
        position_at_.x = 0;
        position2_.x -= 72.0F;
    }

    if( aty == true && position_at_.y <= -72 )
    {
        position_at_.y = 0;
        position2_.y -= 72.0F;
    }

    ////////////////////  Aボタン  //////////////////////
    if( key_tracker.pressed.Z || pad.a == GamePad::ButtonStateTracker::HELD )
    {
   
    }

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

    //カーソルかっこ
    Sprite::Draw(
        texture_,
        position2_,
        &trim2_,
        255,
        0.0F,
        direction_,
        Vector2( 1.0F, 1.0F ),
        Vector2( 0.0F, 0.0F )
    );

    //カーソル
    Sprite::Draw(
        texture_,
        position_,
        &trim_,
        255,
        0.0F,
        direction_,
        Vector2( 1.0F, 1.0F ),
        Vector2( 36.0F, 36.0F )
    );
    // アルファ値確認用(Debug)
    wchar_t str[ _MAX_PATH ];
    swprintf_s( str, L"position x: %.1f", position_.x );
    Font::draw( str, Vector2( 0.0F, 0.0F ) );

    swprintf_s( str, L"position y: %.1f", position_.y );
    Font::draw( str, Vector2( 0.0F, 25.0F ) );
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