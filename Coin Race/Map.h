#pragma once
class Map
{
private:

	char **mapa;
	int filas;
	int columnas;

public:

	Map(int dificultat);

	void modifyMap(int X, int Y, char C);
	int getFilas(void);
	int getColumnas(void);
	char getCelda(int x, int y);


	

	~Map();
};

