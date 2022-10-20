#pragma once

#include "Vec2.h"

class SceneMain;

class Enemy
{
public:
	Enemy();
	virtual ~Enemy();
	virtual Vec2 getRandPos();
	virtual void start(Vec2 pos);

	

	// プレイヤーの初期化
	virtual void init();
	// 画像のセット
	virtual void setHandle(int handle);
	
	// 更新処理
	virtual void update();
	// 描画処理
	virtual void draw();

	float getPosX() const { return m_pos.x; }
	float getPosY() const { return m_pos.y; }

	// 情報の取得
	Vec2 getPos() const { return m_pos; }

	// 敵の中心座標取得
	virtual float getCenterX() { return m_pos.x + (m_height / 2); }
	virtual float getCenterY() { return m_pos.y + (m_height / 2); }

	// 当たり判定実装用に四方向の座標を取得する　
	float getLeft()	const { return m_pos.x; }
	float getRight()	const { return m_pos.x + static_cast<float>(m_width); }
	float getTop()	const { return m_pos.y; }
	float getBottom() const { return m_pos.y + static_cast<float>(m_height); }

	//存在するか
	bool isExist()const { return m_isExist; }

private:
	int m_handle;

	// 画像サイズ
	int m_height;
	int m_width;

	// 画像データ
	int m_aliveHandle;
	int m_deadHandle;

	// 表示位置
	Vec2 m_pos;
	// 移動
	Vec2 m_vec;
	// ショットの発射間隔
	int m_shotInterval;

	// 存在するか
	bool m_isExist;

	// 弾の回転
	float m_angle;

	// 死亡判定
	bool m_isDead;
};