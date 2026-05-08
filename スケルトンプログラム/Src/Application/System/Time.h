#pragma once

struct TimeUI
{
	Math::Matrix m_TransMat;
	Math::Matrix m_ScaleMat;
	Math::Matrix m_Mat;
	Math::Vector2 m_Pos;
	float m_Scale;
};

class GameScene;

class Time
{
public:

	Time() {}
	~Time() { m_Tex.Release(); }
	
	void Init();
	void Update();
	void Draw();
	void Release();

	void PosScaleSet(bool flg);
	void StaartCountDown(float time);

	int GetAliveTime() { return m_TotalSec; }
	bool GetStartFlg() { return m_GameStartFlg; }
	bool GetOverFlg() { return m_GameOverFlg; }

	void SetOwner(GameScene* owner) { m_Owner = owner; }

private:

	GameScene* m_Owner = nullptr;

	KdTexture m_Tex;
	KdTexture m_ColonTex;

	TimeUI m_CountDownUI;

	TimeUI m_AliveMinTenUI;
	TimeUI m_AliveMinOneUI;
	TimeUI m_AliveSecTenUI;
	TimeUI m_AliveSecOneUI;

	TimeUI m_ColonUI;

	int m_CountDown = 0;			//カウントダウンタイマー
	int m_CountUp = 0;				//カウントアップタイマー

	bool m_GameStartFlg = false;	//ゲーム開始フラグ
	bool m_GameOverFlg = false;		//ゲームオーバーフラグ

	int m_TotalSec = 0;				//全体の秒数
	int m_Minutes = 0;				//分
	int m_Seconds = 0;				//秒
	int m_MinTens = 0;				//分の十の位
	int m_MinOnes = 0;				//分の一の位
	int m_SecTens = 0;				//秒の十の位
	int	m_SecOnes = 0;				//秒の一の位

	float alpha = 0.3f;

public:
	static Time& Instance()
	{
		static Time instance;
		return instance;
	}
};