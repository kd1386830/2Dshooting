#include "Player.h"
#include"../../../System/Mouse.h"

C_Player::C_Player()
{
	m_PlayerTex.Load("Texture/player.png");
}

C_Player::~C_Player()
{
	m_PlayerTex.Release();
}

void C_Player::Init()
{
	m_PlayerPos = { 0,0 };
	m_PlayerMove = 5;
	m_PlayerSize = 1;
}

void C_Player::Update()
{
	PlayerMove();
	PlayerRotation();

	m_PlayerTransMat = Math::Matrix::CreateTranslation(m_PlayerPos.x, m_PlayerPos.y, 0);
	m_PlayerScaleMat = Math::Matrix::CreateScale(m_PlayerSize, m_PlayerSize, 0);
	m_PlayerRotateMat = Math::Matrix::CreateRotationZ(m_PlayerAngle - DirectX::XM_PIDIV2);

	m_PlayerMat = m_PlayerScaleMat * m_PlayerRotateMat * m_PlayerTransMat;
}

void C_Player::Draw()
{
	SHADER.m_spriteShader.SetMatrix(m_PlayerMat);
	SHADER.m_spriteShader.DrawTex(&m_PlayerTex, Math::Rectangle(0, 0, 64, 64), 1.0f);
}

void C_Player::PlayerMove()
{
	if (GetAsyncKeyState('W') & 0x8000 || GetAsyncKeyState(VK_UP) & 0x8000)
	{
		m_PlayerPos.y += m_PlayerMove;
	}
	if (GetAsyncKeyState('A') & 0x8000 || GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		m_PlayerPos.x -= m_PlayerMove;
	}
	if (GetAsyncKeyState('S') & 0x8000 || GetAsyncKeyState(VK_DOWN) & 0x8000)
	{
		m_PlayerPos.y -= m_PlayerMove;
	}
	if (GetAsyncKeyState('D') & 0x8000 || GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		m_PlayerPos.x += m_PlayerMove;
	}
}

void C_Player::PlayerRotation()
{
	float dx = C_Mouse::GetInstance().GetMousePos().x - m_PlayerPos.x;
	float dy = C_Mouse::GetInstance().GetMousePos().y - m_PlayerPos.y;

	m_PlayerAngle = atan2(dy, dx);
}
