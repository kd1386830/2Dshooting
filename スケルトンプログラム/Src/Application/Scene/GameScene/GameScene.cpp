#include "GameScene.h"
#include"../SceneManager.h"

#include"Object/Player/Player.h"
#include"Object/Enemy/Enemy.h"
#include"Object/Player/Bullet.h"

void GameScene::Init()
{
	//プレイヤー
	std::shared_ptr<Player> player;
	player = std::make_shared<Player>();
	player->Init();
	m_objList.push_back(player);

	//弾
	std::shared_ptr<Bullet> bullet;
	bullet = std::make_shared<Bullet>();
	bullet->Init();
	m_objList.push_back(bullet);

	//敵
	std::shared_ptr<Enemy> enemy;
	for (int i = 0;i < 10;i++)
	{
		enemy = std::make_shared<Enemy>();
		enemy->Init();
		m_objList.push_back(enemy);
	}
}

void GameScene::Update()
{
	Player* player = nullptr;

	//Playerを探す
	for (auto& obj : m_objList)
	{
		if (auto p = dynamic_cast<Player*>(obj.get()))
		{
			player = p;
			break;
		}
	}
	//Enemyを探す
	for (auto& obj : m_objList)
	{
		if (auto bullet = dynamic_cast<Bullet*>(obj.get()))
		{
			bullet->SetPlayer(player);
			bullet->SetOwner(this);
		}
		Enemy* enemy = dynamic_cast<Enemy*>(obj.get());
		if (enemy && enemy->GetAliveFlg())
		{
			enemy->SetTarget(player);//Enemyを渡す
		}

		obj->Update();//更新
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
