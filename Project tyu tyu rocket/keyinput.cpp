#include "keyinput.h"

//////////////////
//  ���̂̐錾  //
//////////////////
Keyboard KeyInput::key_;                               //�L�[�{�[�h�N���X
Keyboard::KeyboardStateTracker KeyInput::key_tracker_; // �L�[�{�[�h�X�e�[�g�g���b�J�[
Keyboard::State KeyInput::state_;                      // �L�[���͏��


                                                       ////////////////
                                                       //�@�X�V����  //
                                                       ////////////////
void KeyInput::update()
{
    //�L�[���͂��擾���ăg���b�J�[���X�V
    state_ = key_.GetState();
    key_tracker_.Update( state_ );
}