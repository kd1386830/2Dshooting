#pragma once

class C_Title
{
public:

	C_Title() {}
	~C_Title() {}

	void Init();
	void Update();
	void Draw();

private:


public:

	static C_Title& GetInstans()
	{
		static C_Title instans;
		return instans;
	}

};