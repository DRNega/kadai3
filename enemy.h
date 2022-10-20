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

	

	// �v���C���[�̏�����
	virtual void init();
	// �摜�̃Z�b�g
	virtual void setHandle(int handle);
	
	// �X�V����
	virtual void update();
	// �`�揈��
	virtual void draw();

	float getPosX() const { return m_pos.x; }
	float getPosY() const { return m_pos.y; }

	// ���̎擾
	Vec2 getPos() const { return m_pos; }

	// �G�̒��S���W�擾
	virtual float getCenterX() { return m_pos.x + (m_height / 2); }
	virtual float getCenterY() { return m_pos.y + (m_height / 2); }

	// �����蔻������p�Ɏl�����̍��W���擾����@
	float getLeft()	const { return m_pos.x; }
	float getRight()	const { return m_pos.x + static_cast<float>(m_width); }
	float getTop()	const { return m_pos.y; }
	float getBottom() const { return m_pos.y + static_cast<float>(m_height); }

	//���݂��邩
	bool isExist()const { return m_isExist; }

private:
	int m_handle;

	// �摜�T�C�Y
	int m_height;
	int m_width;

	// �摜�f�[�^
	int m_aliveHandle;
	int m_deadHandle;

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

	// ���S����
	bool m_isDead;
};