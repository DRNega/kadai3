#pragma once

#include "player.h"
#include "enemy.h"
#include "ShotNormal.h"

class SceneMain
{
public:
	SceneMain();
	virtual ~SceneMain();

	// ������
	void init();
	// �I������
	void end();

	// ���t���[���̏���
	void update();
	// ���t���[���̕`��
	void draw();
	// �����蔻��`�F�b�N����
	void checkCollision();

	// �e�̐���
	bool createShot(Vec2 pos);

	// �G�̐���
	void createEnemy();

	virtual bool isGameEnd() { return m_isGameEnd; }
	virtual bool isEnd() { return m_isEnd; }

private:
	// �V���b�g�̍ő吔
	static constexpr int kShotMax = 64;
	static constexpr int kMobMax = 5;
	// �G�̍ő�o����
	static constexpr int kEnemyMax = 5;

private:
	// �w�i�̃O���t�B�b�N�n���h��
	int m_hBackgroundGraphic;

	// �v���C���[�̃O���t�B�b�N�n���h��
	int m_hPlayerGraphic;
	int m_hPlayerDeadGraphic;

	// �e�̃O���t�B�b�N�n���h��
	int m_hShotGraphic;
	
	// �G�̃O���t�B�b�N�n���h��
	int m_hEnemyGraphic;

	// �t�H���g�T�C�Y
	int m_fontSize;

	// �Q�[���̐�������
	int m_gameTimeRemaining;
	// �Q�[���I�[�o�[���̒x������
	int m_GameOverDelay;
	
	// �v���C���[
	Player m_player;
	
	// �G
	Enemy m_Enemy[kMobMax];
	//Enemy m_EnemyRight[kMobMax];
	
	// �V���b�g
	ShotNormal m_shot[kShotMax];

	// �Q�[���I��
	bool m_isGameEnd;
	bool m_isEnd;
};