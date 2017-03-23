#pragma once
#include"Map.h"
#include "Input.h"
class Player
{
public:

	int X;
	int Y;
	int PlayerScore;
	Map &m;


	Player(int x, int y, Map &m);
	void movimientoPlayer();
	~Player();
};

