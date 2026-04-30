#pragma once
#include"../BaseObject.h"

class Player;

class Enemy :public BaseObject
{
public:

	Enemy() {}
	~Enemy()override { Release(); }

	void Init()override;
	void Update()override;
	void Draw()override;

	void EnemySpawn();			//敵を画面外のランダムな場所に出す処理
	void ChasePlayer();			//プレイヤーの方向に進む速度を決める処理

	void SetTarget(Player* player) { m_player = player; }	//追尾対象の座標を取得
	void SetAliveFlg(bool flg) { m_AliveFlg = flg; }
	bool GetAliveFlg()			{ return m_AliveFlg; }

	Math::Vector2 GetPos() { return m_Pos; }

private:

	void Release()override;

	Player* m_player = nullptr;

	float m_EnemySpd = 3.0f;	//敵の移動スピード
	Math::Vector2 m_EnemyVec;	//移動速度ベクトル

	Math::Vector2 m_TargetPos;	//追尾対象の座標


};