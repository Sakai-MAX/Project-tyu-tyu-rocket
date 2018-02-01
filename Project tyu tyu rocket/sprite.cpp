#include "sprite.h"
#include "direct3d.h"
#include "player.h"
#include "error.h"


//////////////////////
//  　実体の宣言　　//
//////////////////////
SpriteBatch* Sprite::sprite_;


//////////////////
//  　初期化　　//
//////////////////
bool Sprite::init()
{
    sprite_ = new SpriteBatch( Direct3D::getContext() );

    // メモリ確保チェック
    if( !sprite_ )
    {
        // エラー
        Error::showDialog( L"スプライトバッチのメモリ確保に失敗しました。" );
        return false;
    }

    return true;
}


////////////////
//  　破棄　　//
////////////////
void Sprite::destroy()
{
    delete[] sprite_;
}


//////////////////////////////
//  　スプライト描画開始　　//
//////////////////////////////
void Sprite::Begin()
{
    sprite_->Begin( SpriteSortMode_Deferred, Direct3D::getStates()->NonPremultiplied() );
}


//////////////////////////////
//  　スプライト描画終了　　//
//////////////////////////////
void Sprite::End()
{
    sprite_->End();
}


////////////////////////////
//    スプライトの描画　　//
////////////////////////////
void Sprite::Draw(
    ID3D11ShaderResourceView* Texture, const Vector2& Position, const RECT* pRect, const int Alpha,
    const float Rotation, const SpriteEffects Effect, const Vector2& Scale, const Vector2& Origin, const float Depth )
{
    Color color( 1.0F, 1.0F, 1.0F, static_cast<float>(Alpha) / 255.0F );        //最後の数字を変えると投下できる

// 描画
    sprite_->Draw(
        Texture,       // シェーダリソースビューのポインタ
        Position,      // 座標
        pRect,         // 描画範囲
        color, // カラー
        Rotation,      // 回転値（ラジアン）
        Origin,        // アンカーポイント
        Scale,         // 拡縮
        Effect,        // スプライトエフェクト
        Depth );       // 深度値
}
