#include "DxLib.h"
#include "SceneMain.h"
#include "game.h"

namespace
{
	// ショットの発射間隔
	constexpr int kShotInterval = 16;
}

SceneMain::SceneMain()
{
	m_hPlayerGraphic = -1;
	m_hShotGraphic = -1;
	m_hEnemyGraphic = -1;

	

	m_isGameEnd = false;
	m_isEnd = false;
}
SceneMain::~SceneMain()
{

}

// 初期化
void SceneMain::init()
{
	m_hPlayerGraphic = LoadGraph("data/kitai.jpg");
	m_hShotGraphic = LoadGraph("data/syuriken2.jpg");
	m_hEnemyGraphic = LoadGraph("data/kidan1.png");

	m_player.setHandle(m_hPlayerGraphic);
	m_enemy.setHandle(m_hEnemyGraphic);
	m_player.init();
	m_enemy.init();
	m_player.setMain(this);

	for (auto& shot : m_shot)
	{
		shot.setHandle(m_hShotGraphic);
	}

	for (auto& EnemyRight : m_EnemyRight)
	{
		EnemyRight.setHandle(m_hEnemyGraphic);
		EnemyRight.init();
	}

	m_player.setPos(Game::kScreenWidth / 2, Game::kScreenHeight / 2);
	m_player.init();

	m_isEnd = false;
}

// 終了処理
void SceneMain::end()
{
	DeleteGraph(m_hPlayerGraphic);
	DeleteGraph(m_hEnemyGraphic);
	DeleteGraph(m_hShotGraphic);
}

// 毎フレームの処理
void SceneMain::update()
{
	m_player.update();
	m_enemy.update();
	for (auto& shot : m_shot)
	{
		shot.update();
	}

	m_isEnd = false;

	for (auto& EnemyRight : m_EnemyRight)
	{
		EnemyRight.update();
	}
}

// 毎フレームの描画
void SceneMain::draw()
{
	m_player.draw();
	m_enemy.draw();

	for (auto& shot : m_shot)
	{
		shot.draw();
	}

	// 現在存在している弾の数を表示
	int shotNum = 0;
	for (auto& shot : m_shot)
	{
		if (shot.isExist()) shotNum++;
	}
	DrawFormatString(0, 0, GetColor(255, 255, 255), "弾の数:%d", shotNum);
}

bool SceneMain::createShot(Vec2 pos)
{
	for (auto& shot : m_shot)
	{
		if (shot.isExist()) continue;

		shot.start(pos);
		return true;
	}
	return false;
}

void SceneMain::createEnemyRight()
{
	for (auto& EnemyRight : m_EnemyRight)
	{
		if (EnemyRight.isExist()) continue;

		EnemyRight.start(EnemyRight.getRandPos());
		return;
	}
}