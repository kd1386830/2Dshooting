#include "GameScene.h"

C_GameScene::C_GameScene()
{
	
}

C_GameScene::~C_GameScene()
{
}

void C_GameScene::Init()
{
	m_player.Init();
	m_Pbullet.Init();
}

void C_GameScene::Update()
{
	m_player.Update();
	m_Pbullet.Update();


	if (m_player.GetShotFlg())
	{
		m_Pbullet.shot(m_player);
	}

}

void C_GameScene::Draw()
{
	m_Pbullet.Draw();
	m_player.Draw();
}
