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
	void SetOwner(GameScene* owner) { m_Owner = owner; }

private:

	void Release()override;

	GameScene* m_Owner = nullptr;

	const int SCR_L = -640;	//左端
	const int SCR_R = 640;	//右端
	const int SCR_T = 360;	//上端
	const int SCR_B = -360;	//下端

	Math::Vector2 m_Move;		//弾の移動量
	float m_BulletSpd = 10.0f;	//弾のスピード

};