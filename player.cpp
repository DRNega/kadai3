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
	m_aliveHandle = -1;
	m_deadHandle = -1;

	m_pMain = nullptr;

	m_shotInterval = 0;
	
	m_width = 0;
	m_height = 0;

	m_isDead = false;
}

Player::~Player()
{

}

void Player::init()
{
	m_pos.x = 100.0f;
	m_pos.y = 100.0f;
	m_vec.x = 0.0f;
	m_vec.y = 0.0f;
	m_shotInterval = 0;

	m_isDead = false;
}

// プレイヤーの画像セット
void Player::setHandle(int playerHandle, int playerDeadHandle)
{
	m_aliveHandle = playerHandle;
	m_deadHandle = playerDeadHandle;

	// 画像サイズの取得
	GetGraphSize(m_aliveHandle, &m_width, &m_height);
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

	// 画面端に行こうとした場合
	if (getLeft() < 0)
	{
		m_pos.x = 0.0f;    // 画面端より左には行かない
	}
	if (getRight() > Game::kScreenWidth)
	{
		m_pos.x = static_cast<float>(Game::kScreenWidth - m_width); // 画面端より右には行かない
	}
	// ステージの範囲外に行こうとした場合
	if (getTop() < Game::kStageUpperLimit)
	{
		m_pos.y = Game::kStageUpperLimit;   // ステージの範囲より上には行かない
		
	}
	if (getBottom() > Game::kStageLowerLimit)
	{
		m_pos.y = static_cast<float>(Game::kStageLowerLimit - m_height);    // ステージの範囲より下には行かない
		
	}
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

	//DrawTriangle(getLeft(), getTop(), getLeft(), getBottom(), getRight(),getTop() + 43, GetColor(255, 255, 255), false);
}