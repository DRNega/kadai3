#include "DxLib.h"
#include "game.h"
#include "enemy.h"

#include "SceneMain.h"

namespace
{
	// X�����AY�����̍ő呬�x
	constexpr float kSpeedMax = 4.0f;
	// �摜�̉�]���x
	constexpr float kRotaSpeed = 0.3f;
	// �G�̏��������W
	constexpr float kSetEnemy = 1500.0f;
	// �V���b�g�̔��ˊԊu
	constexpr int kShotInterval = 8;
}

Enemy::Enemy()
{
	m_handle = -1;
	m_height = 0;
	m_width = 0;
	m_shotInterval = 0;

	m_angle = 0.0f;

	m_isExist = false;
}

Enemy::~Enemy()
{

}

void Enemy::init()
{
	m_pos.x = kSetEnemy;
	m_pos.y = 180.0f;

	m_vec.x = kSpeedMax;
}

Vec2 Enemy::getRandPos()
{
	m_pos.x = Game::kScreenWidth;
	m_pos.y = static_cast<float>(GetRand(Game::kStageLowerLimit - Game::kStageUpperLimit) + Game::kStageUpperLimit);

	return m_pos;
}

void Enemy::start(Vec2 pos)
{
	m_isExist = true;
	m_pos = pos;

	m_vec.x = static_cast<float>(GetRand(5)) + 5;
}

void Enemy::update()
{

	// �V���b�g��������
	m_shotInterval--;
	if (m_shotInterval < 0) m_shotInterval = 0;

	m_pos -= m_vec;

	m_angle -= kRotaSpeed;
	if (m_pos.x < 0)
	{
		m_isExist = false;
	}
}

void Enemy::draw()
{
	DrawGraphF(m_pos.x, m_pos.y, m_handle, true);
}