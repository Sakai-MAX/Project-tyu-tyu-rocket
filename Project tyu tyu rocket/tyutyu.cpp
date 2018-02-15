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
#include "tyutyu.h"


//*****************************************************************************
//  コンストラクタ
//*****************************************************************************
Tyutyu::Tyutyu()
{
    anime_no = 0L;
    anime_counter = 0L;

    kMoveSpeed = 1.0F;

    rx = (rand() % 1220) + 30.0F;
    ry = (rand() % 650) + 30.0F;
    rx2 = (rand() % 1220) + 30.0F;
    ry2 = (rand() % 650) + 30.0F;
    texture_ = NULL;
    position_ = Vector2( 353.0F, -20.0F );
    message_vec_ = Vector2( 550.0F, 480.0F + 35.0F ); // メッセージ描画位置
    terget_position_ = Vector2( 200.0F, 370.0F );
    clear_position_ = Vector2( 210.0F, 100.0F );

    direction_ = SpriteEffects_None;

    clear_trim_ = { 256L ,85L, (256L + 256L), (55L + 120L) };
    message_trim_ = { 256L ,55L, (256L + 256L), (55L + 30L) };

    //チュウチュウ
    trim_.top = 0L;
    trim_.left = 0L;
    trim_.right = 128L;
    trim_.bottom = 128L;

    a = 0;
    w = 0;
    s = 0;
    d = 0;
    tyutyu_counter = 0;

}

//*****************************************************************************
//  初期化
//*****************************************************************************
bool Tyutyu::init()
{
    // テクスチャの読み込み
    if( !(texture_ = Texture::load( L"右.png" )) )
    {
        // エラー
        return false;
    }
    // テクスチャの読み込み
    if( !(texture2_ = Texture::load( L"右前.png" )) )
    {
        // エラー
        return false;
    }
    // テクスチャの読み込み
    if( !(texture3_ = Texture::load( L"後.png" )) )
    {
        // エラー
        return false;
    }
    // テクスチャの読み込み
    if( !(texture4_ = Texture::load( L"後右.png" )) )
    {
        // エラー
        return false;
    }
    // テクスチャの読み込み
    if( !(texture5_ = Texture::load( L"後左.png" )) )
    {
        // エラー
        return false;
    }
    // テクスチャの読み込み
    if( !(texture6_ = Texture::load( L"左.png" )) )
    {
        // エラー
        return false;
    }
    // テクスチャの読み込み
    if( !(texture7_ = Texture::load( L"前.png" )) )
    {
        // エラー
        return false;
    }
    // テクスチャの読み込み
    if( !(texture8_ = Texture::load( L"前右.png" )) )
    {
        // エラー
        return false;
    }
    // テクスチャの読み込み
    if( !(texture9_ = Texture::load( L"前左.png" )) )
    {
        // エラー
        return false;
    }
    return true;
}

//*****************************************************************************
//  更新処理
//*****************************************************************************
bool Tyutyu::update()
{
    //入力を取得
    auto key = KeyInput::getState();
    auto key_tracker = KeyInput::getTracker();
    auto pad = PadInput::getTracker();
    auto kaiten = PadInput::State();
    x = kaiten.thumbSticks.leftX;
    y = kaiten.thumbSticks.leftY;
  

    if( anime_counter++ > 0 )
    {
        if( anime_no == 384 )
            anime_no = -128L;
        anime_no += 128;
        tyutyu_counter++;
        trim_.left = anime_no;
        trim_.right = anime_no + 128;
        anime_counter = 0;
    }
    if( tyutyu_counter > 3 )
    {
        trim_.top = 128L;
        trim_.bottom = 256L;
    }

    if( tyutyu_counter > 7 )
    {
        trim_.top = 0L;
        trim_.bottom = 128L;
        tyutyu_counter = 0;
    }

    

    return false;
}
//*****************************************************************************
//  描画
//*****************************************************************************
void Tyutyu::draw()
{
    //カーソル
    Sprite::Draw(
        texture7_,
        position_,
        &trim_,
        255,
        0.0F,
        direction_,
        Vector2( 1.0F, 1.0F ),
        Vector2( 0.0F, 0.0F )
    );
}

void Tyutyu::destroy()
{
    //テクスチャとメモリの解放
    SAFE_RELEASE( texture_ );
}

//*****************************************************************************
//  デストラクタ
//*****************************************************************************
Tyutyu::~Tyutyu()
{
    destroy();
}