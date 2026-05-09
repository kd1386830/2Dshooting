#include "Title.h"

void Title::Init()
{
	m_Tex.Load("Texture/UI/Title.png");
	m_Pos = { 0,120 };
}

void Title::Update()
{
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
