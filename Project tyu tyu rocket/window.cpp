#include "window.h"
#include "error.h"
#include "resource.h"

////////////////////////////
//  �@�v���g�^�C�v�錾�@�@//
////////////////////////////
LRESULT CALLBACK windowProc( HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam );


////////////////////////////
//    �E�B���h�E�̍쐬�@�@//
//////////////////////////// 
const HWND Window::create( HINSTANCE hInstance, const int Width, const int Height )
{
    // �E�B���h�E�N���X�̍쐬
    WNDCLASSEX wnd;
    ZeroMemory( &wnd, sizeof( wnd ) );                              // �[���N���A
    wnd.cbSize = sizeof( WNDCLASSEX );                       // �\���̂̃T�C�Y
    wnd.style = CS_HREDRAW | CS_VREDRAW;                    // �X�^�C��
    wnd.hInstance = hInstance;                                  // �A�v���P�[�V�����C���X�^���X
    wnd.lpszClassName = L"ClassName";                               // �N���X��
    wnd.hCursor = LoadCursor( NULL, IDC_ARROW );              // �J�[�\���`��
    wnd.hbrBackground = reinterpret_cast<HBRUSH>(COLOR_WINDOW + 1); // �f�t�H���g�̔w�i�F
    wnd.lpfnWndProc = windowProc;                                 // �R�[���o�b�N�֐��|�C���^�̓o�^
    wnd.hIcon = LoadIcon( hInstance, reinterpret_cast<wchar_t*>(IDI_ICON1) );   //�A�C�R���̐ݒ�
                                                                                //wnd.hIconSm       �E�B���h�E�̃A�C�R���̕ύX

                                                                                // �E�B���h�E�N���X�̓o�^
    if( !RegisterClassEx( &wnd ) )
    {
        // �G���[
        return NULL;
    }

    // �E�B���h�E�T�C�Y�̌���
    RECT rect = { 0L, 0L, Width, Height };
    const DWORD style = WS_OVERLAPPEDWINDOW & ~WS_THICKFRAME & ~WS_MAXIMIZEBOX;
    const DWORD ex_style = WS_EX_OVERLAPPEDWINDOW;
    AdjustWindowRectEx( &rect, style, false, ex_style );

    // �E�B���h�E�̍쐬
    const HWND hWnd = CreateWindowEx(
        ex_style,               // �g���E�B���h�E�X�^�C��
        L"ClassName",           // �N���X��
        L"Game",                // �E�B���h�E��
        style,                  // �E�B���h�E�X�^�C��
        CW_USEDEFAULT,          // �\�����WX
        CW_USEDEFAULT,          // �\�����WY
        rect.right - rect.left, // �E�B���h�E�T�C�YX
        rect.bottom - rect.top, // �E�B���h�E�T�C�YY
        NULL,                   // �e�E�B���h�E�܂��̓I�[�i�[�E�B���h�E�̃n���h��
        NULL,                   // ���j���[�n���h���܂��͎q���ʎq
        hInstance,              // �A�v���P�[�V�����̃C���X�^���X
        NULL );                 // �E�B���h�E�쐬�f�[�^

                                // �E�B���h�E�n���h���͎擾�ł�����
    if( !hWnd )
    {
        // �G���[
        Error::showDialog( L"�E�B���h�E�n���h���̎擾�Ɏ��s" );
        return NULL;
    }

    return hWnd;
}


////////////////////////////////////
//  �@�E�B���h�E�v���V�[�W���[�@�@//
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
        case VK_ESCAPE: // ESC�L�[�������ꂽ��I��
            PostMessage( hWnd, WM_CLOSE, 0, 0 );
            break;
        }
        break;

        // �}�E�X���͂��擾���邽�߈ȉ��̏�����ǉ�����
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
        // �����܂�

    case WM_DESTROY:
        PostQuitMessage( 0 );
        break;
    }

    return DefWindowProc( hWnd, msg, wParam, lParam );
}