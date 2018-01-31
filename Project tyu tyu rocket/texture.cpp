#include "texture.h"
#include "direct3d.h"
#include "error.h"


/////////////////////////
//        Using        //
/////////////////////////


///////////////////////////
//  �e�N�X�`���̓ǂݍ��� //
///////////////////////////
ID3D11ShaderResourceView* Texture::load( const wchar_t* FileName )
{
    ID3D11ShaderResourceView* texture;

    // WIC�e�N�X�`���̓ǂݍ���
    if( FAILED( CreateWICTextureFromFileEx(
        Direct3D::getDevice(),      // D3DDevice
        Direct3D::getContext(),     // D3DDeviceContext
        FileName,                   // �t�@�C���p�X
        0,                          // �~�b�v�}�b�v���x��(0���w�肷��Ǝ��������j
        D3D11_USAGE_DEFAULT,        // �g�p���@
        D3D11_BIND_SHADER_RESOURCE, // �o�C���h���@
        0,                          // CPU�A�N�Z�X���
        0,                          // �t���O�I�v�V����
        WIC_LOADER_DEFAULT,         // SRGB�t���O
        NULL,                       // ���\�[�X�f�[�^����|�C���^
        &texture ) ) )              // �V�F�[�_���\�[�X�r���[����|�C���^
    {
        // �G���[
        wchar_t str[ _MAX_PATH ];
        swprintf_s( str, L"%s�̓ǂݍ��݂Ɏ��s���܂����B\n", FileName );
        Error::showDialog( str );
        return NULL;
    }

    return texture;
}