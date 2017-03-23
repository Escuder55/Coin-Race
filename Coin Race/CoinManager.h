#pragma once
#include"Map.h"

class CoinManager
{
private:
	int mapCoins;
	Map &m;

public:

	CoinManager(int dificultad, Map &m);
	void inicializeCoin();
	~CoinManager();
};

