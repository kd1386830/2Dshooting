#pragma once

class C_Player
{
public:

	C_Player();
	~C_Player();

		void Init();
		void Update();
		void Draw();

		void PlayerMove();
		void PlayerRotation();

		Math::Vector2 GetPlayerPos() { return m_PlayerPos; }
		float GetAngle() { return m_PlayerAngle; }

private:

	KdTexture m_PlayerTex;

	Math::Matrix m_PlayerScaleMat;	//拡縮
	Math::Matrix m_PlayerTransMat;	//移動
	Math::Matrix m_PlayerRotateMat;	//回転
	Math::Matrix m_PlayerMat;		//行列

	Math::Vector2 m_PlayerPos;		//自機座標

	float m_PlayerMove;				//移動量
	float m_PlayerSize;				//拡大率
	float m_PlayerAngle;			//角度

public:
	static C_Player& GetInstance()
	{
		static C_Player instance;
		return instance;
	}
};