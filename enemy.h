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

	// グラフィックデータ設定
	virtual void setHandle(int handle) { m_handle = handle; }

	// プレイヤーの初期化
	virtual void init();
	
	// 処理
	virtual void update();
	// 描画
	virtual void draw();

	float getPosX() const { return m_pos.x; }
	float getPosY() const { return m_pos.y; }

	// 情報の取得
	Vec2 getPos() const { return m_pos; }

private:
	int m_handle;

	// 画像サイズ
	int m_height;
	int m_width;

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
};