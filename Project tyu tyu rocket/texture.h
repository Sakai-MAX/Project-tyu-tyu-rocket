#pragma once
//*****************************************************************************
//  Class
//*****************************************************************************
class Texture
{
public:
    // テクスチャの読み込み
    static ID3D11ShaderResourceView* load( const wchar_t* FileName );
};