#pragma once
#include"../BaseObject.h"

class Player;
class Item;

class Sparkle :public BaseObject
{
public:

	Sparkle() {}
	~Sparkle() {}

	void Init(Player* player,Item* item);
	void Update()override;
	void Draw()override;
	void Release()override;


private:

	Player* m_Player = nullptr;
	Item* m_Item = nullptr;

	Math::Matrix m_TransMat;
	Math::Matrix m_ScaleMat;

	Math::Color m_Color;

	float m_Scale;

	float m_AnimCnt;

};