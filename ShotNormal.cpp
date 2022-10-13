#include "ShotNormal.h"
#include "game.h"

namespace
{
	constexpr float kShotSpeed = 8.0f;
	constexpr float kRotaSpeed = 0.2f;
}

void ShotNormal::start(Vec2 pos)
{
	ShotBase::start(pos);

	m_vec.x = kShotSpeed;
	m_vec.y = 0.0f;
}

void ShotNormal::update()
{
	if (!m_isExist) return;
	m_pos += m_vec;
	if (m_pos.x > Game::kScreenWidth)
	{
		m_isExist = false;
	}

	m_angle += kRotaSpeed;
}
