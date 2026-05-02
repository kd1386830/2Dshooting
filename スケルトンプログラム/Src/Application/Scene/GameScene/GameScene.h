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

	std::vector<std::shared_ptr<BaseObject>> GetObjList() { return m_objList; }

	void AddObject(std::shared_ptr<BaseObject> obj)
	{
		m_objList.push_back(obj);
	}

private:

	void Release()		override;

	std::vector<std::shared_ptr<BaseObject>> m_objList;

};