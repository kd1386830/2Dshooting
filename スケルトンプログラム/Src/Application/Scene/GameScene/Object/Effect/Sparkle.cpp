#include "Sparkle.h"
#include"../Player/Player.h"
#include"../Item/Item.h"

void Sparkle::Init(Player* player, Item* item)
{
	m_Tex.Load("Texture/Object/Sparkle.png");

	m_Player = player;

	m_Color = item->GetEffectColor();

	m_Scale = 7;
	m_AnimCnt = 0;

	m_ObjType = ObjectType::Sparkle;

}

void Sparkle::Update()
{
	if (!m_Player)return;

	m_Pos = m_Player->GetPos();

	m_AnimCnt += 0.1f;

	if (m_AnimCnt >= 4)
	{
		m_AnimCnt = 0;
		if (m_Player->GetItemActiveTime() <= 0)
		{
			m_AliveFlg = false;
		}
	}

	m_TransMat = Math::Matrix::CreateTranslation(m_Pos.x, m_Pos.y, 0);
	m_ScaleMat = Math::Matrix::CreateScale(m_Scale, m_Scale, 0);
	m_Mat = m_ScaleMat * m_TransMat;
}

void Sparkle::Draw()
{
	if (!m_Player->GetAliveFlg())return;

	D3D.SetBlendState(BlendMode::Add);
	SHADER.m_spriteShader.SetMatrix(m_Mat);
	SHADER.m_spriteShader.DrawTex_Color(&m_Tex, Math::Rectangle(16 * (int)m_AnimCnt, 0, 16, 16), &m_Color);
	D3D.SetBlendState(BlendMode::Alpha);
}

void Sparkle::Release()
{
	m_Tex.Release();
}
