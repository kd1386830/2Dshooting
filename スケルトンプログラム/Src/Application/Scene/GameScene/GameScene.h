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

private:

	void Release()		override;

	std::vector<std::shared_ptr<BaseObject>> m_objList;

};