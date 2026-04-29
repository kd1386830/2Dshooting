#pragma once

class Mouse
{
public:

	~Mouse() {}

	void Init();
	void Update();
	void Draw();

	POINT GetMousePos();

private:

	//画面サイズ
	static const int ScrWidth = 1280;
	static const int ScrHeight = 720;

	//マウス操作
	POINT m_Mouse;

private:

	Mouse() {}

public:
	static Mouse& Instance()
	{
		static Mouse instance;
		return instance;
	}
};