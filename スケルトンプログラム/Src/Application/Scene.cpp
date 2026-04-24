#include "main.h"
#include "Scene.h"
#include"SceneManager/SceneManager.h"

void Scene::Draw2D()
{
	C_SceneManager::GetInstans().Draw();
}

void Scene::Update()
{
	C_SceneManager::GetInstans().Update();
}

void Scene::Init()
{
	C_SceneManager::GetInstans().ChangeState(new C_TitleScene);
	C_SceneManager::GetInstans().Init();
}

void Scene::Release()
{
	
}

void Scene::ImGuiUpdate()
{
	return;

	ImGui::SetNextWindowPos(ImVec2(20, 20), ImGuiSetCond_Once);
	ImGui::SetNextWindowSize(ImVec2(200, 100), ImGuiSetCond_Once);

	// デバッグウィンドウ
	if (ImGui::Begin("Debug Window"))
	{
		ImGui::Text("FPS : %d", APP.m_fps);
	}
	ImGui::End();
}
