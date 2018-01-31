#pragma once
class Sprite
{
private:
    static SpriteBatch* sprite_;   // スプライトバッチ

public:
    static bool init();    // 初期化
    static void destroy(); // 破棄
    static void Begin();   // スプライトの描画開始
    static void End();     // スプライトの描画終了

                           // 描画関数
    static void Draw(
        ID3D11ShaderResourceView* Texture,                  // シェーダリソースビュー
        const Vector2& Position = Vector2( 0.0F, 0.0F ),    // 座標
        const RECT* pRect = NULL,                           // 描画範囲
        const int   Alpha = 255,                            // アルファ地
        const float Rotation = 0.0F,                        // 回転値
        const SpriteEffects Effect = SpriteEffects_None,    // スプライトエフェクト
        const Vector2& Scale = Vector2( 1.0F, 1.0F ),       // 拡縮
        const Vector2& Origin = Vector2( 0.0F, 1.0F ),      // アンカーポイント
        const float Depth = 0.0F );                         // 深度値

                                                            // スプライトバッチクラスを返す
    static SpriteBatch* getSprite() { return sprite_; }
};