#pragma once
#pragma once
#include "Vec2.h"

class ShotBase
{
public:
	ShotBase();
	virtual ~ShotBase();

	void setHandle(int handle) { m_handle = handle; }

	// ショット開始
	virtual void start(Vec2 pos);
	// 更新
	virtual void update();
	// 表示
	virtual void draw();

	// 敵の中心座標取得
	virtual float getCenterX() { return m_pos.x + (m_height / 2); }
	virtual float getCenterY() { return m_pos.y + (m_height / 2); }

	// 当たり判定実装用に四方向の座標を取得する　
	float getLeft()	const { return m_pos.x; }
	float getRight()	const { return m_pos.x + static_cast<float>(m_width); }
	float getTop()	const { return m_pos.y; }
	float getBottom() const { return m_pos.y + static_cast<float>(m_height); }

	// 存在するか
	bool isExist() const { return m_isExist; }

protected:
	// グラフィックハンドル
	int m_handle;
	// 表示位置
	Vec2	m_pos;
	// 移動
	Vec2	m_vec;

	// 画像サイズ
	int m_height;
	int m_width;

	// 存在するか
	bool m_isExist;

	// 弾の回転
	float m_angle;
};