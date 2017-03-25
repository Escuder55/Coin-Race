#include "Player.h"
#include"Map.h"
#include"CoinManager.h"
#include"Input.h"

#include<stdlib.h>
#include<iostream>
#include<ctime>
#include<cstdlib>
#include<time.h>


void main() 
{
	srand((unsigned int)time((time_t *)NULL));
	int difficulty;
	std::cout << "/////////////////////////////////" << "\n" <<
		"	    COIN RACE" << "\n" <<
		"/////////////////////////////////" << std::endl;
				
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
	clock_t start, end;
	start = clock();

	system("cls");


	std::cout << "/////////////////////////////////" << "\n" <<
		"	    COIN RACE" << "\n" <<
		"/////////////////////////////////" << std::endl;
	

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
				std::cout << "/////////////////////////////////" << "\n" <<
					"	    COIN RACE" << "\n" <<
					"/////////////////////////////////" << std::endl;
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

			if (myPlayer.getPlayerScore() == maxScore)
			{
				end = (clock() - start)/1000;
				system("cls");
				std::cout << "\n" << "\n" << "\n" <<
					"		CONGRATULATIONS YOU HAVE WON!!!!!" << "\n"<< "\n" <<
					"		YOU GOT MAX SCORE " <<maxScore << " IN "<< end << " SECONDS"<<std::endl;
				break;
			}

			if (exitGame == true )
				break;
	}
	/*Map::~Map();
	CoinManager::~CoinManager();
	Player::~myPlayer();*/

}