#include "Item.h"
#include"../../GameScene.h"
#include"../Player/Player.h"

void Item::Init()
{
	ItemTypeSet();

	
	m_Tex.Load("Texture/Object/Item.png");

	ItemSpawn();
	m_TransMat = Math::Matrix::CreateTranslation(m_Pos.x, m_Pos.y, 0);
	m_ScaleMat = Math::Matrix::CreateScale(m_Scale, m_Scale, 0);
	m_Mat = m_ScaleMat * m_TransMat;

	m_Radius = 24.0f;

	m_AliveFlg = true;

	m_ObjType = ObjectType::Item;
}

void Item::Update()
{
	Move();
	ScrOutCheck();

	m_TransMat = Math::Matrix::CreateTranslation(m_Pos.x, m_Pos.y, 0);
	m_ScaleMat = Math::Matrix::CreateScale(m_Scale, m_Scale, 0);
	m_Mat = m_ScaleMat * m_TransMat;
}

void Item::Draw()
{
	SHADER.m_spriteShader.SetMatrix(m_Mat);
	switch (m_Type)
	{
	case Item::ItemType::spdUp:
		SHADER.m_spriteShader.DrawTex(&m_Tex, Math::Rectangle(16, 0, 16, 16), 1.0f);
		break;
	case Item::ItemType::ShotSpdUp:
		SHADER.m_spriteShader.DrawTex(&m_Tex, Math::Rectangle(0, 0, 16, 16), 1.0f);
		break;
	}
}

void Item::Release()
{
	m_Tex.Release();
}

void Item::OnHit()
{
	for (auto& obj : m_Owner->GetObjList())
	{
		if (obj->GetObjType() == ObjectType::Player)
		{
			Player* player = dynamic_cast<Player*>(obj.get());

			if (player)
			{
				switch (m_Type)
				{
				case Item::ItemType::spdUp:
					player->SetSpeed(8.0f);
					break;
				case Item::ItemType::ShotSpdUp:
					player->SetShotWaitTime(8);
					break;
				}
			}
		}
	}

	m_AliveFlg = false;
}

void Item::Move()
{
	for (auto& obj : m_Owner->GetObjList())
	{
		if (obj->GetObjType() == ObjectType::Player)
		{
			if (obj->GetAliveFlg())
			{
				Math::Vector2 dir = m_TargetPos - m_Pos;
				dir.Normalize();

				m_vec = dir * m_Speed;
			}
		}
	}
	m_Pos += m_vec;
}

void Item::ItemSpawn()
{
	switch (rand() % 4)
	{
	case 0:	//上
		m_Pos.x = (rand() % 1280) - 640;
		m_Pos.y = 360 + offSet;

		m_TargetPos.x = (rand() % 1280) - 640;
		m_TargetPos.y = -360 - offSet;
		break;
	case 1:	//下
		m_Pos.x = (rand() % 1280) - 640;
		m_Pos.y = -360 - offSet;

		m_TargetPos.x = (rand() % 1280) - 640;
		m_TargetPos.y = 360 + offSet;
		break;
	case 2:	//左
		m_Pos.x = -640 - offSet;
		m_Pos.y = (rand() % 720) - 360;

		m_TargetPos.x = 640 + offSet;
		m_TargetPos.y = (rand() % 720) - 360;
		break;
	case 3:	//右
		m_Pos.x = 640 + offSet;
		m_Pos.y = (rand() % 720) - 360;

		m_TargetPos.x = -640 - offSet;
		m_TargetPos.y = (rand() % 720) - 360;
		break;
	}
}

void Item::ScrOutCheck()
{
	if (m_Pos.x < -640 - offSet || m_Pos.x > 640 + offSet || m_Pos.y < -360 - offSet || m_Pos.y > 360 + offSet)
	{
		m_AliveFlg = false;
	}
}

void Item::ItemTypeSet()
{
	switch (rand() % 2)
	{
	case 0:
		m_Type = ItemType::spdUp;
		break;
	case 1:
		m_Type = ItemType::ShotSpdUp;
		break;
	}
}

Math::Color Item::GetEffectColor()
{
	switch (m_Type)
	{
	case Item::ItemType::spdUp:
		return Math::Color{ 0.2f, 0.2f, 1.0f };
		break;
	case Item::ItemType::ShotSpdUp:
		return Math::Color{ 0.2f, 1.0f, 0.2f };
		break;
	}
}
