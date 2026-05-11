#include "SceneManager.h"
#include"BackGround.h"
#include"../System/Mouse.h"
#include"../System/Time.h"
#include"../Scene/BackGroundObject/Star.h"

#include"TitleScene/TitleScene.h"
#include"GameScene/GameScene.h"
#include"ResultScene/ResultScene.h"

void SceneManager::Init()
{
	m_Tex.Load("Texture/UI/SceneChange.png");

	Mouse::Instance().Init();

	ChangeScene(m_currentSceneType);
	BackGround::Instance().Init();
	Star::Instance().Init();
}

void SceneManager::Update()
{

	if (m_currentSceneType != m_nextSceneType)
	{
		ChangeScene(m_nextSceneType);
	}

	m_currentScene->Update();
	Mouse::Instance().Update();
	BackGround::Instance().Update();
	Star::Instance().Update();

	UpdateFade();

	if (GetAsyncKeyState('T') & 0x8000)
	{
		ChangeFade(SceneType::Title);
	}
	if (GetAsyncKeyState('G') & 0x8000)
	{
		ChangeFade(SceneType::Game);
	}
	if (GetAsyncKeyState('R') & 0x8000)
	{
		Time::Instance().SetGameStartFlg(true);
		ChangeFade(SceneType::Result);
	}


	m_Mat = Math::Matrix::CreateTranslation(m_Pos.x, m_Pos.y, 0);
}

void SceneManager::Draw()
{
	BackGround::Instance().Draw();
	Star::Instance().Draw();

	m_currentScene->Draw();

	SHADER.m_spriteShader.SetMatrix(m_Mat);
	SHADER.m_spriteShader.DrawTex(&m_Tex, Math::Rectangle(0, 0, 1280, 720), FadeAlpha);

	Mouse::Instance().Draw();
}

void SceneManager::ChangeFade(SceneType nextScene)
{
	m_NextScene = nextScene;
	nowFade = FadeType::Fade_out;
	FadeAlpha = 0.0f;
}

void SceneManager::UpdateFade()
{
	if (nowFade == FadeType::Fade_out)
	{
		FadeAlpha += 0.05f;

		if (FadeAlpha >= 1.0f)
		{

			FadeAlpha = 1.5f;
			SetNextScene(m_NextScene);

			nowFade = FadeType::Fade_in;
		}

	}
	else if (nowFade == FadeType::Fade_in)
	{
		FadeAlpha -= 0.05f;

		if (FadeAlpha <= 0.0f)
		{
			FadeAlpha = 0.0f;
			nowFade = FadeType::Fade_no;
		}
	}
}

void SceneManager::Release()
{
	m_Tex.Release();

	Mouse::Instance().Release();

	BackGround::Instance().Release();
}

void SceneManager::ChangeScene(SceneType _sceneType)
{
	switch (_sceneType)
	{
	case SceneType::Title:
		m_currentScene = std::make_shared<TitleScene>();
		break;
	case SceneType::Game:
		m_currentScene = std::make_shared<GameScene>();
		break;
	case SceneType::Result:
		m_currentScene = std::make_shared<ResultScene>();
		break;
	}

	m_currentScene->Init();

	m_currentSceneType = _sceneType;
}
