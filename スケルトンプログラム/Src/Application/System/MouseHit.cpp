#include "MouseHit.h"
#include"Mouse.h"

bool MouseHit::UIMouseHit(Math::Vector2 pos, Math::Vector2 radius, float scale)
{
	const float StartRight = pos.x + (radius.x * scale);
	const float StartLeft = pos.x - (radius.x * scale);
	const float StartTop = pos.y + (radius.y * scale);
	const float StartBottom = pos.y - (radius.y * scale);

	const float x = Mouse::Instance().GetMousePos().x;
	const float y = Mouse::Instance().GetMousePos().y;

	if (x< StartRight && x>StartLeft && y< StartTop && y>StartBottom)
	{
		return true;
	}
	else
	{
		return false;
	}
}
