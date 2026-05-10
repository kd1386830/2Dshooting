#pragma once
#include"../BaseObject.h"
#include"../../../SceneManager.h"

class GameScene;
class Item;

class Player :public BaseObject
{
public:

	Player() {}
	~Player()override { Release(); }

	void Init()override;
	void Update()override;
	void Draw()override;

	void OnHit()override;
	void ItemHit(Item* item);

	void PlayerMove();		//移動処理
	void PlayerRotation();	//回転処理
	void PlayerScreenLimit();

	float GetAngle() { return m_Angle; }
	float GetItemActiveTime() { return m_ItemActiveTime; }

	void SetShotWaitTime(int time) { m_shotWaitTime = time; }
	void SetSpeed(float speed) { m_MoveSpd = speed; }

	void SetOwner(GameScene* owner) { m_Owner = owner; }

private:

	void Release()override;

	GameScene* m_Owner = nullptr;

	Math::Matrix m_TransMat;	//移動行列
	Math::Matrix m_ScaleMat;	//拡縮行列
	Math::Matrix m_RotateMat;	//回転行列

	Math::Vector2 m_MoveVec;	//移動速度ベクトル
	float m_MoveSpd = 5.0f;		//移動スピード

	float m_Angle;				//角度
	float m_Scale;				//拡大率

	int m_ShotWait = 0;			
	int m_shotWaitTime = 15;	//弾の発射間隔

	float m_ItemActiveTime = 5.0f * 60.0f;
	bool m_ItemActiveFlg = false;

};