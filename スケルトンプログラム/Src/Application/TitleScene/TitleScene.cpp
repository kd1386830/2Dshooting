#include "TitleScene.h"
#include"Title.h"

C_TitleScene::C_TitleScene()
{
}

C_TitleScene::~C_TitleScene()
{
}

void C_TitleScene::Init()
{
	C_Title::GetInstans().Init();
}

void C_TitleScene::Update()
{
	C_Title::GetInstans().Update();
}

void C_TitleScene::Draw()
{
	C_Title::GetInstans().Draw();
}
