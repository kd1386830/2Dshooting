#pragma once
#include"../BaseScene/BaseScene.h"

class Score;
class RetryButton;
class ReturnTitleButton;

class ResultScene :public BaseScene
{
public:

	ResultScene() {}
	~ResultScene()override { Release(); }

	void Init()			override;
	void Update()		override;
	void Draw()			override;

private:

	void Release()		override;

	std::shared_ptr<Score> m_score;
	std::shared_ptr<RetryButton> m_retryButton;
	std::shared_ptr<ReturnTitleButton> m_returnTitleButton;

};