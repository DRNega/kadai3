#pragma once

#include "Vec2.h"

class SceneMain;

class Player
{
public:
	Player();
	virtual ~Player();

	virtual void setPos(float x, float y);

	// �O���t�B�b�N�f�[�^�ݒ�
	virtual void setHandle(int handle) { m_handle = handle; }

	// �v���C���[�̏�����
	virtual void init();
	// SceneMain�N���X�̃|�C���^�ݒ�
	virtual void setMain(SceneMain* pMain) { m_pMain = pMain; }

	// ����
	virtual void update();
	// �`��
	virtual void draw();

	float getPosX() const { return m_pos.x; }
	float getPosY() const { return m_pos.y; }

	virtual void isDead() { m_isDead = true; }
	virtual bool getIsDead() { return m_isDead; }

	// �����蔻������p�Ɏl�����̍��W���擾����@
	float getLeft()	const { return m_pos.x; }
	float getRight()	const { return m_pos.x + static_cast<float>(m_width); }
	float getTop()	const { return m_pos.y; }
	float getBottom() const { return m_pos.y + static_cast<float>(m_height); }

	// ���̎擾
	Vec2 getPos() const { return m_pos; }

private:
	int m_handle;

	// SceneMain�̃|�C���^
	SceneMain* m_pMain;

	// �\���ʒu
	Vec2 m_pos;
	// �ړ�
	Vec2 m_vec;
	// ���S�ʒu
	Vec2 m_midPos;

	// �V���b�g�̔��ˊԊu
	int m_shotInterval;

	// �摜�f�[�^
	int m_aliveHandle;
	int m_deadHandle;

	// �摜�T�C�Y
	int m_height;
	int m_width;

	// ���S����
	bool m_isDead;
};