#pragma once

class Mouse
{
public:

	~Mouse() {}

	void Init();
	void Update();
	void Draw();
	void Release();

	POINT GetMousePos();

private:

	//画面サイズ
	static const int ScrWidth = 1280;
	static const int ScrHeight = 720;

	//マウス操作
	POINT m_Mouse;

	KdTexture m_Tex;
	Math::Matrix m_Mat;

private:

	Mouse() {}

public:
	static Mouse& Instance()
	{
		static Mouse instance;
		return instance;
	}
};