#pragma once

#include "Vec2.h"

class SceneMain;

class Player
{
public:
	Player();
	virtual ~Player();

	virtual void setPos(float x, float y);

	// グラフィックデータ設定
	virtual void setHandle(int handle) { m_handle = handle; }

	// プレイヤーの初期化
	virtual void init();
	// SceneMainクラスのポインタ設定
	virtual void setMain(SceneMain* pMain) { m_pMain = pMain; }

	// 処理
	virtual void update();
	// 描画
	virtual void draw();

	float getPosX() const { return m_pos.x; }
	float getPosY() const { return m_pos.y; }

	virtual void isDead() { m_isDead = true; }
	virtual bool getIsDead() { return m_isDead; }

	// 当たり判定実装用に四方向の座標を取得する　
	float getLeft()	const { return m_pos.x; }
	float getRight()	const { return m_pos.x + static_cast<float>(m_width); }
	float getTop()	const { return m_pos.y; }
	float getBottom() const { return m_pos.y + static_cast<float>(m_height); }

	// 情報の取得
	Vec2 getPos() const { return m_pos; }

private:
	int m_handle;

	// SceneMainのポインタ
	SceneMain* m_pMain;

	// 表示位置
	Vec2 m_pos;
	// 移動
	Vec2 m_vec;
	// 中心位置
	Vec2 m_midPos;

	// ショットの発射間隔
	int m_shotInterval;

	// 画像データ
	int m_aliveHandle;
	int m_deadHandle;

	// 画像サイズ
	int m_height;
	int m_width;

	// 死亡判定
	bool m_isDead;
};