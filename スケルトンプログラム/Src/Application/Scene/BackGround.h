#pragma once

class BackGround
{
public:

	BackGround() {}
	~BackGround() {}

	void Init();
	void Update();
	void Draw();
	void Release();

private:

	KdTexture m_Tex;
	Math::Matrix m_TransMat;
	Math::Matrix m_ScaleMat;
	Math::Matrix m_Mat;
	Math::Vector2 m_Pos;
	Math::Vector2 m_Scale;

public:
	static BackGround& Instance()
	{
		static BackGround instance;
		return instance;
	}
};