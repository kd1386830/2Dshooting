#include "Enemy.h"
#include"../Player/Player.h"
#include"../Effect/Explosion.h"

#include"../../GameScene.h"

void Enemy::Init()
{
	m_Tex.Load("Texture/Object/enemy.png");

	EnemySpawn();
	m_Mat = Math::Matrix::CreateTranslation(m_Pos.x, m_Pos.y, 0);

	m_AliveFlg = true;
	m_Radius = 32.0f;

	m_ObjType = ObjectType::Enemy;
}

void Enemy::Update()
{
	ChasePlayer();

	if (m_AnimWait <= 0)
	{
		m_AnimCnt += 0.2f;
		if (m_AnimCnt >= 6)
		{
			m_AnimCnt = 0;
			m_AnimWait = rand() % 2 * 60.0f;
		}
	}
	else
	{
		m_AnimWait --;
	}
	

	m_TransMat = Math::Matrix::CreateTranslation(m_Pos.x, m_Pos.y, 0);
	m_ScaleMat = Math::Matrix::CreateScale(m_Scale, m_Scale, 0);
	m_Mat = m_ScaleMat * m_TransMat;
}

void Enemy::Draw()
{
	SHADER.m_spriteShader.SetMatrix(m_Mat);
	SHADER.m_spriteShader.DrawTex(&m_Tex, Math::Rectangle(16 * (int)m_AnimCnt, 0, 16, 16), 1.0f);
}

void Enemy::OnHit()
{
	auto effect = std::make_shared<Explosion>();
	effect->Init(m_Pos);
	m_Owner->AddObject(effect);

	m_AliveFlg = false;
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
	for (auto& obj : m_Owner->GetObjList())
	{
		if (obj->GetObjType() == ObjectType::Player)
		{
			Math::Vector2 playerPos = obj->GetPos();

			Math::Vector2 dir = playerPos - m_Pos;

			if (dir.Length() > 0)
			{
				dir.Normalize();
			}

			m_EnemyVec = m_EnemyVec * 0.9f + dir * m_EnemySpd * 0.1f;
			//m_EnemyVec = dir * m_EnemySpd;
		}
	}

	m_Pos += m_EnemyVec;
}

void Enemy::Release()
{
	m_Tex.Release();
}
