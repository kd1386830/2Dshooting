#include "TitleScene.h"
#include"../SceneManager.h"

void TitleScene::Init()
{
}

void TitleScene::Update()
{
	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
	{
		SceneManager::Instance().SetNextScene(SceneManager::SceneType::Game);
	}
}

void TitleScene::Draw()
{
	SHADER.m_spriteShader.DrawString(0, 0, "title", { 1,1,1,1 });
}

void TitleScene::Release()
{
}
