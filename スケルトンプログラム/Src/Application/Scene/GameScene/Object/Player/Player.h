#pragma once
#include"../BaseObject.h"

class Player :public BaseObject
{
public:

	Player() {}
	~Player()override { Release(); }

	void Init()override;
	void Update()override;
	void Draw()override;

	void PlayerMove();

private:

	void Release()override;

	Math::Vector2 m_moveVec;
	float m_moveSpd = 5.0f;



};