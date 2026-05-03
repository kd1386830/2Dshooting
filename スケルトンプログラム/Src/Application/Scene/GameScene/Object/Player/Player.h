#pragma once
#include"../BaseObject.h"

class GameScene;

class Player :public BaseObject
{
public:

	Player() {}
	~Player()override { Release(); }

	void Init()override;
	void Update()override;
	void Draw()override;

	void OnHit()override;

	void PlayerMove();		//移動処理
	void PlayerRotation();	//回転処理

	float GetAngle() { return m_Angle; }

	void SetOwner(GameScene* owner) { m_Owner = owner; }

private:

	void Release()override;

	GameScene* m_Owner = nullptr;

	Math::Matrix m_TransMat;	//移動行列
	Math::Matrix m_RotateMat;	//回転行列

	Math::Vector2 m_MoveVec;	//移動速度ベクトル
	float m_MoveSpd = 5.0f;		//移動スピード

	float m_Angle;				//角度

	int m_ShotWait = 0;			//弾の発射間隔

};