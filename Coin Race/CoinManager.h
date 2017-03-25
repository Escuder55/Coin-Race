#pragma once
#include"Map.h"
#include<stdlib.h>

class CoinManager
{
private:
	int mapCoins;
	Map &m;

public:

	CoinManager(int dificultad, Map &m);
	void inicializeCoin();
	void decreaseCoin();
	~CoinManager();
};

