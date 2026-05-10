#pragma once

class GameScene;

class GameOver
{
public:

	GameOver() {}
	~GameOver() {}

	void Init();
	void Update();
	void Draw();
	void Release();

	void SetOwner(GameScene* owner) { m_Owner = owner; }

private:

	GameScene* m_Owner = nullptr;

	KdTexture m_Tex;

	Math::Matrix m_TransMat;
	Math::Matrix m_ScaleMat;
	Math::Matrix m_Mat;

	Math::Vector2 m_Pos;

	float m_Scale = 7;
	float m_Alpha = 0.0f;

	float m_SceneCount = 0.0f;
	bool m_SceneFlg;

	bool m_PlayerDeadFlg = false;
	bool m_ChangeSceneFlg = false;

public:
	static GameOver& Instance()
	{
		static GameOver instance;
		return instance;
	}
};