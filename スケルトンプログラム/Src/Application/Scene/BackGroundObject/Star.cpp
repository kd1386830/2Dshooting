#include "Star.h"

void Star::Init()
{
	m_Tex.Load("Texture/Object/Star.png");

	for (int i = 0;i < StarNum;i++)
	{
		m_Pos[i] = {rand() % 1280 - 640.0f,rand() % 720 - 360.0f};
		m_Alpha[i] = rand() % 100 / 100.0f;

		m_AlphaSpeed[i] = (rand() % 10 + 1) * 0.001f;
	}
}

void Star::Update()
{
	for (int i = 0;i < StarNum;i++)
	{
		if (m_BrightFlg[i])
		{
			m_Alpha[i] += m_AlphaSpeed[i];

			if (m_Alpha[i] >= 1.0f)
			{
				m_Alpha[i] = 1.0f;

				m_BrightFlg[i] = false;
			}
		}
		else
		{
			m_Alpha[i] -= m_AlphaSpeed[i];

			if (m_Alpha[i] <= 0.0f)
			{
				m_Alpha[i] = 0.0f;

				m_BrightFlg[i] = true;
			}
		}
	}

	for (int i = 0;i < StarNum;i++)
	{
		m_Mat[i] = Math::Matrix::CreateTranslation(m_Pos[i].x, m_Pos[i].y, 0);
	}
}

void Star::Draw()
{
	for (int i = 0;i < StarNum;i++)
	{
		SHADER.m_spriteShader.SetMatrix(m_Mat[i]);
		SHADER.m_spriteShader.DrawTex(&m_Tex, Math::Rectangle(0, 0, 12, 12), m_Alpha[i]);
	}
}

void Star::Release()
{
	m_Tex.Release();
}
