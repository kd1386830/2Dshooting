#pragma once
#include"../BaseObject.h"

class Explosion :public BaseObject
{
public:

	Explosion() {}
	~Explosion() {}

	void Init(Math::Vector2 pos);
	void Update()override;
	void Draw()override;
	void Release()override;


private:

	Math::Matrix m_TransMat;
	Math::Matrix m_ScaleMat;

	float m_Scale;

	float m_AnimCnt;

};