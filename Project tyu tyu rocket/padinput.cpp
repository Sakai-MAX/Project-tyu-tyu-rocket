#include "padinput.h"


//////////////////
//  ���̂̐錾  //
//////////////////
GamePad PadInput::pad_;                             // �p�b�h�N���X
GamePad::ButtonStateTracker PadInput::pad_tracker_; // �{�^���X�e�[�g�g���b�J�[
GamePad::State PadInput::State_;                    // �p�b�h���͏��

                                                    //////////////
                                                    // �X�V���� //
                                                    //////////////
void PadInput::update()
{
    // �p�b�h���͂��擾���ăg���b�J�[���X�V
    State_ = pad_.GetState( 0 );
    pad_tracker_.Update( State_ );
}