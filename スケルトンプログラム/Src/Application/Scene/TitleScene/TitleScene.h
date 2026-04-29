#pragma once
#include"../BaseScene/BaseScene.h"

class TitleScene:public BaseScene
{
public:

	TitleScene() {}
	~TitleScene()override { Release(); }

	void Init()			override;
	void Update()		override;
	void Draw()			override;

private:

	void Release()		override;

};