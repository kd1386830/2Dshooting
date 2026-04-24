#include "Title.h"
#include"../SceneManager/SceneManager.h"

void C_Title::Init()
{
}

void C_Title::Update()
{
	if (GetAsyncKeyState(VK_RETURN) & 0x8000)
	{
		//C_SceneManager::GetInstans().ChangeState();
	}
}

void C_Title::Draw()
{
	SHADER.m_spriteShader.DrawString(0, 0, "TITLE", { 1,1,1,1 });
}
