#pragma once
#include"State.h"
#include"Title.h"

class C_TitleScene :public C_State
{
public:

	C_TitleScene();
	~C_TitleScene();

	void Init()override;
	void Update()override;
	void Draw()override;


private:

	C_Title m_title;

};