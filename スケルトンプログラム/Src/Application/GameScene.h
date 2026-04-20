#pragma once
#include"State.h"
#include"Player.h"
#include"PlayerBullet.h"

class C_GameScene:public C_State
{
public:

	C_GameScene();
	~C_GameScene();

	void Init()override;
	void Update()override;
	void Draw()override;


private:

	C_Player m_player;
	C_PlayerBullet m_Pbullet;

};