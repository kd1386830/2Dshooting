#pragma once
#include"../BaseObject.h"

class Player;
class GameScene;

class Enemy :public BaseObject
{
public:

	Enemy() {}
	~Enemy()override { Release(); }

	void Init()override;
	void Update()override;
	void Draw()override;

	void OnHit()override;

	void EnemySpawn();			//敵を画面外のランダムな場所に出す処理
	void ChasePlayer();			//プレイヤーの方向に進む速度を決める処理

	void SetAliveFlg(bool flg) { m_AliveFlg = flg; }

	void SetOwner(GameScene* owner) { m_Owner = owner; }

private:

	void Release()override;

	GameScene* m_Owner = nullptr;

	float m_EnemySpd = 3.0f;	//敵の移動スピード
	Math::Vector2 m_EnemyVec;	//移動速度ベクトル

};