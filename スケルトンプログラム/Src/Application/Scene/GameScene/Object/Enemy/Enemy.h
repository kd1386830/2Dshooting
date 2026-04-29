#pragma once
#include"../BaseObject.h"

class Enemy :public BaseObject
{
public:

	Enemy() {}
	~Enemy()override { Release(); }

	void Init()override;
	void Update()override;
	void Draw()override;

private:

	void Release()override;


};