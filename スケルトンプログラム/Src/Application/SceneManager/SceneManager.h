#pragma once

class C_State;

class C_SceneManager
{
public:

	~C_SceneManager();

	void ChangeState(std::shared_ptr<C_State> newState);

	void ChangeFade(C_State* newState);
	void UpdateFade();

	void Init();

	void Update();

	void Draw();

private:

	C_SceneManager() {}

	std::shared_ptr<C_State> m_currentState;

	//C_State* currentState = nullptr;

	//C_BackGround m_backGround;

public:

	static C_SceneManager& GetInstans()
	{
		static C_SceneManager instans;
		return instans;
	}

};

#define SCENEMANAGER C_SceneManager::GetInstans()