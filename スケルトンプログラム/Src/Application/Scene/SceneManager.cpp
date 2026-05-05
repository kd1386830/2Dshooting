#include "SceneManager.h"
#include"BackGround.h"
#include"../System/Mouse.h"

#include"TitleScene/TitleScene.h"
#include"GameScene/GameScene.h"
#include"ResultScene/ResultScene.h"

void SceneManager::Init()
{
	Mouse::Instance().Init();

	ChangeScene(m_currentSceneType);
	BackGround::Instance().Init();
}

void SceneManager::Update()
{

	if (m_currentSceneType != m_nextSceneType)
	{
		ChangeScene(m_nextSceneType);
	}

	m_currentScene->Update();
	Mouse::Instance().Update();
	BackGround::Instance().Update();
}

void SceneManager::Draw()
{
	BackGround::Instance().Draw();

	m_currentScene->Draw();
	Mouse::Instance().Draw();
}

void SceneManager::Release()
{
	Mouse::Instance().Release();

	BackGround::Instance().Release();
}

void SceneManager::ChangeScene(SceneType _sceneType)
{
	switch (_sceneType)
	{
	case SceneType::Title:
		m_currentScene = std::make_shared<TitleScene>();
		break;
	case SceneType::Game:
		m_currentScene = std::make_shared<GameScene>();
		break;
	case SceneType::Result:
		m_currentScene = std::make_shared<ResultScene>();
		break;
	}

	m_currentScene->Init();

	m_currentSceneType = _sceneType;
}
