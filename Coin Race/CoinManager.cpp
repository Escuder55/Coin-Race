#include "CoinManager.h"
#include<stdlib.h>
#include"Map.h"


CoinManager::CoinManager(int dificultad, Map &m) :m(m)
{
	inicializeCoin();
}
void CoinManager::inicializeCoin()
{
	int x, y;
	mapCoins = (int)((3 + rand()%10)/100)*( m.getFilas() * m.getColumnas()) ;
	//mapCoins = (rand() % 10) + 3;
	for (int i = 0; i < mapCoins; i++)
	{
		do {
			x = rand() % m.getColumnas();
			y = rand() % m.getFilas();
			
		} while (m.getCelda(x,y) != '.');
		m.modifyMap(x, y, '$');

	}
}

void CoinManager::decreaseCoin()
{
	mapCoins--;
	if (mapCoins == 0)
	{
		inicializeCoin();
	}
}


CoinManager::~CoinManager()
{
}
