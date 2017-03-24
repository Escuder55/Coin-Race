#pragma once
#include "Player.h"
#include<stdlib.h>
#include"Input.h"
#include<iostream>
#include"CoinManager.h"
class Player
{
private:

	int x;
	int y;
	int PlayerScore;
	Map &m;
	CoinManager &c;

public:


	Player(int x, int y, Map &m,CoinManager &c);
	void updatePlayer(Input::Key Keypressed, Map &m, CoinManager &c);
	~Player();
};

