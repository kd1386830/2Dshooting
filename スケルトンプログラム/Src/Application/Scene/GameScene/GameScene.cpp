#include "GameScene.h"
#include"../SceneManager.h"
#include"System/Hit.h"
#include"../../System/Time.h"
#include"System/GameOver.h"

#include"Object/Player/Player.h"
#include"Object/Enemy/Enemy.h"
#include"Object/Bullet/Bullet.h"
#include"Object/Item/Item.h"

void GameScene::Init()
{
	GameOver::Instance().SetOwner(this);
	GameOver::Instance().Init();

	Time::Instance().SetOwner(this);
	Time::Instance().Init();
	Time::Instance().StaartCountDown(3.0f);

	//プレイヤー
	std::shared_ptr<Player> player;
	player = std::make_shared<Player>();
	player->Init();
	player->SetOwner(this);
	m_objList.push_back(player);

}

void GameScene::Update()
{
	GameOver::Instance().Update();

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

	if (Time::Instance().GetOverFlg())return;
	if (!Time::Instance().GetStartFlg())return;

	for (int i = 0; i < m_objList.size(); ++i)
	{
		m_objList[i]->Update();
	}

	
	EnemySpawn();
	ItemSpawn();


	if (GetAsyncKeyState('R') & 0x8000)
	{
		SceneManager::Instance().ChangeFade(SceneManager::SceneType::Result);
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

	GameOver::Instance().Draw();

}

void GameScene::EnemySpawn()
{	
	// 通常湧き
	m_SpawnTimer ++;

	if (m_SpawnTimer >= m_SpawnInterval)
	{
		int count = rand() % m_RandTop + m_RandBottom;

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

		m_RandTop++;
		m_RandBottom++;
		m_WaveTimer = 0.0f;
		m_WaveCount += 5;
	}
}

void GameScene::ItemSpawn()
{
	m_ItemTimer++;

	if (m_ItemTimer >= m_ItemInterval)
	{
		std::shared_ptr<Item> item;
		item = std::make_shared<Item>();
		item->Init();
		item->SetOwner(this);

		m_objList.push_back(item);


		m_ItemTimer = 0.0f;
	}
}

void GameScene::Release()
{
}
