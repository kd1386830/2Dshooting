#include "Mouse.h"
#include"../main.h"

void Mouse::Init()
{
	m_Mouse = GetMousePos();
}

void Mouse::Update()
{
	m_Mouse = GetMousePos();
}

void Mouse::Draw()
{
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
