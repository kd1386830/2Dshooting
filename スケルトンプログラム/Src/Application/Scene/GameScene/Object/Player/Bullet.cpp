#include "Bullet.h"
#include"Player.h"
#include"../Enemy/Enemy.h"

#include"../../System/Hit.h"
#include"../../GameScene.h"

void Bullet::Init()
{
	m_Tex.Load("Texture/bullet.png");

	for (int i = 0;i < BulletNum;i++)
	{
		m_AliveFlg[i] = false;
	}

}

void Bullet::Update()
{
	ShotWait += 1;
	if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
	{
		if (ShotWait >= 15)
		{
			Shot();
		}
	}

	for (int i = 0;i < BulletNum;i++)
	{
		if(m_AliveFlg[i])
		{
			m_Pos[i] += m_Move[i];
		}
		
		if (m_OwnerScene)
		{
			for (auto& obj : m_OwnerScene->GetObjList())
			{
				Enemy* enemy = dynamic_cast<Enemy*>(obj.get());
				if (enemy)
				{
					if (enemy->GetAliveFlg())
					{
						if (Hit::Instance().ObjectHit(m_Pos[i], enemy->GetPos(), 16, 64))
						{
							m_AliveFlg[i] = false;
							enemy->SetAliveFlg(false);
						}
					}
				}
			}
		}

		

		m_Mat[i] = Math::Matrix::CreateTranslation(m_Pos[i].x, m_Pos[i].y, 0);
	}
}

void Bullet::Draw()
{
	for (int i = 0;i < BulletNum;i++)
	{
		if (m_AliveFlg[i])
		{
			SHADER.m_spriteShader.SetMatrix(m_Mat[i]);
			SHADER.m_spriteShader.DrawTex(&m_Tex, Math::Rectangle(0, 0, 16, 16), 1.0f);
		}
	}
}

void Bullet::Shot()
{
	for (int i = 0;i < BulletNum;i++)
	{
		if (!m_AliveFlg[i])
		{
			if (!m_player)return;

			m_Pos[i] = m_player->GetPlayerPos();

			m_Move[i].x = cos(m_player->GetAngle()) * m_BulletSpd;
			m_Move[i].y = sin(m_player->GetAngle()) * m_BulletSpd;

			m_AliveFlg[i] = true;
			ShotWait = 0;

			m_Mat[i] = Math::Matrix::CreateTranslation(m_Pos[i].x, m_Pos[i].y, 0);
			break;
		}
	}
}

void Bullet::Release()
{
	m_Tex.Release();
}
