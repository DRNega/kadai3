#include "DxLib.h"
#include "game.h"
#include "player.h"

#include "SceneMain.h"

namespace
{
	// X方向、Y方向の最大速度
	constexpr float kSpeedMax = 4.0f;
	constexpr float kAcc = 0.4f;
	// ショットの発射間隔
	constexpr int kShotInterval = 16;
}

Player::Player()
{
	m_handle = -1;
	m_pMain = nullptr;
	m_shotInterval = 0;

	m_isDead = false;
}

Player::~Player()
{

}

void Player::init()
{
	m_isDead = false;

	m_pos.x = 100.0f;
	m_pos.y = 100.0f;
	m_vec.x = 0.0f;
	m_vec.y = 0.0f;
	m_shotInterval = 0;
}

void Player::setPos(float x, float y)
{
	m_pos.x = x;
	m_pos.y = y;
}

void Player::update()
{
	// パッド(もしくはキーボード)からの入力を取得する
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	// ショットを撃つ処理
	m_shotInterval--;
	if (m_shotInterval < 0) m_shotInterval = 0;

	if ((padState & PAD_INPUT_1) && (m_shotInterval <= 0))
	{
		if (m_pMain->createShot(getPos()))
		{
			m_shotInterval = kShotInterval;
		}
	}


	if (padState & PAD_INPUT_UP)
	{
		m_vec.y -= kAcc;
		if (m_vec.y < -kSpeedMax)	m_vec.y = -kSpeedMax;
	}
	else if (padState & PAD_INPUT_DOWN)
	{
		m_vec.y += kAcc;
		if (m_vec.y > kSpeedMax)	m_vec.y = kSpeedMax;
	}
	else
	{
		m_vec.y *= 0.9f;
	}
	if (padState & PAD_INPUT_LEFT)
	{
		m_vec.x -= kAcc;
		if (m_vec.x < -kSpeedMax)	m_vec.x = -kSpeedMax;
	}
	else if (padState & PAD_INPUT_RIGHT)
	{
		m_vec.x += kAcc;
		if (m_vec.x > kSpeedMax)	m_vec.x = kSpeedMax;
	}
	else
	{
		m_vec.x *= 0.9f;
	}
	m_pos += m_vec;
}

void Player::draw()
{
	if (m_isDead)
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

	DrawGraphF(m_pos.x, m_pos.y, m_handle, true);
}