#pragma once

class Hit
{
public:

	Hit() {}
	~Hit() {}

	bool ObjectHit(Math::Vector2 pos1, Math::Vector2 pos2, float h1, float h2);

private:


public:
	static Hit& Instance()
	{
		static Hit instance;
		return instance;
	}
};