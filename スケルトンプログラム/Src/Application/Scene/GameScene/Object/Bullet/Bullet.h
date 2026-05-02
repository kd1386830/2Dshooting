#pragma once
#include"../BaseObject.h"

class Player;
class Enemy;
class GameScene;

class Bullet :public BaseObject
{
public:

	Bullet() {}
	~Bullet()override { Release(); }

	void Init()override;
	void Update()override;
	void Draw()override;

	void OnHit()override;

	void Shot(Player* player);

private:

	void Release()override;

	Math::Vector2 m_Move;
	float m_BulletSpd = 7.0f;
	Math::Vector2 m_BulletVec;

};