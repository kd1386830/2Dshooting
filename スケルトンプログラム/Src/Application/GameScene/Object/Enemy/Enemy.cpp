#include "Enemy.h"

C_Enemy::C_Enemy()
{
	m_EnemyTex.Load("Texture/enemy.png");
}

C_Enemy::~C_Enemy()
{
	m_EnemyTex.Release();
}

void C_Enemy::Init()
{
	for (int i = 0;i < EnemyNum;i++)
	{
		m_EnemyPos[i] = { -400 + (float)80 * i,250 };
	}
}

void C_Enemy::Update()
{
	for (int i = 0;i < EnemyNum;i++)
	{
		m_EnemyMat[i] = Math::Matrix::CreateTranslation(m_EnemyPos[i].x, m_EnemyPos[i].y, 0);
	}
}

void C_Enemy::Draw()
{
	for (int i = 0;i < EnemyNum;i++)
	{
		SHADER.m_spriteShader.SetMatrix(m_EnemyMat[i]);
		SHADER.m_spriteShader.DrawTex(&m_EnemyTex, Math::Rectangle(0, 0, 64, 64), 1.0f);
	}
}
