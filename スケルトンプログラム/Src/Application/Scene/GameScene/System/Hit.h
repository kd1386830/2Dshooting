#pragma once

class GameScene;

class Hit
{
public:

	Hit() {}
	~Hit() {}

	bool EnemyToHit(Math::Vector2 pos, float radius);

	void SetOwner(GameScene* owner) { m_Owner = owner; }

private:

	GameScene* m_Owner = nullptr;

public:
	static Hit& Instance()
	{
		static Hit instance;
		return instance;
	}
};