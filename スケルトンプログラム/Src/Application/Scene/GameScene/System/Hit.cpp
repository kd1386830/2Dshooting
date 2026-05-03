#include "Hit.h"
#include"../GameScene.h"
#include"../Object/BaseObject.h"

bool Hit::EnemyToHit(Math::Vector2 pos, float radius)
{
	bool Hit = false;

	for (auto& obj : m_Owner->GetObjList())
	{
		if (obj->GetObjType() == BaseObject::ObjectType::Enemy)
		{
			float a = pos.x - obj->GetPos().x;
			float b = pos.y - obj->GetPos().y;

			float c = sqrt(a * a + b * b);

			if (c < radius + obj->GetRadius())
			{
				obj->OnHit();
				Hit = true;
			}
		}
	}

	return Hit;
}
