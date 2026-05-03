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

	const int SCR_L = -640;	//左端
	const int SCR_R = 640;	//右端
	const int SCR_T = 360;	//上端
	const int SCR_B = -360;	//下端

	Math::Vector2 m_Move;		//弾の移動量
	float m_BulletSpd = 7.0f;	//弾のスピード

};