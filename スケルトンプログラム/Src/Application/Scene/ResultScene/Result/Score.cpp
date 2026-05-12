#include "Score.h"
#include"../../../System/Time.h"

void Score::Init()
{
	m_Tex.Load("Texture/UI/Rank.png");
	m_RankTex.Load("Texture/UI/Rank_Sprite.bmp");

	m_Scale = 20.0f;
	m_Pos = { 0,190 };

	m_RankScale = 5.0f;
	m_RankPos = { 8,100 };

	m_DrumRollTimer = 0.0f;

	m_Rank = RankType::None;
}

void Score::Update()
{
	m_DrumRollTimer -= 0.2f;
	if (m_DrumRollTimer >= 120)
	{
		int randRank = rand() % 5;

		m_Rank = (RankType)randRank;
	}
	else
	{
		if (Time::Instance().GetAliveTime() <= 30)
		{
			m_Rank = RankType::D;
		}
		else if (Time::Instance().GetAliveTime() > 30 && Time::Instance().GetAliveTime() <= 60)
		{
			m_Rank = RankType::C;
		}
		else if (Time::Instance().GetAliveTime() > 60 && Time::Instance().GetAliveTime() <= 120)
		{
			m_Rank = RankType::B;
		}
		else if (Time::Instance().GetAliveTime() > 120 && Time::Instance().GetAliveTime() <= 180)
		{
			m_Rank = RankType::A;
		}
		else if (Time::Instance().GetAliveTime() > 180)
		{
			m_Rank = RankType::S;
		}
	}

	if (GetAsyncKeyState('1') & 0x8000)
	{
		m_Rank = RankType::S;
	}

	m_TransMat = Math::Matrix::CreateTranslation(m_Pos.x, m_Pos.y, 0);
	m_ScaleMat = Math::Matrix::CreateScale(m_Scale, m_Scale, 0);
	m_Mat = m_ScaleMat * m_TransMat;

	m_TransRankMat = Math::Matrix::CreateTranslation(m_RankPos.x, m_RankPos.y, 0);
	m_ScaleRankMat = Math::Matrix::CreateScale(m_RankScale, m_RankScale, 0);
	m_RankMat = m_ScaleRankMat * m_TransRankMat;
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

	SHADER.m_spriteShader.SetMatrix(m_RankMat);
	SHADER.m_spriteShader.DrawTex(&m_RankTex, Math::Rectangle(0, 0, 32, 8), 1.0f);
}

void Score::Release()
{
	m_Tex.Release();
	m_RankTex.Release();
}
