#pragma once
#include"../BaseObject.h"

class Player;

class Bullet :public BaseObject
{
public:

	Bullet() {}
	~Bullet()override { Release(); }

	void Init()override;
	void Update()override;
	void Draw()override;

	void Shot();

	void SetPlayer(Player* player) { m_player = player; }

private:

	void Release()override;

	Player* m_player = nullptr;

	static const int BulletNum = 100;

	Math::Vector2 m_Pos[BulletNum];
	Math::Matrix m_Mat[BulletNum];
	bool m_AliveFlg[BulletNum];

	Math::Vector2 m_Move[BulletNum];
	float m_BulletSpd = 7.0f;
	Math::Vector2 m_BulletVec;

	int ShotWait = 0;


};