#pragma once
//名前空間
using namespace DirectX;

//struct
struct Tile
{
    Vector2 position;       //座標
    RECT    trim;           //描画範囲
    int     id;             //ID

                            //コンストラクタ
    Tile()
    {
        position = Vector2( 0.0F );
        trim = RECT{ 0 };
        id = 0;
    }
};

//class
class Field
{
private:
    ID3D11ShaderResourceView* texture_;     //テクスチャ
    Tile* tiles_;       //タイル構造体ポインタ
    int width_, height_;        //マップ横幅、縦幅（個数）
    Vector2  pos;
	Vector2  position_;
    SpriteEffects direction_;   // スプライトエフェクト（向き）
    RECT    trim_;              // 描画範囲
	RECT    trim2_;              // 描画範囲

	float ac;
	float wc;
	float sc;
	float dc;
	int atx;
	int aty;

	float wct;
public:
    Field();            //コンストラクタ
    ~Field();           //デストラクタ

    bool init();        //初期化
    void update();      //更新処理
    void draw();        //描画
    void destroy();

};