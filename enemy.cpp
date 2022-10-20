#include "DxLib.h"
#include "game.h"
#include "enemy.h"

#include "SceneMain.h"

namespace
{
	// X方向、Y方向の最大速度
	constexpr float kSpeedMax = 4.0f;
	// 画像の回転速度
	constexpr float kRotaSpeed = 0.3f;
	// 敵の初期化座標
	constexpr float kSetEnemy = 1500.0f;
	// ショットの発射間隔
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
	m_pos.y = 100.0f;

	m_vec.x = kSpeedMax;
}

Vec2 Enemy::getRandPos()
{
	m_pos.x = Game::kScreenWidth;
	m_pos.y = static_cast<float>(GetRand(Game::kStageLowerLimit - Game::kStageUpperLimit) + Game::kStageUpperLimit);

	return m_pos;
}

// 画像のセット
void Enemy::setHandle(int handle)
{
	m_handle = handle;
	GetGraphSize(m_handle, &m_width, &m_height);
}

void Enemy::start(Vec2 pos)
{
	m_isExist = true;
	m_pos = pos;

	m_vec.x = static_cast<float>(GetRand(5)) + 5;
}

void Enemy::update()
{

	// ショットを撃つ処理
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
	/*if (m_isDead)
	{
		DrawRotaGraphF(m_pos.x + 15.0f, m_pos.y, 1.0, DX_PI, m_deadHandle, true, false);
	}
	else if (m_isDead)
	{
		DrawRotaGraphF(m_pos.x + 15.0f, m_pos.y, 1.0, DX_PI, m_deadHandle, true, true);
	}
	else if (m_isDead)
	{
		DrawTurnGraphF(m_pos.x, m_pos.y, m_deadHandle, true);
	}
	else if (m_isDead)
	{
		DrawGraphF(m_pos.x, m_pos.y, m_deadHandle, true);
	}
	else
	{
		DrawGraphF(m_pos.x, m_pos.y, m_aliveHandle, true);
	}

	DrawGraphF(m_pos.x, m_pos.y, m_handle, true);*/

	DrawRotaGraphF(getCenterX(), getCenterY(), 1.0, m_angle, m_handle, true, false);
	DrawCircle(getCenterX(), getCenterY(), 23, GetColor(255, 0, 0), false);
}