#include "Title.h"
#include"SceneManager.h"

C_Title::C_Title()
{
}

C_Title::~C_Title()
{
}

void C_Title::Init()
{
}

void C_Title::Update()
{
	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
	{
		SCENEMANAGER.ChangeState(new C_GameScene);
	}
}

void C_Title::Draw()
{
	SHADER.m_spriteShader.DrawString(0, 0, "ƒ^ƒCƒgƒ‹", { 1,1,1,1 });
}
