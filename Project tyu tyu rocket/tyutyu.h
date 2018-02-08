#pragma once
//*****************************************************************************
//  Class
//*****************************************************************************
class Tyutyu
{
private:
    ID3D11ShaderResourceView* texture_; // シェーダリソースビュー
    ID3D11ShaderResourceView* texture_Mk2;
    SpriteEffects direction_;   // スプライトエフェクト（向き）
    Vector2 position_;          // 座標
    Vector2 position_Mk2;
    RECT    trim_;              // 描画範囲
    RECT    trimMk2_;
    RECT    trimMk3_;
    RECT    trimMk4_;
    RECT    trimMk5_;
    RECT    trimMk6_;
    RECT    trimMk7_;
    RECT    trimMk8_;

public:
    Tyutyu();       // コンストラクタ
    ~Tyutyu();      // デストラクタ
    bool init();   // 初期化
    void update(); // 更新処理
    void draw();   // 描画
    void destroy(); //破棄
};