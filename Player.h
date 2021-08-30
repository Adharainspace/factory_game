#pragma once

#include "Object.h"

class Player : public Object
{
	public:
		Player(int x, int y);
		~Player() override;
};