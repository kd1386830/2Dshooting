#include "Enemy.h"
#include"../Player/Player.h"

void Enemy::Init()
{
	m_Tex.Load("Texture/enemy.png");

	EnemySpawn();
	
	m_AliveFlg = true;
}

void Enemy::Update()
{
	ChasePlayer();
	m_Pos += m_EnemyVec;

	m_Mat = Math::Matrix::CreateTranslation(m_Pos.x, m_Pos.y, 0);
}

void Enemy::Draw()
{
	SHADER.m_spriteShader.SetMatrix(m_Mat);
	SHADER.m_spriteShader.DrawTex(&m_Tex, Math::Rectangle(0, 0, 64, 64), 1.0f);
}

void Enemy::EnemySpawn()
{
	const float offSet = 50.0f;	//画面外に出す距離
	switch (rand() % 4)
	{
	case 0:	//上
		m_Pos.x = (rand() % 1280) - 640;
		m_Pos.y = 360 + offSet;
		break;
	case 1:	//下
		m_Pos.x = (rand() % 1280) - 640;
		m_Pos.y = -360 - offSet;
		break;
	case 2:	//左
		m_Pos.x = -640 - offSet;
		m_Pos.y = (rand() % 720) - 360;
		break;
	case 3:	//右
		m_Pos.x = 640 + offSet;
		m_Pos.y = (rand() % 720) - 360;
		break;
	}
}

void Enemy::ChasePlayer()
{
	if (!m_player) return;

	Math::Vector2 playerPos = m_player->GetPlayerPos();

	Math::Vector2 dir = playerPos - m_Pos;

	if (dir.Length() > 0)
	{
		dir.Normalize();
	}

	m_EnemyVec = m_EnemyVec * 0.9f + dir * m_EnemySpd * 0.1f;
}

void Enemy::Release()
{
	m_Tex.Release();
}
