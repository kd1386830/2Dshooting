#pragma once

class C_BackGround
{
public:

	C_BackGround();
	~C_BackGround();

	void Init();
	void Update();
	void Draw();


private:

	KdTexture m_BackTex;

	Math::Matrix m_BackMat1;
	Math::Matrix m_BackMat2;

	Math::Vector2 m_BackPos;

};