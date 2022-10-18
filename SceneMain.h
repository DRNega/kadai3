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

	// 弾の生成
	bool createShot(Vec2 pos);

	// 敵の生成
	void createEnemyRight();

	virtual bool isGameEnd() { return m_isGameEnd; }
	virtual bool isEnd() { return m_isEnd; }

private:
	// ショットの最大数
	static constexpr int kShotMax = 64;
	static constexpr int kMobMax = 5;

private:

	// プレイヤーのグラフィックハンドル
	int m_hPlayerGraphic;

	// 弾のグラフィックハンドル
	int m_hShotGraphic;
	
	// 敵のグラフィックハンドル
	int m_hEnemyGraphic;
	
	// プレイヤー
	Player m_player;
	
	// 敵
	Enemy m_enemy;
	Enemy m_EnemyRight[kMobMax];
	
	// ショット
	ShotNormal m_shot[kShotMax];

	// ゲーム終了
	bool m_isGameEnd;
	bool m_isEnd;
};