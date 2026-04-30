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

	void PlayerMove();		//移動処理
	void PlayerRotation();	//回転処理

	Math::Vector2 GetPlayerPos() { return m_Pos; }
	float GetAngle() { return m_Angle; }

private:

	void Release()override;

	Math::Matrix m_TransMat;	//移動行列
	Math::Matrix m_RotateMat;	//回転行列

	Math::Vector2 m_MoveVec;	//移動速度ベクトル
	float m_MoveSpd = 5.0f;		//移動スピード

	float m_Angle;				//角度

};