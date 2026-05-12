#include "Title.h"

void Title::Init()
{
	m_Tex.Load("Texture/UI/Title.png");
	m_Pos = { 0.0f,120.0f };
}

void Title::Update()
{
	m_Pos.y += m_Move;
	if (m_Pos.y > 126.0f || m_Pos.y < 114.0f)
	{
		m_Move *= -1;
	}

	m_Mat = Math::Matrix::CreateTranslation(m_Pos.x, m_Pos.y, 0);
}

void Title::Draw()
{
	SHADER.m_spriteShader.SetMatrix(m_Mat);
	SHADER.m_spriteShader.DrawTex(&m_Tex, Math::Rectangle(0, 0, 701, 259), 1.0f);
}

void Title::Release()
{
	m_Tex.Release();
}
