#include "window.h"
#include "error.h"
#include "resource.h"

////////////////////////////
//  　プロトタイプ宣言　　//
////////////////////////////
LRESULT CALLBACK windowProc( HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam );


////////////////////////////
//    ウィンドウの作成　　//
//////////////////////////// 
const HWND Window::create( HINSTANCE hInstance, const int Width, const int Height )
{
    // ウィンドウクラスの作成
    WNDCLASSEX wnd;
    ZeroMemory( &wnd, sizeof( wnd ) );                              // ゼロクリア
    wnd.cbSize = sizeof( WNDCLASSEX );                       // 構造体のサイズ
    wnd.style = CS_HREDRAW | CS_VREDRAW;                    // スタイル
    wnd.hInstance = hInstance;                                  // アプリケーションインスタンス
    wnd.lpszClassName = L"ClassName";                               // クラス名
    wnd.hCursor = LoadCursor( NULL, IDC_ARROW );              // カーソル形状
    wnd.hbrBackground = reinterpret_cast<HBRUSH>(COLOR_WINDOW + 1); // デフォルトの背景色
    wnd.lpfnWndProc = windowProc;                                 // コールバック関数ポインタの登録
    wnd.hIcon = LoadIcon( hInstance, reinterpret_cast<wchar_t*>(IDI_ICON1) );   //アイコンの設定
                                                                                //wnd.hIconSm       ウィンドウのアイコンの変更

                                                                                // ウィンドウクラスの登録
    if( !RegisterClassEx( &wnd ) )
    {
        // エラー
        return NULL;
    }

    // ウィンドウサイズの決定
    RECT rect = { 0L, 0L, Width, Height };
    const DWORD style = WS_OVERLAPPEDWINDOW & ~WS_THICKFRAME & ~WS_MAXIMIZEBOX;
    const DWORD ex_style = WS_EX_OVERLAPPEDWINDOW;
    AdjustWindowRectEx( &rect, style, false, ex_style );

    // ウィンドウの作成
    const HWND hWnd = CreateWindowEx(
        ex_style,               // 拡張ウィンドウスタイル
        L"ClassName",           // クラス名
        L"Game",                // ウィンドウ名
        style,                  // ウィンドウスタイル
        CW_USEDEFAULT,          // 表示座標X
        CW_USEDEFAULT,          // 表示座標Y
        rect.right - rect.left, // ウィンドウサイズX
        rect.bottom - rect.top, // ウィンドウサイズY
        NULL,                   // 親ウィンドウまたはオーナーウィンドウのハンドル
        NULL,                   // メニューハンドルまたは子識別子
        hInstance,              // アプリケーションのインスタンス
        NULL );                 // ウィンドウ作成データ

                                // ウィンドウハンドルは取得できたか
    if( !hWnd )
    {
        // エラー
        Error::showDialog( L"ウィンドウハンドルの取得に失敗" );
        return NULL;
    }

    return hWnd;
}


////////////////////////////////////
//  　ウィンドウプロシージャー　　//
////////////////////////////////////
LRESULT CALLBACK windowProc( HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam )
{
    PAINTSTRUCT ps;
    HDC hdc;

    switch( msg )
    {
    case WM_PAINT:
        hdc = BeginPaint( hWnd, &ps );
        EndPaint( hWnd, &ps );
        break;

    case WM_KEYDOWN:
        switch( wParam )
        {
        case VK_ESCAPE: // ESCキーが押されたら終了
            PostMessage( hWnd, WM_CLOSE, 0, 0 );
            break;
        }
        break;

        // マウス入力を取得するため以下の処理を追加する
    case WM_ACTIVATEAPP:
    case WM_INPUT:
    case WM_MOUSEMOVE:
    case WM_LBUTTONDOWN:
    case WM_LBUTTONUP:
    case WM_RBUTTONDOWN:
    case WM_RBUTTONUP:
    case WM_MBUTTONDOWN:
    case WM_MBUTTONUP:
    case WM_MOUSEWHEEL:
    case WM_XBUTTONDOWN:
    case WM_XBUTTONUP:
    case WM_MOUSEHOVER:
        Mouse::ProcessMessage( msg, wParam, lParam );
        break;
        // ここまで

    case WM_DESTROY:
        PostQuitMessage( 0 );
        break;
    }

    return DefWindowProc( hWnd, msg, wParam, lParam );
}