#pragma once

class ReturnTitleButton
{
public:

	ReturnTitleButton() {}
	~ReturnTitleButton() {}

	void Init();
	void Update();
	void Draw();
	void Release();

private:

	KdTexture m_Tex;

	Math::Matrix m_TransMat;
	Math::Matrix m_ScaleMat;
	Math::Matrix m_Mat;

	Math::Color m_Color;

	Math::Vector2 m_Pos;
	Math::Vector2 m_Radius = { 20.0f,4.0f };

	float m_Scale;

};