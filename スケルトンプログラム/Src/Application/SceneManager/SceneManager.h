#pragma once
#include"../TitleScene/TitleScene.h"
#include"../GameScene/Gamescene.h"

class C_SceneManager
{
public:

	~C_SceneManager();

	void ChangeState(C_State* newState);

	void ChangeFade(C_State* newState);
	void UpdateFade();

	void Init();

	void Update();

	void Draw();

private:

	C_SceneManager() {}

	C_State* currentState = nullptr;

	//C_BackGround m_backGround;

public:

	static C_SceneManager& GetInstans()
	{
		static C_SceneManager instans;
		return instans;
	}

};