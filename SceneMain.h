#pragma once

#include "player.h"
#include "enemy.h"
#include "ShotNormal.h"

class SceneMain
{
public:
	SceneMain();
	virtual ~SceneMain();

	// 初期化
	void init();
	// 終了処理
	void end();

	// 毎フレームの処理
	void update();
	// 毎フレームの描画
	void draw();
	// 当たり判定チェック処理
	void checkCollision();

	// 弾の生成
	bool createShot(Vec2 pos);

	// 敵の生成
	void createEnemy();

	virtual bool isGameEnd() { return m_isGameEnd; }
	virtual bool isEnd() { return m_isEnd; }

private:
	// ショットの最大数
	static constexpr int kShotMax = 64;
	static constexpr int kMobMax = 5;
	// 敵の最大出現数
	static constexpr int kEnemyMax = 5;

private:
	// 背景のグラフィックハンドル
	int m_hBackgroundGraphic;

	// プレイヤーのグラフィックハンドル
	int m_hPlayerGraphic;
	int m_hPlayerDeadGraphic;

	// 弾のグラフィックハンドル
	int m_hShotGraphic;
	
	// 敵のグラフィックハンドル
	int m_hEnemyGraphic;

	// フォントサイズ
	int m_fontSize;

	// ゲームの制限時間
	int m_gameTimeRemaining;
	// ゲームオーバー時の遅延時間
	int m_GameOverDelay;
	
	// プレイヤー
	Player m_player;
	
	// 敵
	Enemy m_Enemy[kMobMax];
	//Enemy m_EnemyRight[kMobMax];
	
	// ショット
	ShotNormal m_shot[kShotMax];

	// ゲーム終了
	bool m_isGameEnd;
	bool m_isEnd;
};