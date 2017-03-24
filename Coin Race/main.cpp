#include "Player.h"
#include"Map.h"
#include"CoinManager.h"
#include"Input.h"

#include<stdlib.h>
#include<iostream>
#include<ctime>



void main() 
{

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

	for (int i = 0; i < myMap.getFilas(); i++)
	{
		for (int j = 0; j < myMap.getColumnas(); j++)
		{
			std::cout << " " << myMap.getCelda(i, j) << " |";
		}
		std::cout << std::endl;
	}



	/*while (myPlayer.getPlayerScore() < maxScore || exitGame == false)
	{
		for (int i = 0; i < myMap.getFilas(); i++)
		{
			for (int j = 0; j < myMap.getColumnas(); j++)
			{
				std::cout<< " " << myMap.getCelda(i, j) << " |";
			}
			std::cout << std::endl;
		} 
	}*/


	


	
}