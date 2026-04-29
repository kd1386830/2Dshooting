#pragma once

class BaseScene
{
public:

	BaseScene() {}
	virtual ~BaseScene() { Release(); }

	virtual void Init();
	virtual void Update();
	virtual void Draw();
	virtual void Release();

private:


};