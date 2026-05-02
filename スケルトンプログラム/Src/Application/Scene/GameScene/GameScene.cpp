#include "GameScene.h"
#include"../SceneManager.h"
#include"System/Hit.h"

#include"Object/Player/Player.h"
#include"Object/Enemy/Enemy.h"
#include"Object/Bullet/Bullet.h"

void GameScene::Init()
{
	Hit::Instance().SetOwner(this);

	//プレイヤー
	std::shared_ptr<Player> player;
	player = std::make_shared<Player>();
	player->Init();
	player->SetOwner(this);
	m_objList.push_back(player);

	//敵
	std::shared_ptr<Enemy> enemy;
	for (int i = 0;i < 10;i++)
	{
		enemy = std::make_shared<Enemy>();
		enemy->Init();
		enemy->SetOwner(this);
		m_objList.push_back(enemy);
	}
}

void GameScene::Update()
{
	auto it = m_objList.begin();

	while (it != m_objList.end())
	{
		if ((*it)->GetAliveFlg() == false)
		{
			it = m_objList.erase(it);
		}
		else
		{
			it++;
		}
	}



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
