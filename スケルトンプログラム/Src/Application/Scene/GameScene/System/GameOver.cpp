#include "GameOver.h"
#include"../GameScene.h"
#include"../Object/BaseObject.h"
#include"../../SceneManager.h"

void GameOver::Init()
{
	m_Tex.Load("Texture/UI/GAME_OVER.png");

	m_Pos = { 0,0 };
	m_Alpha = 0.0f;
	m_SceneCount = 0.0f;
	m_SceneFlg = false;
	m_PlayerDeadFlg = false;
	m_ChangeSceneFlg = false;
}

void GameOver::Update()
{
	for (auto& obj : m_Owner->GetObjList())
	{
		if (obj->GetObjType() == BaseObject::ObjectType::Player)
		{
			if(!obj->GetAliveFlg())
			{
				m_PlayerDeadFlg = true;
			}
		}
	}

	if(m_PlayerDeadFlg)
	{
		if (m_Alpha >= 1.0f)
		{
			m_Alpha = 1.0f;
			m_SceneFlg = true;
		}
		else
		{
			m_Alpha += 0.02f;
		}

		if (m_SceneFlg)
		{
			m_SceneCount++;
			if (!m_ChangeSceneFlg && m_SceneCount >= 2.0f * 60.0f)
			{
				m_ChangeSceneFlg = true;
				SceneManager::Instance().ChangeFade(SceneManager::SceneType::Result);
			}
		}
	}

	m_TransMat = Math::Matrix::CreateTranslation(m_Pos.x, m_Pos.y, 0);
	m_ScaleMat = Math::Matrix::CreateScale(m_Scale, m_Scale, 0);
	m_Mat = m_ScaleMat * m_TransMat;
}

void GameOver::Draw()
{
	SHADER.m_spriteShader.SetMatrix(m_Mat);
	SHADER.m_spriteShader.DrawTex(&m_Tex, Math::Rectangle(0, 0, 68, 8), m_Alpha);
}

void GameOver::Release()
{
	m_Tex.Release();
}
