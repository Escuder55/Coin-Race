#include "Map.h"
#include<stdlib.h>


Map::Map(int dificultad)
{
	filas = ((5 * dificultad + rand() % 5 * dificultad));
	columnas = ((5 * dificultad + rand() % 5 * dificultad));

	mapa = new char *[filas];

	for (int i = 0; i < filas; i++)
	{
		mapa[i] = new char[columnas];
	}

	for (int i = 0; i < filas; i++)
	{
		for (int j = 0; j < columnas; j++)
		{
			mapa[i][j] = '.';
		}
	}
}
int Map::getFilas(void)
{
	return filas;
}
int Map::getColumnas(void)
{
	return columnas;
}

void Map::modifyMap(int X, int Y, char C)
{
	mapa[X][Y] = C;
}

char Map::getCelda(int x, int y)
{
	return mapa[x][y];
}


Map::~Map()
{
	for (int i = 0; i < filas; i++)
	{
		delete[] mapa[i];
	}
	delete[] mapa;
	mapa = nullptr;

}
