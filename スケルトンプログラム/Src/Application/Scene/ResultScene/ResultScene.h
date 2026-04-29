#pragma once
#include"../BaseScene/BaseScene.h"

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

};