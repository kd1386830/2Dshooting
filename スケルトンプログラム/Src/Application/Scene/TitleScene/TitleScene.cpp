#include "TitleScene.h"
#include"UI/Title.h"
#include"UI/StartButton.h"

void TitleScene::Init()
{
	Title::Instance().Init();
	StartButton::Instance().Init();
}

void TitleScene::Update()
{
	Title::Instance().Update();
	StartButton::Instance().Update();
	
}

void TitleScene::Draw()
{
	Title::Instance().Draw();
	StartButton::Instance().Draw();
}

void TitleScene::Release()
{
	Title::Instance().Release();
	StartButton::Instance().Release();
}
