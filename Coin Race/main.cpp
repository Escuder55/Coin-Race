#include"Map.h"
#include"Player.h"
#include"CoinManager.h"
#include "Input.h"





void main() 
{

	Input::Key KeyPressed;

	KeyPressed = Input::getKey();
	Player::updatePlayer (KeyPressed);
}