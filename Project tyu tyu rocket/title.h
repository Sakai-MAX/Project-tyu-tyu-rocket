#pragma once
//Class
class Title
{
private:
    ID3D11ShaderResourceView * texture_;   //テクスチャ
    SpriteEffects             direction_; // スプライトエフェクト（向き）


    Vector2 position_;
    Vector2 position2_;
    Vector2 position3_;
    Vector2 position4_;
    Vector2 position5_;

    RECT trim_;
    RECT trim2_;
    RECT trim3_;
    RECT trim4_;
    RECT trim5_;

    float rx1;
    float ry1;
    float rx2;
    float ry2;
    float rx3;
    float ry3;
    float rx4;
    float ry4;


    bool ret;

    bool thn;  // 待機カウント
    int  txc;    // 透明度

public:
    Title();            //コンストラクタ
    ~Title();           //デストラクタ
    bool init();        //初期化
    bool update();      //更新処理
    void draw();         //破棄
    void destroy();     //破棄
};