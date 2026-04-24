#pragma once

const int SCREEN_LEFT = -640;	//左端
const int SCREEN_RIGHT = 640;	//右端
const int SCREEN_TOP = 360;		//上端
const int SCREEN_BOTTOM = -360;	//下端

class C_PlayerBullet
{
public:

	C_PlayerBullet();
	~C_PlayerBullet();

	void Init();
	void Update();
	void Draw();

	void shot();

private:

	static const int BulletNum = 100;		//弾の総数

	KdTexture m_PBulletTex;

	Math::Matrix m_PBulletMat[BulletNum];	//弾の行列
	Math::Vector2 m_PBulletPos[BulletNum];	//弾の座標

	bool m_PBulletFlg[BulletNum];			//弾の生存フラグ
	float m_PBulletMoveX[BulletNum];		//弾の移動量
	float m_PBulletMoveY[BulletNum];		//弾の移動量
	float m_PBulletSpeed;					//弾の速度

public:
	static C_PlayerBullet& GetInstance()
	{
		static C_PlayerBullet instance;
		return instance;
	}
};