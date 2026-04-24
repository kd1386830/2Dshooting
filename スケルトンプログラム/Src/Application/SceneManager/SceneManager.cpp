#include"SceneManager.h"

C_SceneManager::~C_SceneManager()
{
}

void C_SceneManager::ChangeState(C_State* newState)
{
	delete currentState;
	currentState = newState;
	currentState->Init();
}

void C_SceneManager::ChangeFade(C_State* newState)
{
	/*NextState = newState;

	NowFade = FadeType::Fade_out;
	FadeAlpha = 0.0f;*/

}

void C_SceneManager::UpdateFade()
{
	/*if (NowFade == Fade_out)
	{
		FadeAlpha += 0.05f;

		if (FadeAlpha >= 1.0f)
		{

			FadeAlpha += 1.0f;
			ChangeState(NextState);

			NextState = nullptr;
			NowFade = FadeType::Fade_in;
		}

	}
	else if (NowFade == Fade_in)
	{
		FadeAlpha -= 0.05f;

		if (FadeAlpha <= 0.0f)
		{
			FadeAlpha = 0.0f;
			NowFade = FadeType::Fade_no;
		}
	}*/
}

void C_SceneManager::Init()
{
	currentState->Init();
}

void C_SceneManager::Update()
{
	currentState->Update();
}

void C_SceneManager::Draw()
{
	currentState->Draw();
}
