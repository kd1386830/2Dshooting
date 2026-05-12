#include "ReturnTitleButton.h"
#include"../../../System/MouseHit.h"
#include"../../SceneManager.h"

void ReturnTitleButton::Init()
{
	m_Tex.Load("Texture/UI/RETURN_TO_TITLE.png");
	m_Pos = { 0,-230 };
	m_Scale = 7;
}

void ReturnTitleButton::Update()
{
	if (MouseHit::Instance().UIMouseHit(m_Pos, m_Radius, m_Scale))
	{
		m_Color = { 0.2f, 1.0f, 1.0f, 1.0f };

		if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
		{
			SceneManager::Instance().ChangeFade(SceneManager::SceneType::Title);
		}
	}
	else
	{
		m_Color = { 0.467f, 0.800f, 0.165f };
	}


	m_TransMat = Math::Matrix::CreateTranslation(m_Pos.x, m_Pos.y, 0);
	m_ScaleMat = Math::Matrix::CreateScale(m_Scale, m_Scale, 0);
	m_Mat = m_ScaleMat * m_TransMat;
}

void ReturnTitleButton::Draw()
{
	SHADER.m_spriteShader.SetMatrix(m_Mat);
	SHADER.m_spriteShader.DrawTex_Color(&m_Tex, Math::Rectangle(0, 0, 40, 8), &m_Color);
}

void ReturnTitleButton::Release()
{
	m_Tex.Release();
}
