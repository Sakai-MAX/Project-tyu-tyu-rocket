#include "padinput.h"


//////////////////
//  実体の宣言  //
//////////////////
GamePad PadInput::pad_;                             // パッドクラス
GamePad::ButtonStateTracker PadInput::pad_tracker_; // ボタンステートトラッカー
GamePad::State PadInput::State_;                    // パッド入力状態

                                                    //////////////
                                                    // 更新処理 //
                                                    //////////////
void PadInput::update()
{
    // パッド入力を取得してトラッカーを更新
    State_ = pad_.GetState( 0 );
    pad_tracker_.Update( State_ );
}