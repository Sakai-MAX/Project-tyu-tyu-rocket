#pragma once
//*****************************************************************************
//  Class
//*****************************************************************************
class Texture
{
public:
    // �e�N�X�`���̓ǂݍ���
    static ID3D11ShaderResourceView* load( const wchar_t* FileName );
};