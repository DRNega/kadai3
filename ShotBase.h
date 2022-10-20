#pragma once
#pragma once
#include "Vec2.h"

class ShotBase
{
public:
	ShotBase();
	virtual ~ShotBase();

	void setHandle(int handle) { m_handle = handle; }

	// �V���b�g�J�n
	virtual void start(Vec2 pos);
	// �X�V
	virtual void update();
	// �\��
	virtual void draw();

	// �G�̒��S���W�擾
	virtual float getCenterX() { return m_pos.x + (m_height / 2); }
	virtual float getCenterY() { return m_pos.y + (m_height / 2); }

	// �����蔻������p�Ɏl�����̍��W���擾����@
	float getLeft()	const { return m_pos.x; }
	float getRight()	const { return m_pos.x + static_cast<float>(m_width); }
	float getTop()	const { return m_pos.y; }
	float getBottom() const { return m_pos.y + static_cast<float>(m_height); }

	// ���݂��邩
	bool isExist() const { return m_isExist; }

protected:
	// �O���t�B�b�N�n���h��
	int m_handle;
	// �\���ʒu
	Vec2	m_pos;
	// �ړ�
	Vec2	m_vec;

	// �摜�T�C�Y
	int m_height;
	int m_width;

	// ���݂��邩
	bool m_isExist;

	// �e�̉�]
	float m_angle;
};