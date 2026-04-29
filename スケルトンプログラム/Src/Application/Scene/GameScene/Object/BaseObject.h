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

	KdTexture m_tex;		//テクスチャ

	Math::Matrix m_mat;		//行列
	Math::Vector2 m_pos;	//座標

	bool m_aliveFlg;		//生存フラグ

};