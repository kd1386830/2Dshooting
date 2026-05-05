#pragma once

class StartButton
{
public:

	StartButton() {}
	~StartButton() {}

	void Init();
	void Update();
	void Draw();
	void Release();

	bool MouseHit();

private:

	KdTexture m_Tex;
	Math::Matrix m_TransMat;
	Math::Matrix m_ScaleMat;
	Math::Matrix m_Mat;

	Math::Vector2 m_Pos;
	Math::Vector2 m_Radius = { 38.0f,4.0f };

	float m_Scale;

public:
	static StartButton& Instance()
	{
		static StartButton instance;
		return instance;
	}
};