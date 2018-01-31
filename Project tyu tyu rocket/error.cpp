//////////////////////////////
// メッセージボックスの表示 //
//////////////////////////////
#include"error.h"

void Error::showDialog( wchar_t* Message )
{
    //引数で受け取ったメッセージを表示
    MessageBox(
        NULL,                   //ウィンドウハンドル
        Message,                //表示するメッセージ
        L"ERROR",               //タイトルに表示する文字列
        MB_OK | MB_ICONERROR | MB_ICONSTOP | MB_TASKMODAL );   //ダイアログタイプ
}

