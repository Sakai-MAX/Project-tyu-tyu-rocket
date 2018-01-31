#include "keyinput.h"

//////////////////
//  実体の宣言  //
//////////////////
Keyboard KeyInput::key_;                               //キーボードクラス
Keyboard::KeyboardStateTracker KeyInput::key_tracker_; // キーボードステートトラッカー
Keyboard::State KeyInput::state_;                      // キー入力状態


                                                       ////////////////
                                                       //　更新処理  //
                                                       ////////////////
void KeyInput::update()
{
    //キー入力を取得してトラッカーを更新
    state_ = key_.GetState();
    key_tracker_.Update( state_ );
}