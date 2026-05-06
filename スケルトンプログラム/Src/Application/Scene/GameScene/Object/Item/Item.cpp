#include "Item.h"
#include"../../GameScene.h"

void Item::Init()
{
	ItemTypeSet();

	m_Tex.Load("Texture/Object/Item.png");

	ItemSpawn();
	m_TransMat = Math::Matrix::CreateTranslation(m_Pos.x, m_Pos.y, 0);
	m_ScaleMat = Math::Matrix::CreateScale(m_Scale, m_Scale, 0);
	m_Mat = m_ScaleMat * m_TransMat;

	m_AliveFlg = true;
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
	SHADER.m_spriteShader.DrawTex(&m_Tex, Math::Rectangle(0, 0, 16, 16), 1.0f);
}

void Item::Release()
{
	m_Tex.Release();
}

void Item::OnHit()
{

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
	m_Type = static_cast<ItemType>(rand() % 2);
}
