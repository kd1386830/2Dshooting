#pragma once
#include"../BaseScene/BaseScene.h"

class Title;
class StartButton;

class TitleScene :public BaseScene
{
public:

	TitleScene() {}
	~TitleScene()override { Release(); }

	void Init()			override;
	void Update()		override;
	void Draw()			override;

private:

	void Release()		override;

	std::shared_ptr<Title> m_title;
	std::shared_ptr<StartButton> m_startButton;

};