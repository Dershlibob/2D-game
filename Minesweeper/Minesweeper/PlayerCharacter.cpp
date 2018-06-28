#include "PlayerCharacter.h"

void Player::Init()
{
	PlayerController.CreateObject(PlayerShape.SquareVert, sizeof(PlayerShape.SquareVert), PlayerShape.SquareInd, sizeof(PlayerShape.SquareInd), "Assets/Images/wall.jpg", program, 0, 0);
}

void Player::Update()
{


}