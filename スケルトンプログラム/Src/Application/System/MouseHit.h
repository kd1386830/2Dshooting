#pragma once

class MouseHit
{
public:

	MouseHit() {}
	~MouseHit() {}

	bool UIMouseHit(Math::Vector2 pos,Math::Vector2 radius,float scale);

private:



public:
	static MouseHit& Instance()
	{
		static MouseHit instance;
		return instance;
	}
};