#include "Title.h"
#include"../SceneManager/SceneManager.h"

void C_Title::Init()
{
}

void C_Title::Update()
{
	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
	{
		C_SceneManager::GetInstans().ChangeState(new C_GameScene);
	}
}

void C_Title::Draw()
{
	SHADER.m_spriteShader.DrawString(0, 0, "TITLE", { 1,1,1,1 });
}
