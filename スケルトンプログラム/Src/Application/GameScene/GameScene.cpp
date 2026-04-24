#include "GameScene.h"
#include"Object/Player/Player.h"
#include"Object/Player/PlayerBullet.h"

C_GameScene::C_GameScene()
{

}

C_GameScene::~C_GameScene()
{
}

void C_GameScene::Init()
{
	C_Player::GetInstance().Init();
	C_PlayerBullet::GetInstance().Init();
}

void C_GameScene::Update()
{
	C_Player::GetInstance().Update();
	C_PlayerBullet::GetInstance().Update();
}

void C_GameScene::Draw()
{
	C_Player::GetInstance().Draw();
	C_PlayerBullet::GetInstance().Draw();
}
