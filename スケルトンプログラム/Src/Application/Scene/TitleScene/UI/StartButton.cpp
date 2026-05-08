#include "StartButton.h"
#include"../../SceneManager.h"
#include"../../../System/Mouse.h"

void StartButton::Init()
{
	m_Tex.Load("Texture/UI/GAME_START.png");
	m_Pos = { 0,-100 };
	m_Scale = 7;
}

void StartButton::Update()
{
	if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
	{
		if (MouseHit())
		{
			SceneManager::Instance().ChangeFade(SceneManager::SceneType::Game);
		}
	}

	m_TransMat = Math::Matrix::CreateTranslation(m_Pos.x, m_Pos.y, 0);
	m_ScaleMat = Math::Matrix::CreateScale(m_Scale, m_Scale, 0);
	m_Mat = m_ScaleMat * m_TransMat;
}

void StartButton::Draw()
{
	SHADER.m_spriteShader.SetMatrix(m_Mat);
	SHADER.m_spriteShader.DrawTex(&m_Tex, Math::Rectangle(0, 0, 76, 8), 1.0f);
}

void StartButton::Release()
{
	m_Tex.Release();
}

bool StartButton::MouseHit()
{
	const float StartRight = m_Pos.x + (m_Radius.x * m_Scale);
	const float StartLeft = m_Pos.x - (m_Radius.x * m_Scale);
	const float StartTop = m_Pos.y + (m_Radius.y * m_Scale);
	const float StartBottom = m_Pos.y - (m_Radius.y * m_Scale);

	const float x = Mouse::Instance().GetMousePos().x;
	const float y = Mouse::Instance().GetMousePos().y;

	if (x< StartRight && x>StartLeft && y< StartTop && y>StartBottom)
	{
		return true;
	}
	else
	{
		return false;
	}
}
