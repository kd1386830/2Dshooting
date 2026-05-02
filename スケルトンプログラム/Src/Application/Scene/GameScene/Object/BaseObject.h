#pragma once

class BaseObject
{
public:

	enum class ObjectType
	{
		None,
		Player,
		Enemy,
		Bullet,
	};


	BaseObject() {}
	virtual ~BaseObject() { Release(); }

	virtual void Init();
	virtual void Update();
	virtual void Draw();

	virtual void OnHit() {}

	ObjectType GetObjType() { return m_ObjType; }
	Math::Vector2 GetPos() { return m_Pos; }
	bool GetAliveFlg() { return m_AliveFlg; }
	float GetRadius() { return m_Radius; }

protected:

	virtual void Release();

	KdTexture m_Tex;		//テクスチャ

	Math::Matrix m_Mat;		//行列
	Math::Vector2 m_Pos;	//座標

	float m_Radius;			//半径

	bool m_AliveFlg;		//生存フラグ

	ObjectType m_ObjType = ObjectType::None;

};