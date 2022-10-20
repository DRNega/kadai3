#include "DxLib.h"
#include "SceneMain.h"
#include "game.h"

namespace
{
	// �V���b�g�̔��ˊԊu
	constexpr int kShotInterval = 32;
	// �Q�[���̐�������
	constexpr int kGameMaxTime = 900;
	// ���S���̒x��
	constexpr int kGameOverDelay = 90;
	// �Q�[���I�[�o�[
	const char* const kGameOver = "GameOver";
	constexpr int kFontSize = 60;
}

SceneMain::SceneMain()
{
	m_hBackgroundGraphic = -1;
	m_hPlayerGraphic = -1;
	m_hPlayerDeadGraphic = -1;
	m_hShotGraphic = -1;
	m_hEnemyGraphic = -1;

	m_fontSize = 0;

	m_gameTimeRemaining = kGameMaxTime;
	m_GameOverDelay = kGameOverDelay;

	m_isGameEnd = false;
	m_isEnd = false;
}
SceneMain::~SceneMain()
{

}

// ������
void SceneMain::init()
{
	m_hBackgroundGraphic = LoadGraph(Game::kBackgroundGraph);
	m_hPlayerGraphic = LoadGraph("data/kitai2.png");
	m_hPlayerDeadGraphic = LoadGraph("data/bakuha.png");
	m_hShotGraphic = LoadGraph("data/kidan3.png");
	m_hEnemyGraphic = LoadGraph("data/kidan1.png");

	m_player.setHandle(m_hPlayerGraphic, m_hPlayerDeadGraphic);
	m_player.init();
	m_player.setMain(this);

	for (auto& shot : m_shot)
	{
		shot.setHandle(m_hShotGraphic);
	}

	for (auto& Enemy : m_Enemy)
	{
		Enemy.setHandle(m_hEnemyGraphic);
		Enemy.init();
	}

	m_player.setPos(Game::kScreenWidth / 2, Game::kScreenHeight / 2);
	m_player.init();

	// �t�H���g�T�C�Y�ݒ�
	m_fontSize = kFontSize;

	// �e���ԗp�ϐ��̏�����
	m_gameTimeRemaining = kGameMaxTime;
	m_GameOverDelay = kGameOverDelay;

	m_isEnd = false;
}

// �I������
void SceneMain::end()
{
	DeleteGraph(m_hPlayerGraphic);
	DeleteGraph(m_hEnemyGraphic);
	DeleteGraph(m_hShotGraphic);
}

// ���t���[���̏���
void SceneMain::update()
{
	// �w�i�̕\��
	DrawGraph(0, 0, m_hBackgroundGraphic, true);

	if (!m_gameTimeRemaining)	// �Q�[���c�莞�Ԃ�0�ɂȂ����ꍇ
	{
		m_isEnd = true;			// �N���A�p�̃V�[���ֈڍs����
	}
	else if (!m_GameOverDelay)	// �Q�[���I�[�o�[�x����0�ɂȂ����ꍇ
	{
		m_isEnd = true;			// �V�[���I���݂̂� true �ɂ���			
	}							// �^�C�g���֖߂�

	// �v���C���[�̍X�V����
	m_player.update();

	for (auto& shot : m_shot)
	{
		shot.update();
	}

	// �����蔻��`�F�b�N����
	checkCollision();

	// �G���쐬
	createEnemy();

	for (auto& Enemy : m_Enemy)
	{
		Enemy.update();
	}
}

// ���t���[���̕`��
void SceneMain::draw()
{
	m_player.draw();
	//m_enemy.draw();

	for (auto& shot : m_shot)
	{
		shot.draw();
	}

	// ���ݑ��݂��Ă���e�̐���\��
	int shotNum = 0;
	for (auto& shot : m_shot)
	{
		if (shot.isExist()) shotNum++;
	}
	DrawFormatString(0, 0, GetColor(255, 255, 255), "�e�̐�:%d", shotNum);

	for (auto& Enemy : m_Enemy)
	{
		if (Enemy.isExist()) Enemy.draw();
	}

	// �v���C���[�̎��S���肪 true �̏ꍇ
	if (m_player.isDead())
	{
		// 1�t���[�����ƂɃt�H���g�T�C�Y�𑝉�������
		m_fontSize++;
		SetFontSize(m_fontSize);
		// �Q�[���I�[�o�[�̃e�L�X�g��\��
		DrawString(Game::kScreenWidthHalf - GetDrawStringWidth(kGameOver, 4), 210, kGameOver, GetColor(255, 0, 0));
	}
}

// �����蔻��`�F�b�N����
void SceneMain::checkCollision()
{
	for (auto& Enemy : m_Enemy)
	{
		// �������Ă��Ȃ��ꍇ�������X�L�b�v
		if (Enemy.getRight() <= m_player.getLeft()) continue;
		if (m_player.getRight() <= Enemy.getLeft()) continue;
		if (Enemy.getBottom() <= m_player.getTop()) continue;
		if (m_player.getBottom() <= Enemy.getTop()) continue;
		// �������Ă���ꍇ�v���C���[�����S����ɂ���
		m_player.setDead();
	}

	//for (auto& Shot : m_Enemy)
	//{
	//	// �������Ă��Ȃ��ꍇ�������X�L�b�v
	//	if (Shot.getRight() <= m_player.getLeft()) continue;
	//	if (m_player.getRight() <= Shot.getLeft()) continue;
	//	if (Shot.getBottom() <= m_player.getTop()) continue;
	//	if (m_player.getBottom() <= Shot.getTop()) continue;
	//	// �������Ă���ꍇ�v���C���[�����S����ɂ���
	//	m_playe.setDead();
	//}
}

bool SceneMain::createShot(Vec2 pos)
{
	for (auto& shot : m_shot)
	{
		if (shot.isExist()) continue;

		shot.start(pos);
		return true;
	}
	return false;
}

void SceneMain::createEnemy()
{
	for (auto& Enemy : m_Enemy)
	{
		if (Enemy.isExist()) continue;

		Enemy.start(Enemy.getRandPos());
		return;
	}
}