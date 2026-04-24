#pragma once

class C_Enemy
{
public:

	C_Enemy();
	~C_Enemy();

	void Init();
	void Update();
	void Draw();


private:

	static const int EnemyNum = 10;

	KdTexture m_EnemyTex;

	Math::Matrix m_EnemyMat[EnemyNum];

	Math::Vector2 m_EnemyPos[EnemyNum];

	bool m_EnemyAliveFlg[EnemyNum];

public:
	static C_Enemy& GetInstance()
	{
		static C_Enemy instance;
		return instance;
	}
};