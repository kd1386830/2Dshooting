#include "Mouse.h"
#include"../main.h"

void Mouse::Init()
{
	m_Tex.Load("Texture/UI/Sight.png");

	m_Mouse = GetMousePos();
}

void Mouse::Update()
{
	ShowCursor(FALSE);//マウスカーソル非表示

	m_Mouse = GetMousePos();

	m_Mat = Math::Matrix::CreateTranslation(m_Mouse.x, m_Mouse.y, 0);
}

void Mouse::Draw()
{
	SHADER.m_spriteShader.SetMatrix(m_Mat);
	SHADER.m_spriteShader.DrawTex(&m_Tex, Math::Rectangle(0, 0, 36, 36), 1.0f);
}

void Mouse::Release()
{
	m_Tex.Release();
}

POINT Mouse::GetMousePos()
{
	POINT m;
	GetCursorPos(&m);
	ScreenToClient(APP.m_window.GetWndHandle(), &m);
	m.x -= ScrWidth / 2;
	m.y -= ScrHeight / 2;
	m.y *= -1;
	return m;
}
