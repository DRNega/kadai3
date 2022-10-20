#include "SceneTitle.h"
#include "DxLib.h"
#include "game.h"

namespace
{
	// �^�C�g�����b�Z�[�W
	const char* const kTitleMessage = "Z�L�[ or A�{�^����������";
	const char* const kGameStart = "�X�^�[�g";
}

void SceneTitle::init()
{
	m_handle = LoadGraph("data/kidan2.png");
	GetGraphSize(m_handle, &m_width, &m_height);

	// �w�i�摜
	m_hBackgroundGraphic = LoadGraph(Game::kBackgroundGraph);

	m_TextPosY = 0;
	m_TextVecY = 4;

	//m_angle = 0;

	m_isEnd = false;

}

// �I������
void SceneTitle::end()
{
	DeleteGraph(m_handle);
	DeleteGraph(m_hBackgroundGraphic);
}

void SceneTitle::update()
{
	// �����̈ړ�
	/*m_LeftTextPosY += m_LeftTextVecY;
	if (m_LeftTextPosY < 0)
	{
		m_LeftTextPosY = 0;
		m_LeftTextVecY = 4;
	}
	if (m_LeftTextPosY > 200)
	{
		m_LeftTextPosY = 200;
		m_LeftTextVecY = -4;
	}*/

	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	if (padState & PAD_INPUT_1)
	{
		m_isEnd = true;
	}
}

void SceneTitle::draw()
{
	// �w�i�摜��ǂݍ���ŕ\��
	DrawGraph(0, 0, m_hBackgroundGraphic, true);

	// �Q�[���^�C�g���̉摜�\��
	DrawGraph(0, m_TextPosY, m_handle, true);
	DrawGraph(Game::kScreenWidth - m_width, m_TextPosY, m_handle, true);

	DrawRotaGraphF(Game::kScreenWidthHalf, Game::kScreenHeight / 3, 1.5, 0, m_handle, true, false);

	SetFontSize(60);

	/*DrawString(0, m_LeftTextPosY, "YYYYYY", GetColor(255, 255, 255));
	DrawString(Game::kScreenWidth - 187, m_LeftTextPosY, "YYYYYY", GetColor(255, 255, 255));

	DrawString(Game::kScreenWidth / 2 - 90, 210, "YYYYYY", GetColor(255, 255, 255));*/

	SetFontSize(30);
	DrawString(Game::kScreenWidth / 2 - GetDrawStringWidth(kTitleMessage, 12), Game::kScreenHeight / 2, kTitleMessage, GetColor(255, 255, 255));
	DrawString(Game::kScreenWidth / 2 - GetDrawStringWidth(kGameStart, 4), Game::kScreenHeight / 2 + 30, kGameStart, GetColor(255, 255, 255));
}