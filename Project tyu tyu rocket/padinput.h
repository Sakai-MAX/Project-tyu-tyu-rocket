#pragma once
/////////////
//  Class  //
/////////////
class PadInput
{
private:
    static GamePad pad_;                             // パッドクラス
    static GamePad::ButtonStateTracker pad_tracker_; // ボタンステートトラッカー
    static GamePad::State State_;                    // パッド入力状態
    static GamePad::ThumbSticks kaiten_;

public:
    static void update(); // パッド入力の取得
    static GamePad::State State() { return State_; }
    // ボタンステートトラッカーを返す
    static GamePad::ButtonStateTracker getTracker() { return pad_tracker_; }
};