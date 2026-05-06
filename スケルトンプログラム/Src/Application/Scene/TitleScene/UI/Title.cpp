#include "Title.h"

void Title::Init()
{
	m_Tex.Load("");
	m_Pos = { 0,0 };
}

void Title::Update()
{
	m_Mat = Math::Matrix::CreateTranslation(m_Pos.x, m_Pos.y, 0);
}

void Title::Draw()
{
	//SPACE SURVIVAL
}

void Title::Release()
{
	m_Tex.Release();
}
