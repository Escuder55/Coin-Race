#include "Player.h"
#include<stdlib.h>




Player::Player(int x, int y, Map &m) :m(m)
{
	do {
		x = rand() % m.getColumnas();
		y = rand() % m.getFilas();

	} while (m.getCelda(x, y) != '.');
	m.modifyMap(x, y, '@');
}
void movimientoPlayer()
{
	
}

Player::~Player()
{
	
}
