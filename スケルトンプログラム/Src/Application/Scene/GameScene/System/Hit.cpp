#include "Hit.h"
#include"../GameScene.h"
#include"../Object/BaseObject.h"

bool Hit::ObjectHit(BaseObject* a, BaseObject* b)
{
	Math::Vector2 d = a->GetPos() - b->GetPos();

	float distSqrt = d.LengthSquared();
	float r = a->GetRadius() + b->GetRadius();

	return distSqrt < r * r;
}
