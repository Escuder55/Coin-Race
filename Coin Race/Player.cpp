#include "Player.h"
#include<stdlib.h>
#include"Input.h"
#include<iostream>
#include"CoinManager.h"




Player::Player(int x, int y, Map &m):m(m), c(c) 
{
	do {
		x = rand() % m.getColumnas();
		y = rand() % m.getFilas();

	} while (m.getCelda(x, y) != '.');
	m.modifyMap(x, y, '@');
}
void Player::updatePlayer(Input::Key Keypressed,Map &m,CoinManager &c)
{
	switch (Keypressed)
	{
		case Input::Key::W:
				if (y != 0)
				{
					m.modifyMap(x, y, '.');
					y++;
					if (m.getCelda(x, y) == '$')
					{
						PlayerScore++;
						c.decreaseCoin();
					}
					m.modifyMap(x, y, '@');
				}
				else
				{
					std::cout << "You can't do this movement!!" << std::endl;
				}
				break;

		case Input::Key::A:

				if (x != 0)
				{
					m.modifyMap(x, y, '.');
						x--;
					if (m.getCelda(x, y) == '$')
					{
						PlayerScore++;
						c.decreaseCoin();
					}
					m.modifyMap(x, y, '@');
				}
				else
				{
					std::cout << "You can't do this movement!!" << std::endl;
				}
				break;

		case Input::Key::S:

				if (y != m.getFilas())
				{
					m.modifyMap(x, y, '.');
					y--;
					if (m.getCelda(x, y) == '$')
					{
						PlayerScore++;
						c.decreaseCoin();
					}
					m.modifyMap(x, y, '@');
				}
				else
				{
					std::cout << "You can't do this movement!!" << std::endl;
				}
				break;

		case Input::Key::D:

				if (y != m.getColumnas())
				{
					m.modifyMap(x, y, '.');
					x++;
					if (m.getCelda(x, y) == '$')
					{
						PlayerScore++;
						c.decreaseCoin();
					}
					m.modifyMap(x, y, '@');
				}
				else
				{
					std::cout << "You can't do this movement!!" << std::endl;
				}
				break;

		case Input::Key::ESC:
			char answer;
			std::cout << "Are you sure you want to exit the Game? (Y/N)";
			std::cin >> answer >> std::endl;
				if (answer == 'y' || answer == 'Y')
				{
					//AQUI HACER QUE EL JUEGO SALGA DEL GAMELOOP
				}
				if (answer == 'n' || answer == 'N')
				{
					break;
				}
				
	}

}

Player::~Player()
{
	
}
}