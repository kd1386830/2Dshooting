#include "Hit.h"

bool Hit::ObjectHit(Math::Vector2 pos1, Math::Vector2 pos2, float h1, float h2)
{
	float a = pos1.x - pos2.x;
	float b = pos1.y - pos2.y;

	float c = sqrt(a * a + b * b);

	if (c < h1 + h2)
	{
		return true;
	}
	else
	{
		return false;
	}
}
