#include "PlayerBullet.h"
#include"Player.h"

C_PlayerBullet::C_PlayerBullet()
{
	m_PBulletTex.Load("Texture/bullet.png");
}

C_PlayerBullet::~C_PlayerBullet()
{
	m_PBulletTex.Release();
}

void C_PlayerBullet::Init()
{
	for (int i = 0;i < BulletNum;i++)
	{
		m_PBulletPos[i] = { 0,0 };
		m_PBulletFlg[i] = false;
	}
	m_PBulletSpeed = 10;
	m_PBulletWait = 0;
}

void C_PlayerBullet::Update()
{
	m_PBulletWait ++;

	if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
	{
		if (m_PBulletWait > 15)
		{
		shot();
		}
	}

	for (int i = 0;i < BulletNum;i++)
	{
		if (m_PBulletFlg[i])
		{
			m_PBulletPos[i].x += m_PBulletMoveX[i];
			m_PBulletPos[i].y += m_PBulletMoveY[i];

			if (m_PBulletPos[i].x < SCREEN_LEFT - 16 || m_PBulletPos[i].x > SCREEN_RIGHT + 16 || m_PBulletPos[i].y < SCREEN_BOTTOM - 16 || m_PBulletPos[i].y > SCREEN_TOP + 16)
			{
				m_PBulletFlg[i] = false;
			}
		}
	}

	for (int i = 0;i < BulletNum;i++)
	{
		m_PBulletMat[i] = Math::Matrix::CreateTranslation(m_PBulletPos[i].x, m_PBulletPos[i].y, 0);
	}
}

void C_PlayerBullet::Draw()
{
	for (int i = 0;i < BulletNum;i++)
	{
		if (m_PBulletFlg[i])
		{
			SHADER.m_spriteShader.SetMatrix(m_PBulletMat[i]);
			SHADER.m_spriteShader.DrawTex(&m_PBulletTex, Math::Rectangle(0, 0, 16, 16), 1.0f);
		}
	}
}

void C_PlayerBullet::shot()
{
	for (int i = 0;i < BulletNum;i++)
	{
		if (!m_PBulletFlg[i])
		{
			m_PBulletPos[i] = C_Player::GetInstance().GetPlayerPos();

			m_PBulletMoveX[i] = cos(C_Player::GetInstance().GetAngle()) * m_PBulletSpeed;
			m_PBulletMoveY[i] = sin(C_Player::GetInstance().GetAngle()) * m_PBulletSpeed;

			m_PBulletFlg[i] = true;
			m_PBulletWait = 0;

			m_PBulletMat[i] = Math::Matrix::CreateTranslation(m_PBulletPos[i].x, m_PBulletPos[i].y, 0);

			break;
		}
	}
}
