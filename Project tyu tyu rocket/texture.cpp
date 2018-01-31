#include "texture.h"
#include "direct3d.h"
#include "error.h"


/////////////////////////
//        Using        //
/////////////////////////


///////////////////////////
//  テクスチャの読み込み //
///////////////////////////
ID3D11ShaderResourceView* Texture::load( const wchar_t* FileName )
{
    ID3D11ShaderResourceView* texture;

    // WICテクスチャの読み込み
    if( FAILED( CreateWICTextureFromFileEx(
        Direct3D::getDevice(),      // D3DDevice
        Direct3D::getContext(),     // D3DDeviceContext
        FileName,                   // ファイルパス
        0,                          // ミップマップレベル(0を指定すると自動生成）
        D3D11_USAGE_DEFAULT,        // 使用方法
        D3D11_BIND_SHADER_RESOURCE, // バインド方法
        0,                          // CPUアクセス種類
        0,                          // フラグオプション
        WIC_LOADER_DEFAULT,         // SRGBフラグ
        NULL,                       // リソースデータ受取先ポインタ
        &texture ) ) )              // シェーダリソースビュー受取先ポインタ
    {
        // エラー
        wchar_t str[ _MAX_PATH ];
        swprintf_s( str, L"%sの読み込みに失敗しました。\n", FileName );
        Error::showDialog( str );
        return NULL;
    }

    return texture;
}