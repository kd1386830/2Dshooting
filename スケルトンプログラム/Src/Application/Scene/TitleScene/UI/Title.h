#pragma once

class Title
{
public:

	Title() {}
	~Title() {}

	void Init();
	void Update();
	void Draw();
	void Release();

private:

	KdTexture m_Tex;
	Math::Matrix m_Mat;
	Math::Vector2 m_Pos;

};