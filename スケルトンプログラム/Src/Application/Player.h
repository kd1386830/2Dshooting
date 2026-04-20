#pragma once

class C_Player
{
public:

	C_Player();
	~C_Player();

	void Init();
	void Update();
	void Draw();

	void PlayerMove();		//©‹@‚ÌˆÚ“®
	void PlayerRotate();	//©‹@‚Ì‰ñ“]

	Math::Vector2 GetPlayerPos() { return m_PlayerPos; }
	float GetAngle() { return m_PlayerAngle; }
	bool GetShotFlg() { return m_ShotFlg; }

private:

	KdTexture m_PlayerTex;

	Math::Matrix m_PlayerScaleMat;	//Šgk
	Math::Matrix m_PlayerTransMat;	//ˆÚ“®
	Math::Matrix m_PlayerRotateMat;	//‰ñ“]
	Math::Matrix m_PlayerMat;		//s—ñ

	Math::Vector2 m_PlayerPos;		//©‹@À•W

	float m_PlayerMove;				//ˆÚ“®—Ê
	float m_PlayerSize;				//Šg‘å—¦
	float m_PlayerAngle;			//Šp“x
	bool m_ShotFlg;					//”­Ë‚µ‚½‚©
};