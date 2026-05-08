#pragma once
#include"../BaseObject.h"

class GameScene;

class Item:public BaseObject
{
public:

	enum class ItemType
	{
		spdUp,
		ShotSpdUp,
	};

	Item() {}
	~Item() {}

	void Init()override;
	void Update()override;
	void Draw()override;
	void Release()override;

	void OnHit();

	void Move();
	void ItemSpawn();
	void ScrOutCheck();

	void ItemTypeSet();

	ItemType GetItemType() { return m_Type; }

	void SetOwner(GameScene* owner) { m_Owner = owner; }

private:

	GameScene* m_Owner = nullptr;

	ItemType m_Type;

	const float offSet = 50.0f;

	Math::Matrix m_TransMat;
	Math::Matrix m_ScaleMat;

	Math::Vector2 m_TargetPos;
	Math::Vector2 m_vec;

	float m_Speed = 4.0f;
	float m_Scale = 3.0f;

};