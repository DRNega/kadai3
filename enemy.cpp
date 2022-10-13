#include "DxLib.h"
#include "game.h"
#include "enemy.h"

#include "SceneMain.h"

namespace
{
	// X�����AY�����̍ő呬�x
	constexpr float kSpeedMax = 8.0f;
	constexpr float kAcc = 0.4f;
	// �V���b�g�̔��ˊԊu
	constexpr int kShotInterval = 8;
}

Enemy::Enemy()
{
	m_handle = -1;
	m_pMain = nullptr;
	m_shotInterval = 0;
}

Enemy::~Enemy()
{

}

void Enemy::init()
{
	m_pos.x = 125.0f;
	m_pos.y = 125.0f;
	m_vec.x = 0.0f;
	m_vec.y = 0.0f;
	m_shotInterval = 0;
}

void Enemy::update()
{

	// �V���b�g��������
	m_shotInterval--;
	if (m_shotInterval < 0) m_shotInterval = 0;

	


	m_pos += m_vec;
}

void Enemy::draw()
{
	DrawGraphF(m_pos.x, m_pos.y, m_handle, true);
}