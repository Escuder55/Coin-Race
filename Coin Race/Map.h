#pragma once
#include<stdlib.h>
class Map
{

public:
	char **mapa;
	int filas;
	int columnas;



	Map(int dificultat);

	void modifyMap(int X, int Y, char C);
	int getFilas(void);
	int getColumnas(void);
	char getCelda(int x, int y);


	

	~Map();
};

