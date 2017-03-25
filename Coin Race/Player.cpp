#include "Player.h"
#include<stdlib.h>
#include"Input.h"
#include<iostream>
#include"CoinManager.h"
#include"Map.h"




Player::Player(Map &m, CoinManager &c):m(m), c(c) 
{
	PlayerScore = 0;
	do {
		x = rand() % m.getColumnas();
		y = rand() % m.getFilas();

	} while (m.getCelda(x, y) != '.');
	m.modifyMap(x, y, '@');
}
bool Player::updatePlayer(Input::Key Keypressed,Map &m,CoinManager &c)
{
	bool exit = false;
	switch (Keypressed)
	{
		case Input::Key::W:
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

		case Input::Key::A:

				if (y != 0)
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

		case Input::Key::S:

				if (x != m.getFilas()-1)
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

		case Input::Key::D:

				if (y != m.getColumnas()-1)
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

		case Input::Key::ESC:
			char answer;
			std::cout << "Are you sure you want to exit the Game? (Y/N)";
			std::cin >> answer ;
				if (answer == 'y' || answer == 'Y')
				{
					exit = true;
				}
				if (answer == 'n' || answer == 'N')
				{
					break;
				}
				
	}
	return exit;

}

int Player::getPlayerScore()
{
	return PlayerScore;
}

Player::~Player()
{

}
