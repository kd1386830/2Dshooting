#include "GameScene.h"
#include"../SceneManager.h"
#include"System/Hit.h"
#include"../../System/Time.h"

#include"Object/Player/Player.h"
#include"Object/Enemy/Enemy.h"
#include"Object/Bullet/Bullet.h"

void GameScene::Init()
{
	Hit::Instance().SetOwner(this);

	Time::Instance().SetOwner(this);
	Time::Instance().Init();
	Time::Instance().StaartCountDown(3.0f);

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

	Time::Instance().Update();

	if (!Time::Instance().GetStartFlg())return;

	for (int i = 0; i < m_objList.size(); ++i)
	{
		m_objList[i]->Update();
	}

	EnemySpawn();


	if (GetAsyncKeyState('R') & 0x8000)
	{
		SceneManager::Instance().SetNextScene(SceneManager::SceneType::Result);
	}
}

void GameScene::Draw()
{

	Time::Instance().Draw();

	if (!Time::Instance().GetStartFlg())return;

	for (int i = 0; i < m_objList.size(); ++i)
	{
		m_objList[i]->Draw();
	}


	//SHADER.m_spriteShader.DrawString(0, 0, "game", { 1,1,1,1 });
}

void GameScene::EnemySpawn()
{
	// 通常湧き
	m_SpawnTimer ++;

	if (m_SpawnTimer >= m_SpawnInterval)
	{
		int count = rand() % 5 + 4; // 1〜2体

		for (int i = 0; i < count; i++)
		{
			std::shared_ptr<Enemy> enemy;
			enemy = std::make_shared<Enemy>();
			enemy->Init();
			enemy->SetOwner(this);
			m_objList.push_back(enemy);
		}

		m_SpawnTimer = 0.0f;
	}

	// ウェーブ湧き
	m_WaveTimer ++;

	if (m_WaveTimer >= m_WaveInterval)
	{
		for (int i = 0; i < m_WaveCount; i++)
		{
			std::shared_ptr<Enemy> enemy;
			enemy = std::make_shared<Enemy>();
			enemy->Init();
			enemy->SetOwner(this);
			m_objList.push_back(enemy);
		}

		m_WaveTimer = 0.0f;
	}
}

void GameScene::Release()
{
}
