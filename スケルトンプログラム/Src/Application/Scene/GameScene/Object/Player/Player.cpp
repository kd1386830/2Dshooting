#include "Player.h"
#include"../Bullet/Bullet.h"
#include"../../GameScene.h"

#include"../../../../System/Mouse.h"

void Player::Init()
{
	m_Tex.Load("Texture/player.png");

	m_Pos = { 0,0 };
	m_AliveFlg = true;
	m_Radius = 32.0f;

	m_ObjType = ObjectType::Player;
}

void Player::Update()
{
	PlayerMove();
	PlayerRotation();

	if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
	{
		std::shared_ptr<Bullet>bullet;
		bullet = std::make_shared<Bullet>();
		bullet->Init();
		bullet->Shot(this);
		m_Owner->AddObject(bullet);
	}

	m_TransMat = Math::Matrix::CreateTranslation(m_Pos.x, m_Pos.y, 0);
	m_RotateMat = Math::Matrix::CreateRotationZ(m_Angle - DirectX::XM_PIDIV2);
	m_Mat = m_RotateMat * m_TransMat;
}

void Player::Draw()
{
	SHADER.m_spriteShader.SetMatrix(m_Mat);
	SHADER.m_spriteShader.DrawTex(&m_Tex, Math::Rectangle(0, 0, 64, 64), 1.0f);
}

void Player::OnHit()
{

}

void Player::PlayerMove()
{
	m_MoveVec = { 0,0 };
	if (GetAsyncKeyState('W') & 0x8000 || GetAsyncKeyState(VK_UP) & 0x8000)		m_MoveVec.y = 1.0f;
	if (GetAsyncKeyState('A') & 0x8000 || GetAsyncKeyState(VK_LEFT) & 0x8000)	m_MoveVec.x = -1.0f;
	if (GetAsyncKeyState('S') & 0x8000 || GetAsyncKeyState(VK_DOWN) & 0x8000)	m_MoveVec.y = -1.0f;
	if (GetAsyncKeyState('D') & 0x8000 || GetAsyncKeyState(VK_RIGHT) & 0x8000)	m_MoveVec.x = 1.0f;
	m_MoveVec.Normalize();
	m_Pos += m_MoveVec * m_MoveSpd;
}

void Player::PlayerRotation()
{
	float dx = Mouse::Instance().GetMousePos().x - m_Pos.x;
	float dy = Mouse::Instance().GetMousePos().y - m_Pos.y;

	m_Angle = atan2(dy, dx);
}

void Player::Release()
{
	m_Tex.Release();
}
