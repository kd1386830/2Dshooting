#include "Player.h"

void Player::Init()
{
	m_tex.Load("Texture/player.png");
	m_pos = { 0,0 };
	m_aliveFlg = true;
}

void Player::Update()
{
	PlayerMove();


	m_mat = Math::Matrix::CreateTranslation(m_pos.x, m_pos.y, 0);
}

void Player::Draw()
{
	SHADER.m_spriteShader.SetMatrix(m_mat);
	SHADER.m_spriteShader.DrawTex(&m_tex, Math::Rectangle(0, 0, 64, 64), 1.0f);
}

void Player::PlayerMove()
{
	m_moveVec = { 0,0 };
	if (GetAsyncKeyState('W') & 0x8000 || GetAsyncKeyState(VK_UP) & 0x8000)m_moveVec.y = 1.0f;
	if(GetAsyncKeyState('A')&0x8000 || GetAsyncKeyState(VK_LEFT)&0x8000)m_moveVec.x = -1.0f;
	if(GetAsyncKeyState('S')&0x8000 || GetAsyncKeyState(VK_DOWN)&0x8000)m_moveVec.y = -1.0f;
	if(GetAsyncKeyState('D')&0x8000 || GetAsyncKeyState(VK_RIGHT)&0x8000)m_moveVec.x = 1.0f;
	m_moveVec.Normalize();
	m_pos += m_moveVec * m_moveSpd;
}

void Player::Release()
{
	m_tex.Release();
}
