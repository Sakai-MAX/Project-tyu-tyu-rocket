#pragma once
/////////////////
//  　Class　　//
/////////////////
class KeyInput
{
private:
    static Keyboard key_;                               // キーボードクラス
    static Keyboard::KeyboardStateTracker key_tracker_; // キーボードステートトラッカー
    static Keyboard::State state_;                      // キー入力状態

public:
    static void update(); // キー入力の取

                          // キーボードとステートトラッカーを返す関数
    static Keyboard::State getState() { return state_; }
    static Keyboard::KeyboardStateTracker getTracker() { return key_tracker_; }
};