#pragma once

class BaseObject;

class Hit
{
public:

	Hit() {}
	~Hit() {}

	bool ObjectHit(BaseObject* a, BaseObject* b);

private:


public:
	static Hit& Instance()
	{
		static Hit instance;
		return instance;
	}
};