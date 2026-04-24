#pragma once

class C_State
{
public:

	C_State() {}
	~C_State() {}

	virtual void Init();
	virtual void Update();
	virtual void Draw();

};