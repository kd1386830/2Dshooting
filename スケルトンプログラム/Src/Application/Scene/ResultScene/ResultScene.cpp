#include "ResultScene.h"
#include"../SceneManager.h"

void ResultScene::Init()
{
}

void ResultScene::Update()
{
	if (GetAsyncKeyState('T') & 0x8000)
	{
		SceneManager::Instance().SetNextScene(SceneManager::SceneType::Title);
	}
}

void ResultScene::Draw()
{

}

void ResultScene::Release()
{
}
