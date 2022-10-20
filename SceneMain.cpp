#include "DxLib.h"
#include "SceneMain.h"
#include "game.h"

namespace
{
	// ショットの発射間隔
	constexpr int kShotInterval = 32;
	// ゲームの制限時間
	constexpr int kGameMaxTime = 900;
	// 死亡時の遅延
	constexpr int kGameOverDelay = 90;
	// ゲームオーバー
	const char* const kGameOver = "GameOver";
	constexpr int kFontSize = 60;
}

SceneMain::SceneMain()
{
	m_hBackgroundGraphic = -1;
	m_hPlayerGraphic = -1;
	m_hPlayerDeadGraphic = -1;
	m_hShotGraphic = -1;
	m_hEnemyGraphic = -1;

	m_fontSize = 0;

	m_gameTimeRemaining = kGameMaxTime;
	m_GameOverDelay = kGameOverDelay;

	m_isGameEnd = false;
	m_isEnd = false;
}
SceneMain::~SceneMain()
{

}

// 初期化
void SceneMain::init()
{
	m_hBackgroundGraphic = LoadGraph(Game::kBackgroundGraph);
	m_hPlayerGraphic = LoadGraph("data/kitai2.png");
	m_hPlayerDeadGraphic = LoadGraph("data/bakuha.png");
	m_hShotGraphic = LoadGraph("data/kidan3.png");
	m_hEnemyGraphic = LoadGraph("data/kidan1.png");

	m_player.setHandle(m_hPlayerGraphic, m_hPlayerDeadGraphic);
	m_player.init();
	m_player.setMain(this);

	for (auto& shot : m_shot)
	{
		shot.setHandle(m_hShotGraphic);
	}

	for (auto& Enemy : m_Enemy)
	{
		Enemy.setHandle(m_hEnemyGraphic);
		Enemy.init();
	}

	m_player.setPos(Game::kScreenWidth / 2, Game::kScreenHeight / 2);
	m_player.init();

	// フォントサイズ設定
	m_fontSize = kFontSize;

	// 各時間用変数の初期化
	m_gameTimeRemaining = kGameMaxTime;
	m_GameOverDelay = kGameOverDelay;

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
	// 背景の表示
	DrawGraph(0, 0, m_hBackgroundGraphic, true);

	if (!m_gameTimeRemaining)	// ゲーム残り時間が0になった場合
	{
		m_isEnd = true;			// クリア用のシーンへ移行する
	}
	else if (!m_GameOverDelay)	// ゲームオーバー遅延が0になった場合
	{
		m_isEnd = true;			// シーン終了のみを true にする			
	}							// タイトルへ戻る

	// プレイヤーの更新処理
	m_player.update();

	for (auto& shot : m_shot)
	{
		shot.update();
	}

	// 当たり判定チェック処理
	checkCollision();

	// 敵を作成
	createEnemy();

	for (auto& Enemy : m_Enemy)
	{
		Enemy.update();
	}
}

// 毎フレームの描画
void SceneMain::draw()
{
	m_player.draw();
	//m_enemy.draw();

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

	for (auto& Enemy : m_Enemy)
	{
		if (Enemy.isExist()) Enemy.draw();
	}

	// プレイヤーの死亡判定が true の場合
	if (m_player.isDead())
	{
		// 1フレームごとにフォントサイズを増加させる
		m_fontSize++;
		SetFontSize(m_fontSize);
		// ゲームオーバーのテキストを表示
		DrawString(Game::kScreenWidthHalf - GetDrawStringWidth(kGameOver, 4), 210, kGameOver, GetColor(255, 0, 0));
	}
}

// 当たり判定チェック処理
void SceneMain::checkCollision()
{
	for (auto& Enemy : m_Enemy)
	{
		// 当たっていない場合処理をスキップ
		if (Enemy.getRight() <= m_player.getLeft()) continue;
		if (m_player.getRight() <= Enemy.getLeft()) continue;
		if (Enemy.getBottom() <= m_player.getTop()) continue;
		if (m_player.getBottom() <= Enemy.getTop()) continue;
		// 当たっている場合プレイヤーを死亡判定にする
		m_player.setDead();
	}

	//for (auto& Shot : m_Enemy)
	//{
	//	// 当たっていない場合処理をスキップ
	//	if (Shot.getRight() <= m_player.getLeft()) continue;
	//	if (m_player.getRight() <= Shot.getLeft()) continue;
	//	if (Shot.getBottom() <= m_player.getTop()) continue;
	//	if (m_player.getBottom() <= Shot.getTop()) continue;
	//	// 当たっている場合プレイヤーを死亡判定にする
	//	m_playe.setDead();
	//}
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

void SceneMain::createEnemy()
{
	for (auto& Enemy : m_Enemy)
	{
		if (Enemy.isExist()) continue;

		Enemy.start(Enemy.getRandPos());
		return;
	}
}