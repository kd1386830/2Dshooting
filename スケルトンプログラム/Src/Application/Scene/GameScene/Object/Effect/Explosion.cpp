#include "Explosion.h"

void Explosion::Init(Math::Vector2 pos)
{
	m_Tex.Load("Texture/Object/Explosion.png");

	m_Pos = pos;
	m_Scale = 4;
	m_AnimCnt = 0;

	m_ObjType = ObjectType::Explosion;
}

void Explosion::Update()
{
	m_AnimCnt += 0.2f;

	if (m_AnimCnt >= 5)
	{
		m_AliveFlg = false;
	}



	m_TransMat = Math::Matrix::CreateTranslation(m_Pos.x, m_Pos.y, 0);
	m_ScaleMat = Math::Matrix::CreateScale(m_Scale, m_Scale, 0);
	m_Mat = m_ScaleMat * m_TransMat;
}

void Explosion::Draw()
{
	SHADER.m_spriteShader.SetMatrix(m_Mat);
	SHADER.m_spriteShader.DrawTex(&m_Tex, Math::Rectangle(16 * (int)m_AnimCnt, 0, 16, 16), 1.0f);
}

void Explosion::Release()
{
	m_Tex.Release();
}
