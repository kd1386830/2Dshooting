#include "Score.h"
#include"../../../System/Time.h"

void Score::Init()
{
	m_Tex.Load("Texture/UI/Rank.png");

	m_Scale = 20.0f;
	m_Pos = { 0,100 };

	m_Rank = RankType::None;
}

void Score::Update()
{
	if (Time::Instance().GetAliveTime() <= 20)
	{
		m_Rank = RankType::D;
	}
	else if (Time::Instance().GetAliveTime() > 20 && Time::Instance().GetAliveTime() <= 40)
	{
		m_Rank = RankType::C;
	}
	else if(Time::Instance().GetAliveTime() > 40 && Time::Instance().GetAliveTime() <= 60)
	{
		m_Rank = RankType::B;
	}
	else if (Time::Instance().GetAliveTime() > 60 && Time::Instance().GetAliveTime() <= 120)
	{
		m_Rank = RankType::A;
	}
	else if (Time::Instance().GetAliveTime() > 120)
	{
		m_Rank = RankType::S;
	}

	//m_Rank = RankType::B;

	m_TransMat = Math::Matrix::CreateTranslation(m_Pos.x, m_Pos.y, 0);
	m_ScaleMat = Math::Matrix::CreateScale(m_Scale, m_Scale, 0);
	m_Mat = m_ScaleMat * m_TransMat;
}

void Score::Draw()
{
	SHADER.m_spriteShader.SetMatrix(m_Mat);
	switch (m_Rank)
	{
	case Score::RankType::S:
		SHADER.m_spriteShader.DrawTex(&m_Tex, Math::Rectangle(0, 0, 8, 8), 1.0f);
		break;
	case Score::RankType::A:
		SHADER.m_spriteShader.DrawTex(&m_Tex, Math::Rectangle(8, 0, 8, 8), 1.0f);
		break;
	case Score::RankType::B:
		SHADER.m_spriteShader.DrawTex(&m_Tex, Math::Rectangle(16, 0, 8, 8), 1.0f);
		break;
	case Score::RankType::C:
		SHADER.m_spriteShader.DrawTex(&m_Tex, Math::Rectangle(24, 0, 8, 8), 1.0f);
		break;
	case Score::RankType::D:
		SHADER.m_spriteShader.DrawTex(&m_Tex, Math::Rectangle(32, 0, 8, 8), 1.0f);
		break;
	}
}

void Score::Release()
{
	m_Tex.Release();
}
