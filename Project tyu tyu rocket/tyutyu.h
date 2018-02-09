#pragma once
//*****************************************************************************
//  Class
//*****************************************************************************
class Tyutyu
{
private:
    ID3D11ShaderResourceView* texture_;     //テクスチャ
    ID3D11ShaderResourceView* texture2_;     //テクスチャ2
    ID3D11ShaderResourceView* texture3_;     //テクスチャ3
    ID3D11ShaderResourceView* texture4_;     //テクスチャ4
    ID3D11ShaderResourceView* texture5_;     //テクスチャ5
    ID3D11ShaderResourceView* texture6_;     //テクスチャ6
    ID3D11ShaderResourceView* texture7_;     //テクスチャ7
    ID3D11ShaderResourceView* texture8_;     //テクスチャ8
    ID3D11ShaderResourceView* texture9_;     //テクスチャ9

    SpriteEffects direction_;   // スプライトエフェクト（向き）
    Vector2 position_;          // 座標
    Vector2 terget_position_;   // 的の座標
    Vector2 copy_ball_position_;// 砲弾の座標（コピー）
    Vector2 clear_position_;   // クリアの座標
    Vector2 message_vec_;      // メッセージ座標

    RECT    trim_;              // カーソル
    RECT    trim2_;             // カーソルかっこ
    RECT    trim3_;
    RECT    trim4_;
    RECT    trim5_;
    RECT    clear_trim_;        // クリアの描画範囲
    RECT    message_trim_;      // メッセージ描画範囲

    LONG   anime_no;                       //描画NUM
    LONG  anime_counter;                   // 描画カウンター

    bool atx;
    bool aty;
    bool btx;
    bool bty;


    bool    shooting_;
    bool    terget_hit_flag_;

    float   kMoveSpeed;

    float a;
    float w;
    float s;
    float d;


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

public:
    Tyutyu();       // コンストラクタ
    ~Tyutyu();      // デストラクタ
    bool init();   // 初期化
    bool update(); // 更新処理
    void draw();   // 描画
    void destroy(); //破棄
};