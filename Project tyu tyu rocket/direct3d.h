#pragma once
////////////////////////////////////
//             Class              //
////////////////////////////////////
class Direct3D
{
private:
    static ID3D11Device*           d3d_device_;         // D3Dデバイス
    static ID3D11DeviceContext*    device_context_;     // デバイスコンテキスト 
    static IDXGISwapChain*         swap_chain_;         // スワップチェイン
    static D3D_FEATURE_LEVEL       feature_level_;      // 機能レベル
    static ID3D11RenderTargetView* render_target_view_; // 描画ターゲットビュー
    static CommonStates*           common_states_;      // ステートクラス

public:
    static bool init( const HWND hWnd, const int Width, const int Height ); // 初期化
    static void destroy();               // 破棄
    static void clear();                 // 画面クリア
    static HRESULT present();            // 画面更新

                                         // 各種インターフェイスを返す関数
    static ID3D11Device*        getDevice()  { return d3d_device_; }
    static ID3D11DeviceContext* getContext() { return device_context_; }
    static IDXGISwapChain*      getChain()   { return swap_chain_; }
    static CommonStates*        getStates()  { return common_states_; }
};