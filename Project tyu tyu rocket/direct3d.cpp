#include "direct3d.h"
#include "error.h"
#include <DirectXColors.h>
#include "release.h"


////////////////////////////////////
//           実体の宣言           //
////////////////////////////////////
ID3D11Device*           Direct3D::d3d_device_;         // D3Dデバイス
ID3D11DeviceContext*    Direct3D::device_context_;     // デバイスコンテキスト 
IDXGISwapChain*         Direct3D::swap_chain_;         // スワップチェイン
D3D_FEATURE_LEVEL       Direct3D::feature_level_;      // 機能レベル
ID3D11RenderTargetView* Direct3D::render_target_view_; // 描画ターゲットビュー
CommonStates*           Direct3D::common_states_;      // ステートクラス


                                                       ///////////////////////////////////////////////////////////////////                                                       
                                                       //  初期化(ウィンドウハンドルとウィンドウサイズを引数で受け取る）//
                                                       ///////////////////////////////////////////////////////////////////
bool Direct3D::init( const HWND hWnd, const int Width, const int Height )
{
    // 機能レベルの設定
    D3D_FEATURE_LEVEL level_array[] =
    {
        D3D_FEATURE_LEVEL_11_0,
        D3D_FEATURE_LEVEL_10_1,
        D3D_FEATURE_LEVEL_10_0,
    };

    // スワップチェインの設定
    DXGI_SWAP_CHAIN_DESC sc;
    ZeroMemory( &sc, sizeof( sc ) );                                       // 初期化
    sc.Windowed = true;                            // ウィンドウモード
    sc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;        // スワップエフェクト
    sc.OutputWindow = hWnd;                            // ウィンドウハンドル
    sc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT; // バックバッファの使用法
    sc.BufferCount = 1U;                              // バックバッファ数
    sc.BufferDesc.Width = Width;                           // バックバッファサイズ（横）
    sc.BufferDesc.Height = Height;                          // バックバッファサイズ（縦）
    sc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;      // フォーマット
    sc.BufferDesc.RefreshRate.Numerator = 60U;                             // リフレッシュレート分子
    sc.BufferDesc.RefreshRate.Denominator = 1U;                              // リフレッシュレート分母
    sc.SampleDesc.Count = 1;                               // マルチサンプリング
    sc.SampleDesc.Quality = 0;                               // マルチサンプリング品質
    sc.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;	                     // モード自動切り替え

                                                                             // 要素数を計算
    int num_feature_level = sizeof( level_array ) / sizeof( level_array[ 0 ] );

    // スワップチェーン、D3DDevice、D3DDeviceContextを作成する
    if( FAILED( D3D11CreateDeviceAndSwapChain(
        NULL,                      // DXGIアダプター
        D3D_DRIVER_TYPE_HARDWARE,  // ドライバータイプ
        NULL,                      // ソフトウェアラスタライザーを実装するDLLハンドル
        D3D11_CREATE_DEVICE_DEBUG, // フラグ
        level_array,               // 機能レベル
        num_feature_level,         // レベル個数
        D3D11_SDK_VERSION,         // 常にこの値
        &sc,                       // スワップチェーン初期パラメータ構造体
        &swap_chain_,              // スワップチェーンポインタ
        &d3d_device_,              // D3DDevice
        &feature_level_,           // 設定した機能レベル
        &device_context_ ) ) )     // DeviceContext
    {
        // エラー
        return false;
    }

    // バックバッファ描画ターゲットの取得
    ID3D11Texture2D* backbuffer = NULL;
    if( FAILED( swap_chain_->GetBuffer( 0, __uuidof(ID3D11Texture2D), reinterpret_cast<void**>(&backbuffer) ) ) )
    {
        // エラー
        return false;
    }

    // 描画ターゲット・ビューの作成
    if( FAILED( d3d_device_->CreateRenderTargetView(
        backbuffer,               // ビューでアクセスするリソース
        NULL,                     // ターゲットビューの定義
        &render_target_view_ ) ) ) // ターゲットビュー格納先
    {
        // エラー
        return false;
    }

    // バックバッファ解放
    backbuffer->Release();

    // 描画ターゲットビューを出力マネージャーの描画ターゲットとして設定
    device_context_->OMSetRenderTargets(
        1,					  // 描画ターゲット数（8まで可)
        &render_target_view_, // ターゲットビュー配列
        NULL );               // 深度/ステンシルビュー

                              // ビューポート作成
    D3D11_VIEWPORT vp;
    vp.Width = static_cast<float>(Width);   // 描画領域幅
    vp.Height = static_cast<float>(Height);  // 描画領域高さ
    vp.MinDepth = 0.0F;   // 描画領域最小深度値
    vp.MaxDepth = 1.0F;   // 描画領域最大深度値
    vp.TopLeftX = 0;      //描画開始位置X
    vp.TopLeftY = 0;      //描画開始位置Y

                          // ビューポートを設定
    device_context_->RSSetViewports( 1, &vp );

    // ステートクラスのメモリ確保
    common_states_ = new CommonStates( d3d_device_ );

    // メモリ確保チェック
    if( !common_states_ )
    {
        // エラー
        Error::showDialog( L"ステートクラスのメモリ確保に失敗" );
        return false;
    }

    return true;
}


//////////////////
//  画面クリア  //
//////////////////
void Direct3D::clear()
{
    device_context_->ClearRenderTargetView( render_target_view_, DirectX::Colors::Black );
}

////////////
//  破棄  //
////////////
void Direct3D::destroy()
{
    // インターフェイスの解放
    SAFE_RELEASE( render_target_view_ ); // 描画ターゲット
    SAFE_RELEASE( swap_chain_ );         // スワップチェイン
    device_context_->ClearState();  // 既定の設定に戻す
    SAFE_RELEASE( device_context_ );     // デバイスコンテキスト
    SAFE_RELEASE( d3d_device_ );         // D3Dデバイス

                                         // メモリ解放
    delete common_states_;

}

HRESULT Direct3D::present()
{
    return swap_chain_->Present( 0, 0 );
}