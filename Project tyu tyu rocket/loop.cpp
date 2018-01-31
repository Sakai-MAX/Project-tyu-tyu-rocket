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
//  �萔
//*****************************************************************************
const int kWindowWidth = 1280; // �E�B���h�E�T�C�Y�i���j
const int kWindowHeight = 720;  // �E�B���h�E�T�C�Y�i�c�j


                                //*****************************************************************************
                                //  ���O���
                                //*****************************************************************************
using namespace DirectX;
using namespace std::chrono;


//*****************************************************************************
//  �R���X�g���N�^
//*****************************************************************************
Loop::Loop()
{
    //�ŏ��Ɏ��s����V�[���ԍ���ݒ�
    work_no_ = kTitleInit;
}


//*****************************************************************************
//  ������
//*****************************************************************************
bool Loop::init( const HINSTANCE hInstance )
{
#ifdef _DEBUG
    // ���������[�N�̌������o
    //_CrtSetBreakAlloc( 220 );

    // ���������[�N�̃`�F�b�N���s���i�f�X�g���N�^�̌Ăяo�������ׂďI������i�K�Ń`�F�b�N�j
    _CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );
#endif


    // �E�B���h�E�̍쐬
    Window win;
    const HWND hWnd = win.create( hInstance, kWindowWidth, kWindowHeight );

    // �N���X������
    if( !Direct3D::init( hWnd, kWindowWidth, kWindowHeight ) ) return false;  // Direct3D������
    if( !Sprite::init() ) return false; // �X�v���C�g�N���X�̏�����
    if( !Font::init() )   return false; // �t�H���g�N���X�̏�����

                                        // COM���C�u�����̏�����
    if( FAILED( CoInitializeEx( NULL, COINIT_MULTITHREADED ) ) )
    {
        // �G���[
        return false;
    }




    // �E�B���h�E�̕\��
    ShowWindow( hWnd, SW_SHOWNORMAL );

    return true;
}


//*****************************************************************************
//  �X�V����
//*****************************************************************************
int Loop::update( const HINSTANCE hInstance )
{
    // ������
    if( !init( hInstance ) ) return 0;


    MSG msg = { NULL }; // ���b�Z�[�W�\����
    auto prev = high_resolution_clock::now(); // �O��̎���

                                              // ���C�����[�v
    while( msg.message != WM_QUIT )
    {
        // ���b�Z�[�W����
        if( PeekMessage( &msg, NULL, 0, 0, PM_REMOVE ) )
        {
            TranslateMessage( &msg );
            DispatchMessage( &msg );
        }
        else
        {
            // ���݂̎������擾
            const auto now = high_resolution_clock::now();
            auto elapsed = duration_cast<microseconds>(now - prev);

            // 60FPS�ɂ��邽�߂ɂ͖�16�~���b�ɂP��X�V����
            if( elapsed.count() >= 16666LL )
            {

                // ���݂̎������ȑO�̎����ɍX�V
                prev = now;

                // ���͂̎擾

                // ���͂̎擾
                KeyInput::update();
                PadInput::update();

                //�V�[�����̏���
                switch( work_no_ )
                {
                case kTitleInit:
                    //�^�C�g���N���X�̏�����
                    if( !title_.init() )
                    {
                        //�G���[
                        PostQuitMessage( 0 );
                    }
                    //���̏���
                    work_no_ = kTitleUpdate;
                    break;

                case kTitleUpdate:
                    //�^�C�g���N���X�X�V
                    if( !title_.update() )
                    {
                        //fakse���A���Ă�����^�C�g���I��

                        work_no_ = kGameInit;
                    }
                    break;

                case kGameInit:
                    //�Q�[���N���X������
                    if( !game_.init() )
                    {
                        //�G���[
                        PostQuitMessage( 0 );
                    }

                    //���̏�����
                    work_no_ = kGameUpdate;
                    break;

                case kGameUpdate:
                    //�Q�[���N���X�X�V
                    if( !game_.update() )
                    {
                        //false���A���Ă�����Q�[���I��
                        game_.destroy();
                        work_no_ = kTitleInit;
                    }
                    break;


                }


                draw(); // �`��
            }
        }
    }

    // COM���C�u�����̉��
    CoUninitialize();

    // ���
    Font::destroy();     // �t�H���g�N���X
    Sprite::destroy();   // �X�v���C�g�N���X
    Direct3D::destroy(); // Direct3D


    return 0;
}


//*****************************************************************************
//  �`��
//*****************************************************************************
void Loop::draw()
{
    Direct3D::clear();   // ��ʃN���A
    Sprite::Begin();     // �X�v���C�g�`��J�n

                         //�N���X�`��
    switch( work_no_ )
    {
    case kTitleUpdate:
        title_.draw();
        break;

    case kGameUpdate:
        game_.draw();
        break;
    }


    Sprite::End();       // �X�v���C�g�`��I��    
    Direct3D::present(); // ��ʍX�V����
}


//*****************************************************************************
//  �f�X�g���N�^
//*****************************************************************************
Loop::~Loop()
{
}