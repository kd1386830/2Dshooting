#include "Bullet.h"
#include"../Player/Player.h"
#include"../Enemy/Enemy.h"

#include"../../System/Hit.h"
#include"../../GameScene.h"

void Bullet::Init()
{
	m_Tex.Load("Texture/bullet.png");

	m_AliveFlg = true;
	m_Radius = 8.0f;

	m_ObjType = ObjectType::Bullet;

}

void Bullet::Update()
{
	m_Pos += m_Move;

	if (m_Pos.x<SCR_L - m_Radius || m_Pos.x > SCR_R + m_Radius || m_Pos.y < SCR_B - m_Radius || m_Pos.y > SCR_T + m_Radius)
	{
		m_AliveFlg = false;
	}

	if (Hit::Instance().EnemyToHit(m_Pos, m_Radius))
	{
		OnHit();
	}

	m_Mat = Math::Matrix::CreateTranslation(m_Pos.x, m_Pos.y, 0);
}

void Bullet::Draw()
{
	SHADER.m_spriteShader.SetMatrix(m_Mat);
	SHADER.m_spriteShader.DrawTex(&m_Tex, Math::Rectangle(0, 0, 16, 16), 1.0f);
}

void Bullet::OnHit()
{
	m_AliveFlg = false;
}

void Bullet::Shot(Player* player)
{
	m_Pos = player->GetPos();

	m_Move.x = cos(player->GetAngle()) * m_BulletSpd;
	m_Move.y = sin(player->GetAngle()) * m_BulletSpd;

	m_AliveFlg = true;

	m_Mat = Math::Matrix::CreateTranslation(m_Pos.x, m_Pos.y, 0);
}

void Bullet::Release()
{
	m_Tex.Release();
}
