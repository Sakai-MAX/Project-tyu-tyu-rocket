#include "direct3d.h"
#include "error.h"
#include <DirectXColors.h>
#include "release.h"


////////////////////////////////////
//           ���̂̐錾           //
////////////////////////////////////
ID3D11Device*           Direct3D::d3d_device_;         // D3D�f�o�C�X
ID3D11DeviceContext*    Direct3D::device_context_;     // �f�o�C�X�R���e�L�X�g 
IDXGISwapChain*         Direct3D::swap_chain_;         // �X���b�v�`�F�C��
D3D_FEATURE_LEVEL       Direct3D::feature_level_;      // �@�\���x��
ID3D11RenderTargetView* Direct3D::render_target_view_; // �`��^�[�Q�b�g�r���[
CommonStates*           Direct3D::common_states_;      // �X�e�[�g�N���X


                                                       ///////////////////////////////////////////////////////////////////                                                       
                                                       //  ������(�E�B���h�E�n���h���ƃE�B���h�E�T�C�Y�������Ŏ󂯎��j//
                                                       ///////////////////////////////////////////////////////////////////
bool Direct3D::init( const HWND hWnd, const int Width, const int Height )
{
    // �@�\���x���̐ݒ�
    D3D_FEATURE_LEVEL level_array[] =
    {
        D3D_FEATURE_LEVEL_11_0,
        D3D_FEATURE_LEVEL_10_1,
        D3D_FEATURE_LEVEL_10_0,
    };

    // �X���b�v�`�F�C���̐ݒ�
    DXGI_SWAP_CHAIN_DESC sc;
    ZeroMemory( &sc, sizeof( sc ) );                                       // ������
    sc.Windowed = true;                            // �E�B���h�E���[�h
    sc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;        // �X���b�v�G�t�F�N�g
    sc.OutputWindow = hWnd;                            // �E�B���h�E�n���h��
    sc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT; // �o�b�N�o�b�t�@�̎g�p�@
    sc.BufferCount = 1U;                              // �o�b�N�o�b�t�@��
    sc.BufferDesc.Width = Width;                           // �o�b�N�o�b�t�@�T�C�Y�i���j
    sc.BufferDesc.Height = Height;                          // �o�b�N�o�b�t�@�T�C�Y�i�c�j
    sc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;      // �t�H�[�}�b�g
    sc.BufferDesc.RefreshRate.Numerator = 60U;                             // ���t���b�V�����[�g���q
    sc.BufferDesc.RefreshRate.Denominator = 1U;                              // ���t���b�V�����[�g����
    sc.SampleDesc.Count = 1;                               // �}���`�T���v�����O
    sc.SampleDesc.Quality = 0;                               // �}���`�T���v�����O�i��
    sc.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;	                     // ���[�h�����؂�ւ�

                                                                             // �v�f�����v�Z
    int num_feature_level = sizeof( level_array ) / sizeof( level_array[ 0 ] );

    // �X���b�v�`�F�[���AD3DDevice�AD3DDeviceContext���쐬����
    if( FAILED( D3D11CreateDeviceAndSwapChain(
        NULL,                      // DXGI�A�_�v�^�[
        D3D_DRIVER_TYPE_HARDWARE,  // �h���C�o�[�^�C�v
        NULL,                      // �\�t�g�E�F�A���X�^���C�U�[����������DLL�n���h��
        D3D11_CREATE_DEVICE_DEBUG, // �t���O
        level_array,               // �@�\���x��
        num_feature_level,         // ���x����
        D3D11_SDK_VERSION,         // ��ɂ��̒l
        &sc,                       // �X���b�v�`�F�[�������p�����[�^�\����
        &swap_chain_,              // �X���b�v�`�F�[���|�C���^
        &d3d_device_,              // D3DDevice
        &feature_level_,           // �ݒ肵���@�\���x��
        &device_context_ ) ) )     // DeviceContext
    {
        // �G���[
        return false;
    }

    // �o�b�N�o�b�t�@�`��^�[�Q�b�g�̎擾
    ID3D11Texture2D* backbuffer = NULL;
    if( FAILED( swap_chain_->GetBuffer( 0, __uuidof(ID3D11Texture2D), reinterpret_cast<void**>(&backbuffer) ) ) )
    {
        // �G���[
        return false;
    }

    // �`��^�[�Q�b�g�E�r���[�̍쐬
    if( FAILED( d3d_device_->CreateRenderTargetView(
        backbuffer,               // �r���[�ŃA�N�Z�X���郊�\�[�X
        NULL,                     // �^�[�Q�b�g�r���[�̒�`
        &render_target_view_ ) ) ) // �^�[�Q�b�g�r���[�i�[��
    {
        // �G���[
        return false;
    }

    // �o�b�N�o�b�t�@���
    backbuffer->Release();

    // �`��^�[�Q�b�g�r���[���o�̓}�l�[�W���[�̕`��^�[�Q�b�g�Ƃ��Đݒ�
    device_context_->OMSetRenderTargets(
        1,					  // �`��^�[�Q�b�g���i8�܂ŉ�)
        &render_target_view_, // �^�[�Q�b�g�r���[�z��
        NULL );               // �[�x/�X�e���V���r���[

                              // �r���[�|�[�g�쐬
    D3D11_VIEWPORT vp;
    vp.Width = static_cast<float>(Width);   // �`��̈敝
    vp.Height = static_cast<float>(Height);  // �`��̈捂��
    vp.MinDepth = 0.0F;   // �`��̈�ŏ��[�x�l
    vp.MaxDepth = 1.0F;   // �`��̈�ő�[�x�l
    vp.TopLeftX = 0;      //�`��J�n�ʒuX
    vp.TopLeftY = 0;      //�`��J�n�ʒuY

                          // �r���[�|�[�g��ݒ�
    device_context_->RSSetViewports( 1, &vp );

    // �X�e�[�g�N���X�̃������m��
    common_states_ = new CommonStates( d3d_device_ );

    // �������m�ۃ`�F�b�N
    if( !common_states_ )
    {
        // �G���[
        Error::showDialog( L"�X�e�[�g�N���X�̃������m�ۂɎ��s" );
        return false;
    }

    return true;
}


//////////////////
//  ��ʃN���A  //
//////////////////
void Direct3D::clear()
{
    device_context_->ClearRenderTargetView( render_target_view_, DirectX::Colors::Black );
}

////////////
//  �j��  //
////////////
void Direct3D::destroy()
{
    // �C���^�[�t�F�C�X�̉��
    SAFE_RELEASE( render_target_view_ ); // �`��^�[�Q�b�g
    SAFE_RELEASE( swap_chain_ );         // �X���b�v�`�F�C��
    device_context_->ClearState();  // ����̐ݒ�ɖ߂�
    SAFE_RELEASE( device_context_ );     // �f�o�C�X�R���e�L�X�g
    SAFE_RELEASE( d3d_device_ );         // D3D�f�o�C�X

                                         // ���������
    delete common_states_;

}

HRESULT Direct3D::present()
{
    return swap_chain_->Present( 0, 0 );
}