#include "ResultScene.h"
#include"../SceneManager.h"

#include"Result/Score.h"
#include"../../System/Time.h"

void ResultScene::Init()
{
	Time::Instance().Init();

	m_score = std::make_shared<Score>();
	m_score->Init();
}

void ResultScene::Update()
{
	Time::Instance().Update();

	m_score->Update();

	if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
	{
		SceneManager::Instance().ChangeFade(SceneManager::SceneType::Title);
	}
}

void ResultScene::Draw()
{
	Time::Instance().Draw();

	m_score->Draw();
}

void ResultScene::Release()
{
	Time::Instance().Release();

	m_score->Release();
}
