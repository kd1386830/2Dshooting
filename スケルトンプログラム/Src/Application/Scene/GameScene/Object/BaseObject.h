#pragma once

class BaseObject
{
public:

	BaseObject() {}
	virtual ~BaseObject() { Release(); }

	virtual void Init();
	virtual void Update();
	virtual void Draw();

protected:

	virtual void Release();

	KdTexture m_Tex;		//テクスチャ

	Math::Matrix m_Mat;		//行列
	Math::Vector2 m_Pos;	//座標

	bool m_AliveFlg;		//生存フラグ

};