#include "Enemy.h"

void Enemy::Init()
{
	m_Tex.Load("Texture/enemy.png");
	m_Pos = { 0,0 };
	m_AliveFlg = true;
}

void Enemy::Update()
{

	m_Mat = Math::Matrix::CreateTranslation(m_Pos.x, m_Pos.y, 0);
}

void Enemy::Draw()
{
	SHADER.m_spriteShader.SetMatrix(m_Mat);
	SHADER.m_spriteShader.DrawTex(&m_Tex, Math::Rectangle(0, 0, 64, 64), 1.0f);
}

void Enemy::Release()
{
	m_Tex.Release();
}
