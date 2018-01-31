#include "loop.h"


//WinMain
int WINAPI wWinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int CmdShow )
{
    Loop loop;
    return loop.update( hInstance );
}