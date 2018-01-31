#pragma once
////////////////////////////////////
//             Class              //
////////////////////////////////////
class Direct3D
{
private:
    static ID3D11Device*           d3d_device_;         // D3D�f�o�C�X
    static ID3D11DeviceContext*    device_context_;     // �f�o�C�X�R���e�L�X�g 
    static IDXGISwapChain*         swap_chain_;         // �X���b�v�`�F�C��
    static D3D_FEATURE_LEVEL       feature_level_;      // �@�\���x��
    static ID3D11RenderTargetView* render_target_view_; // �`��^�[�Q�b�g�r���[
    static CommonStates*           common_states_;      // �X�e�[�g�N���X

public:
    static bool init( const HWND hWnd, const int Width, const int Height ); // ������
    static void destroy();               // �j��
    static void clear();                 // ��ʃN���A
    static HRESULT present();            // ��ʍX�V

                                         // �e��C���^�[�t�F�C�X��Ԃ��֐�
    static ID3D11Device*        getDevice()  { return d3d_device_; }
    static ID3D11DeviceContext* getContext() { return device_context_; }
    static IDXGISwapChain*      getChain()   { return swap_chain_; }
    static CommonStates*        getStates()  { return common_states_; }
};