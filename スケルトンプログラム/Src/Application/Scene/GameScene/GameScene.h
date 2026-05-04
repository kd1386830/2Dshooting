#pragma once
#include"../BaseScene/BaseScene.h"

class BaseObject;

class GameScene :public BaseScene
{
public:

	GameScene() {}
	~GameScene()override { Release(); }

	void Init()			override;
	void Update()		override;
	void Draw()			override;

	void EnemySpawn();

	std::vector<std::shared_ptr<BaseObject>> GetObjList() { return m_objList; }

	void AddObject(std::shared_ptr<BaseObject> obj)
	{
		m_objList.push_back(obj);
	}

private:

	void Release()		override;

	std::vector<std::shared_ptr<BaseObject>> m_objList;


	int m_SpawnTimer = 0.0f;
	int m_SpawnInterval = 2.0f * 60.0f; //通常湧き間隔

	int m_WaveTimer = 0.0f;
	int m_WaveInterval = 30.0f * 60.0f; //30秒ごと

	int m_WaveCount = 15; //一度に出す数

};