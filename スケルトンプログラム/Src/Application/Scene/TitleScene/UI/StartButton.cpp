#include "StartButton.h"
#include"../../SceneManager.h"
#include"../../../System/Mouse.h"
#include"../../../System/MouseHit.h"

void StartButton::Init()
{
	m_Tex.Load("Texture/UI/GAME_START.png");
	m_Pos = { 0,-180 };
	m_Scale = 7;
}

void StartButton::Update()
{
	if (MouseHit::Instance().UIMouseHit(m_Pos, m_Radius, m_Scale))
	{
		m_Color = { 0.2f, 1.0f, 1.0f, 1.0f };

		if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
		{
			SceneManager::Instance().ChangeFade(SceneManager::SceneType::Game);
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

void StartButton::Draw()
{
	SHADER.m_spriteShader.SetMatrix(m_Mat);
	SHADER.m_spriteShader.DrawTex_Color(&m_Tex, Math::Rectangle(0, 0, 40, 8), &m_Color);
}

void StartButton::Release()
{
	m_Tex.Release();
}
