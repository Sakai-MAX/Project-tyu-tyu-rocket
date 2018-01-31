//Include
#include "field.h"
#include "texture.h"
#include "sprite.h"
#include "error.h"
#include "keyinput.h"
#include "release.h"

//定数
const int kTileSize = 64;   //タイルサイズ

float ac = 0;
float wc = 0;
float sc = 0;
float dc = 0;
int atx = 10;
int aty = 5;

float wct = 0;

//コンストラクタ
Field::Field()
{
    texture_ = NULL;
    tiles_ = NULL;
    width_ = 0;
    height_ = 0;
}

//初期化
bool Field::init()
{
    //テクスチャの読み込み
    if( !(texture_ = Texture::load( L"きのこ狩りの男ex.png" )) )
    {
        //エラー
        return false;

    }

    //FMFファイルからデータを読み込む
    FILE* fp = fopen( "map.fmf", "rb" );

    //ファイルが明けたか確認
    if( !fp )
    {
        //エラー
        Error::showDialog( L"fmfファイルを開けませんでした" );
        return false;
    }

    //先頭から8Byteポインタを移動
    fseek( fp, 8L, SEEK_SET );

    //マップの横幅と縦幅を取得
    fread( &width_, sizeof( int ), 1, fp );
    fread( &height_, sizeof( int ), 1, fp );

    //タイル個数分のメモリを動的確保
    tiles_ = new Tile[ width_ * height_ ];

    //メモリ確保できたか
    if( !tiles_ )
    {
        //エラー
        Error::showDialog( L"タイルメモリの確保に失敗しました" );
        return false;
    }

    //ID取得のためのヘッダ部分をスキップ
    fseek( fp, 20L, SEEK_SET );

    float j = 0;
    for( int i = 0; i < width_ * height_; i++ )
    {
        //IDの取得
        fread( &tiles_[ i ].id, sizeof( char ), 1, fp );

        //描画範囲の設定
        tiles_[ i ].trim.left = tiles_[ i ].id % 16 * kTileSize;
        tiles_[ i ].trim.top = tiles_[ i ].id / 16 * kTileSize;
        tiles_[ i ].trim.right = tiles_[ i ].trim.left + kTileSize;
        tiles_[ i ].trim.bottom = tiles_[ i ].trim.top + kTileSize;

        //座標設定
        tiles_[ i ].position.x = static_cast<float>(kTileSize * (i % width_));
        tiles_[ i ].position.y = static_cast<float>(kTileSize * (i / width_));
    }

    //ファイルを閉じる
    fclose( fp );

    return true;

}

//更新処理
void Field::update()
{

    // 入力状態を取得
    auto key = KeyInput::getState();
    auto key_tracker = KeyInput::getTracker();

}

//描画
void Field::draw()
{
    for( int i = 0; i < width_ * height_; i++ )
    {
        Sprite::Draw( texture_, tiles_[ i ].position, &tiles_[ i ].trim );
    }
}

//破棄
void Field::destroy()
{
    //テクスチャの解放
    SAFE_RELEASE( texture_ );

}


//デストラクタ
Field::~Field()
{
    destroy();
}