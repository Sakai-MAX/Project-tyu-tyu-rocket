#pragma once
/////////////////
//  �@Class�@�@//
/////////////////
class KeyInput
{
private:
    static Keyboard key_;                               // �L�[�{�[�h�N���X
    static Keyboard::KeyboardStateTracker key_tracker_; // �L�[�{�[�h�X�e�[�g�g���b�J�[
    static Keyboard::State state_;                      // �L�[���͏��

public:
    static void update(); // �L�[���͂̎�

                          // �L�[�{�[�h�ƃX�e�[�g�g���b�J�[��Ԃ��֐�
    static Keyboard::State getState() { return state_; }
    static Keyboard::KeyboardStateTracker getTracker() { return key_tracker_; }
};