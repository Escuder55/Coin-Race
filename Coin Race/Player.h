#pragma once
#include "Player.h"
#include<stdlib.h>
#include"Input.h"
#include<iostream>
#include"CoinManager.h"
#include"Map.h"
class Player
{
private:

	int x;
	int y;
	int PlayerScore;
	Map &m;
	CoinManager &c;

public:


	Player(Map &m,CoinManager &c);
	bool updatePlayer(Input::Key Keypressed, Map &m, CoinManager &c);
	int getPlayerScore();
	~Player();
};

