#pragma once

class Score
{
public:

	enum class RankType
	{
		S,
		A,
		B,
		C,
		D,
		None
	};

	Score() {}
	~Score() {}

	void Init();
	void Update();
	void Draw();
	void Release();

private:

	RankType m_Rank;

	KdTexture m_Tex;
	Math::Matrix m_TransMat;
	Math::Matrix m_ScaleMat;
	Math::Matrix m_Mat;

	Math::Vector2 m_Pos;
	float m_Scale;

};