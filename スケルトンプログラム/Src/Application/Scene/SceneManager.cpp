#include "SceneManager.h"

#include"TitleScene/TitleScene.h"
#include"GameScene/GameScene.h"
#include"ResultScene/ResultScene.h"

void SceneManager::Init()
{
	ChangeScene(m_currentSceneType);
}

void SceneManager::Update()
{
	if (m_currentSceneType != m_nextSceneType)
	{
		ChangeScene(m_nextSceneType);
	}
	m_currentScene->Update();
}

void SceneManager::Draw()
{
	m_currentScene->Draw();
}

void SceneManager::Release()
{
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
