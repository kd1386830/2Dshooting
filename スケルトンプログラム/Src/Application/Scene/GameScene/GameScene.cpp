#include "GameScene.h"
#include"../SceneManager.h"

#include"Object/Player/Player.h"

void GameScene::Init()
{
	std::shared_ptr<Player> player;
	player = std::make_shared<Player>();
	player->Init();
	m_objList.push_back(player);
}

void GameScene::Update()
{
	for (int i = 0; i < m_objList.size(); ++i)
	{
		m_objList[i]->Update();
	}


	if (GetAsyncKeyState('R') & 0x8000)
	{
		SceneManager::Instance().SetNextScene(SceneManager::SceneType::Result);
	}
}

void GameScene::Draw()
{
	for (int i = 0; i < m_objList.size(); ++i)
	{
		m_objList[i]->Draw();
	}



	SHADER.m_spriteShader.DrawString(0, 0, "game", { 1,1,1,1 });
}

void GameScene::Release()
{
}
