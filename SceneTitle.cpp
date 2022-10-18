#include "SceneTitle.h"
#include "DxLib.h"
#include "game.h"

namespace
{
	// �^�C�g�����b�Z�[�W
	const char* const kTitleMessage = "Z�L�[ or A�{�^����������";
	const char* const kGameStart = "�X�^�[�g";
	// �e�L�X�g�̉�]�p�x
	constexpr float kRotaSpeed = 0.02f;
}

void SceneTitle::init()
{
	m_TextPosY = 0;
	m_TextVecY = 4;

	m_angle = 0;

	m_isEnd = false;

	m_handle = LoadGraph("data/kidan2.png");
	GetGraphSize(m_handle, &m_width, &m_height);
}

// �I������
void SceneTitle::end()
{
	DeleteGraph(m_handle);
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
	SetFontSize(60);

	/*DrawString(0, m_LeftTextPosY, "YYYYYY", GetColor(255, 255, 255));
	DrawString(Game::kScreenWidth - 187, m_LeftTextPosY, "YYYYYY", GetColor(255, 255, 255));

	DrawString(Game::kScreenWidth / 2 - 90, 210, "YYYYYY", GetColor(255, 255, 255));*/

	SetFontSize(30);
	DrawString(Game::kScreenWidth / 2 - 180, Game::kScreenHeight / 2, "Z�L�[ or A�{�^����������", GetColor(255, 255, 255));
	DrawString(Game::kScreenWidth / 2 - 105, Game::kScreenHeight / 2 + 30, "�Q�[���X�^�[�g", GetColor(255, 255, 255));
}