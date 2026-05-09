#include "ResultScene.h"

#include"Result/Score.h"
#include"Result/RetryButton.h"
#include"Result/ReturnTitleButton.h"
#include"../../System/Time.h"

void ResultScene::Init()
{
	Time::Instance().Init();

	m_score = std::make_shared<Score>();
	m_retryButton = std::make_shared<RetryButton>();
	m_returnTitleButton = std::make_shared<ReturnTitleButton>();

	m_score->Init();
	m_retryButton->Init();
	m_returnTitleButton->Init();
}

void ResultScene::Update()
{
	Time::Instance().Update();

	m_score->Update();
	m_retryButton->Update();
	m_returnTitleButton->Update();
}

void ResultScene::Draw()
{
	Time::Instance().Draw();

	m_score->Draw();
	m_retryButton->Draw();
	m_returnTitleButton->Draw();
}

void ResultScene::Release()
{
	Time::Instance().Release();

	m_score->Release();
	m_retryButton->Release();
	m_returnTitleButton->Release();
}
