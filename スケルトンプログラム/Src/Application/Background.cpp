#include "Background.h"

C_BackGround::C_BackGround()
{
	m_BackTex.Load("Texture/back.png");
}

C_BackGround::~C_BackGround()
{
	m_BackTex.Release();
}

void C_BackGround::Init()
{
	m_BackPos = { 0,0 };
}

void C_BackGround::Update()
{
	m_BackPos.y -= 3;

	if (m_BackPos.y < -720)
	{
		m_BackPos.y = 0;
	}

	m_BackMat1 = Math::Matrix::CreateTranslation(m_BackPos.x, m_BackPos.y, 0);
	m_BackMat2 = Math::Matrix::CreateTranslation(m_BackPos.x, m_BackPos.y + 720, 0);
}

void C_BackGround::Draw()
{
	SHADER.m_spriteShader.SetMatrix(m_BackMat1);
	SHADER.m_spriteShader.DrawTex(&m_BackTex, Math::Rectangle(0, 0, 1280, 720), 1.0f);
	SHADER.m_spriteShader.SetMatrix(m_BackMat2);
	SHADER.m_spriteShader.DrawTex(&m_BackTex, Math::Rectangle(0, 0, 1280, 720), 1.0f);
}