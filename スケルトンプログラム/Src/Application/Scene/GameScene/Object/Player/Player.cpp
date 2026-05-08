#include "Player.h"
#include"../Bullet/Bullet.h"

#include"../../GameScene.h"
#include"../../../../System/Mouse.h"
#include"../../System/Hit.h"

void Player::Init()
{
	m_Tex.Load("Texture/Object/player.png");

	m_Pos = { 0,0 };
	m_AliveFlg = true;
	m_Radius = 32.0f;
	m_Scale = 4;

	m_ObjType = ObjectType::Player;
}

void Player::Update()
{
	PlayerMove();
	PlayerRotation();

	m_ShotWait++;

	if (m_ShotWait > m_shotWaitTime)
	{
		if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
		{
			std::shared_ptr<Bullet>bullet;
			bullet = std::make_shared<Bullet>();
			bullet->Init();
			bullet->SetOwner(m_Owner);
			bullet->Shot(this);
			m_Owner->AddObject(bullet);

			m_ShotWait = 0;
		}
	}
	
	for (auto& obj : m_Owner->GetObjList())
	{
		if (obj->GetObjType() == ObjectType::Enemy)
		{
			if (Hit::Instance().ObjectHit(this, obj.get()))
			{
				if(obj->GetAliveFlg())
				{
					obj->OnHit();
					OnHit();
				}
			}
		}
		if (obj->GetObjType() == ObjectType::Item)
		{
			if (Hit::Instance().ObjectHit(this, obj.get()))
			{
				if (obj->GetAliveFlg())
				{
					obj->OnHit();
					ItemHit();
				}
			}
		}
	}

	if (m_ActiveItemFlg)
	{
		m_ActiveItemTime--;
		if (m_ActiveItemTime <= 0)
		{
			DefStatu();
		}
	}

	m_TransMat = Math::Matrix::CreateTranslation(m_Pos.x, m_Pos.y, 0);
	m_ScaleMat = Math::Matrix::CreateScale(m_Scale, m_Scale, 0);
	m_RotateMat = Math::Matrix::CreateRotationZ(m_Angle - DirectX::XM_PIDIV2);
	m_Mat = m_RotateMat * m_ScaleMat * m_TransMat;
}

void Player::Draw()
{
	SHADER.m_spriteShader.SetMatrix(m_Mat);
	SHADER.m_spriteShader.DrawTex(&m_Tex, Math::Rectangle(0, 0, 16, 16), 1.0f);
}

void Player::OnHit()
{
	m_AliveFlg = false;
	SceneManager::Instance().ChangeFade(SceneManager::SceneType::Result);
}

void Player::ItemHit()
{
	m_shotWaitTime = 8;
	m_ActiveItemFlg = true;
}

void Player::PlayerMove()
{
	m_MoveVec = { 0,0 };
	if (GetAsyncKeyState('W') & 0x8000 || GetAsyncKeyState(VK_UP) & 0x8000)		m_MoveVec.y = 1.0f;
	if (GetAsyncKeyState('A') & 0x8000 || GetAsyncKeyState(VK_LEFT) & 0x8000)	m_MoveVec.x = -1.0f;
	if (GetAsyncKeyState('S') & 0x8000 || GetAsyncKeyState(VK_DOWN) & 0x8000)	m_MoveVec.y = -1.0f;
	if (GetAsyncKeyState('D') & 0x8000 || GetAsyncKeyState(VK_RIGHT) & 0x8000)	m_MoveVec.x = 1.0f;
	m_MoveVec.Normalize();
	m_Pos += m_MoveVec * m_MoveSpd;
}

void Player::PlayerRotation()
{
	float dx = Mouse::Instance().GetMousePos().x - m_Pos.x;
	float dy = Mouse::Instance().GetMousePos().y - m_Pos.y;

	m_Angle = atan2(dy, dx);
}

void Player::DefStatu()
{
	m_shotWaitTime = 15;
	m_ActiveItemFlg = false;
	m_ActiveItemTime = 5 * 60;
}

void Player::Release()
{
	m_Tex.Release();
}
