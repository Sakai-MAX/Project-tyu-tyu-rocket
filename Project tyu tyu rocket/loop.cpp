#include "loop.h"
#include "window.h"
#include "direct3d.h"
#include "sprite.h"
#include "keyinput.h"
#include "padinput.h"
#include "player.h"
#include "field.h"
#include "error.h"
#include "game.h"
#include "font.h"


//*****************************************************************************
//  定数
//*****************************************************************************
const int kWindowWidth = 1280; // ウィンドウサイズ（横）
const int kWindowHeight = 720;  // ウィンドウサイズ（縦）


                                //*****************************************************************************
                                //  名前空間
                                //*****************************************************************************
using namespace DirectX;
using namespace std::chrono;


//*****************************************************************************
//  コンストラクタ
//*****************************************************************************
Loop::Loop()
{
    //最初に実行するシーン番号を設定
    work_no_ = kTitleInit;
}


//*****************************************************************************
//  初期化
//*****************************************************************************
bool Loop::init( const HINSTANCE hInstance )
{
#ifdef _DEBUG
    // メモリリークの個所を検出
    //_CrtSetBreakAlloc( 220 );

    // メモリリークのチェックを行う（デストラクタの呼び出しがすべて終わった段階でチェック）
    _CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );
#endif


    // ウィンドウの作成
    Window win;
    const HWND hWnd = win.create( hInstance, kWindowWidth, kWindowHeight );

    // クラス初期化
    if( !Direct3D::init( hWnd, kWindowWidth, kWindowHeight ) ) return false;  // Direct3D初期化
    if( !Sprite::init() ) return false; // スプライトクラスの初期化
    if( !Font::init() )   return false; // フォントクラスの初期化

                                        // COMライブラリの初期化
    if( FAILED( CoInitializeEx( NULL, COINIT_MULTITHREADED ) ) )
    {
        // エラー
        return false;
    }




    // ウィンドウの表示
    ShowWindow( hWnd, SW_SHOWNORMAL );

    return true;
}


//*****************************************************************************
//  更新処理
//*****************************************************************************
int Loop::update( const HINSTANCE hInstance )
{
    // 初期化
    if( !init( hInstance ) ) return 0;


    MSG msg = { NULL }; // メッセージ構造体
    auto prev = high_resolution_clock::now(); // 前回の時刻

                                              // メインループ
    while( msg.message != WM_QUIT )
    {
        // メッセージ処理
        if( PeekMessage( &msg, NULL, 0, 0, PM_REMOVE ) )
        {
            TranslateMessage( &msg );
            DispatchMessage( &msg );
        }
        else
        {
            // 現在の時刻を取得
            const auto now = high_resolution_clock::now();
            auto elapsed = duration_cast<microseconds>(now - prev);

            // 60FPSにするためには約16ミリ秒に１回更新する
            if( elapsed.count() >= 16666LL )
            {

                // 現在の時刻を以前の時刻に更新
                prev = now;

                // 入力の取得

                // 入力の取得
                KeyInput::update();
                PadInput::update();

                //シーン毎の処理
                switch( work_no_ )
                {
                case kTitleInit:
                    //タイトルクラスの初期化
                    if( !title_.init() )
                    {
                        //エラー
                        PostQuitMessage( 0 );
                    }
                    //次の処理
                    work_no_ = kTitleUpdate;
                    break;

                case kTitleUpdate:
                    //タイトルクラス更新
                    if( !title_.update() )
                    {
                        //fakseが帰ってきたらタイトル終了

                        work_no_ = kGameInit;
                    }
                    break;

                case kGameInit:
                    //ゲームクラス初期化
                    if( !game_.init() )
                    {
                        //エラー
                        PostQuitMessage( 0 );
                    }

                    //次の処理へ
                    work_no_ = kGameUpdate;
                    break;

                case kGameUpdate:
                    //ゲームクラス更新
                    if( !game_.update() )
                    {
                        //falseが帰ってきたらゲーム終了
                        game_.destroy();
                        work_no_ = kTitleInit;
                    }
                    break;


                }


                draw(); // 描画
            }
        }
    }

    // COMライブラリの解放
    CoUninitialize();

    // 解放
    Font::destroy();     // フォントクラス
    Sprite::destroy();   // スプライトクラス
    Direct3D::destroy(); // Direct3D


    return 0;
}


//*****************************************************************************
//  描画
//*****************************************************************************
void Loop::draw()
{
    Direct3D::clear();   // 画面クリア
    Sprite::Begin();     // スプライト描画開始

                         //クラス描画
    switch( work_no_ )
    {
    case kTitleUpdate:
        title_.draw();
        break;

    case kGameUpdate:
        game_.draw();
        break;
    }


    Sprite::End();       // スプライト描画終了    
    Direct3D::present(); // 画面更新処理
}


//*****************************************************************************
//  デストラクタ
//*****************************************************************************
Loop::~Loop()
{
}