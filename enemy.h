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

	// �O���t�B�b�N�f�[�^�ݒ�
	virtual void setHandle(int handle) { m_handle = handle; }

	// �v���C���[�̏�����
	virtual void init();
	
	// ����
	virtual void update();
	// �`��
	virtual void draw();

	float getPosX() const { return m_pos.x; }
	float getPosY() const { return m_pos.y; }

	// ���̎擾
	Vec2 getPos() const { return m_pos; }

private:
	int m_handle;

	// �摜�T�C�Y
	int m_height;
	int m_width;

	// �\���ʒu
	Vec2 m_pos;
	// �ړ�
	Vec2 m_vec;
	// �V���b�g�̔��ˊԊu
	int m_shotInterval;

	// ���݂��邩
	bool m_isExist;

	// �e�̉�]
	float m_angle;
};