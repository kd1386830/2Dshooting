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

	KdTexture m_RankTex;
	Math::Matrix m_TransRankMat;
	Math::Matrix m_ScaleRankMat;
	Math::Matrix m_RankMat;

	Math::Vector2 m_RankPos;
	float m_RankScale;

	float m_DrumRollTimer = 0;

};