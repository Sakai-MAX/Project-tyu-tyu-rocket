#pragma once
/////////////
//  Class  //
/////////////
class PadInput
{
private:
    static GamePad pad_;                             // �p�b�h�N���X
    static GamePad::ButtonStateTracker pad_tracker_; // �{�^���X�e�[�g�g���b�J�[
    static GamePad::State State_;                    // �p�b�h���͏��
    static GamePad::ThumbSticks kaiten_;

public:
    static void update(); // �p�b�h���͂̎擾
    static GamePad::State State() { return State_; }
    // �{�^���X�e�[�g�g���b�J�[��Ԃ�
    static GamePad::ButtonStateTracker getTracker() { return pad_tracker_; }
};