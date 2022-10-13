#include "DxLib.h"
#include "game.h"
#include "shotBase.h"

namespace
{
	constexpr float kShotSpeed = 8.0f;
	constexpr double m_angle = 90.0f;
}

ShotBase::ShotBase()
{
	m_handle = -1;
	m_pos.x = 100.0f;
	m_pos.y = 100.0f;

	m_vec.x = 8.0f;
	m_vec.y = 0.0f;

	m_isExist = false;
}

ShotBase::~ShotBase()
{

}

void ShotBase::start(Vec2 pos)
{
	m_isExist = true;
	m_pos = pos;

	m_vec.x = kShotSpeed;
	m_vec.y = 0.0f;
}

void ShotBase::update()
{
	if (!m_isExist) return;
	m_pos += m_vec;

	if (m_pos.x > Game::kScreenWidth)
	{
		m_isExist = false;
	}
}
// �\��
void ShotBase::draw()
{
	if (!m_isExist) return;
	DrawRotaGraph(m_pos.x, m_pos.y, 1.0, 90, m_handle, true, false);
}
