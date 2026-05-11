#pragma once

class Star
{
public:

	Star() {}
	~Star() {}

	void Init();
	void Update();
	void Draw();
	void Release();

private:

	static const int StarNum = 20;

	KdTexture m_Tex;

	Math::Matrix m_Mat[StarNum];

	Math::Vector2 m_Pos[StarNum];

	float m_Alpha[StarNum];
	float m_AlphaSpeed[StarNum];
	bool m_BrightFlg[StarNum];

public:
	static Star& Instance()
	{
		static Star instance;
		return instance;
	}
};