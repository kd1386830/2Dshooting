#include "TitleScene.h"
#include"UI/Title.h"
#include"UI/StartButton.h"

void TitleScene::Init()
{
	m_title = std::make_shared<Title>();
	m_startButton = std::make_shared<StartButton>();

	m_title->Init();
	m_startButton->Init();
}

void TitleScene::Update()
{
	m_title->Update();
	m_startButton->Update();
}

void TitleScene::Draw()
{
	m_title->Draw();
	m_startButton->Draw();
}

void TitleScene::Release()
{
	m_title->Release();
	m_startButton->Release();
}
