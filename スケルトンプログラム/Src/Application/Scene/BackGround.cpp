#include "BackGround.h"

void BackGround::Init()
{
	m_Tex.Load("Texture/Object/BackGround.png");
	m_Pos = { 0,0 };
	m_Scale = { 10,11.25 };
}

void BackGround::Update()
{
	m_TransMat = Math::Matrix::CreateTranslation(m_Pos.x, m_Pos.y, 0);
	m_ScaleMat = Math::Matrix::CreateScale(m_Scale.x, m_Scale.y, 0);
	m_Mat = m_ScaleMat * m_TransMat;
}

void BackGround::Draw()
{
	SHADER.m_spriteShader.SetMatrix(m_Mat);
	SHADER.m_spriteShader.DrawTex(&m_Tex, Math::Rectangle(0, 0, 128, 64), 1.0f);
}

void BackGround::Release()
{
	m_Tex.Release();
}
