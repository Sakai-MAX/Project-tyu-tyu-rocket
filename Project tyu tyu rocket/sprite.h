#pragma once
class Sprite
{
private:
    static SpriteBatch* sprite_;   // �X�v���C�g�o�b�`

public:
    static bool init();    // ������
    static void destroy(); // �j��
    static void Begin();   // �X�v���C�g�̕`��J�n
    static void End();     // �X�v���C�g�̕`��I��

                           // �`��֐�
    static void Draw(
        ID3D11ShaderResourceView* Texture,                  // �V�F�[�_���\�[�X�r���[
        const Vector2& Position = Vector2( 0.0F, 0.0F ),    // ���W
        const RECT* pRect = NULL,                           // �`��͈�
        const int   Alpha = 255,                            // �A���t�@�n
        const float Rotation = 0.0F,                        // ��]�l
        const SpriteEffects Effect = SpriteEffects_None,    // �X�v���C�g�G�t�F�N�g
        const Vector2& Scale = Vector2( 1.0F, 1.0F ),       // �g�k
        const Vector2& Origin = Vector2( 0.0F, 1.0F ),      // �A���J�[�|�C���g
        const float Depth = 0.0F );                         // �[�x�l

                                                            // �X�v���C�g�o�b�`�N���X��Ԃ�
    static SpriteBatch* getSprite() { return sprite_; }
};