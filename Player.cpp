#include "Player.h"

Player::Player(int x, int y) : 
	Object::Object(true, "robot-right", LAYER_PLAYER, x, y)
{}

Player::~Player()
{}