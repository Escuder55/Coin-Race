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
	mapCoins = ((3 + rand()%10))*( m.getFilas() * m.getColumnas())/100;
	//mapCoins = 10;
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
int CoinManager::getMapCoins()
{
	return mapCoins;
}


CoinManager::~CoinManager()
{
}
