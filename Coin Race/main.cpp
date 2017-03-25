#include "Player.h"
#include"Map.h"
#include"CoinManager.h"
#include"Input.h"

#include<stdlib.h>
#include<iostream>
#include<ctime>
#include<cstdlib>


void main() 
{
	srand((unsigned int)time((time_t *)NULL));
	int difficulty;
	
	std::cout << " CHOOSE YOUR DIFFICULTY: \n" <<"\n" <<
					"	1.EASY			" << "\n" << "\n" <<
					"	2.MEDIUM		" << "\n" << "\n" <<
					"	3.HARD			" << std::endl;
	std::cin >> difficulty;
	Map myMap(difficulty);
	CoinManager myCoin(difficulty, myMap);
	Player myPlayer(myMap, myCoin);
	
	int maxScore = ((30 * difficulty + rand() % 30 * difficulty));
	Input::Key keyPressed;
	bool exitGame = false;

	system("cls");
	
	std::cout << myCoin.getMapCoins() << std::endl;

	for (int i = 0; i < myMap.getFilas(); i++)
	{
		for (int j = 0; j < myMap.getColumnas(); j++)
		{
			std::cout << " " << myMap.getCelda(i, j) << " |";
		}
		std::cout << std::endl;
	}
	std::cout << "\n" << "\n" << "SCORE:  " << myPlayer.getPlayerScore() << "\n" << "MAX SCORE: "
		<< maxScore << std::endl;

	


	while (myPlayer.getPlayerScore() < maxScore || exitGame == false)
	{
		keyPressed = Input::getKey();
		exitGame = myPlayer.updatePlayer(keyPressed, myMap, myCoin);
		

			if (keyPressed != Input::Key::NONE)
			{
				system("cls");
				for (int i = 0; i < myMap.getFilas(); i++)
				{
					for (int j = 0; j < myMap.getColumnas(); j++)
					{
						std::cout << " " << myMap.getCelda(i, j) << " |";
					}
					std::cout << std::endl;
				}
				std::cout << "\n" << "\n" << "SCORE:  " << myPlayer.getPlayerScore() <<"\n"<<"MAX SCORE: " 
					<< maxScore << std::endl;
			}
	}


	
}