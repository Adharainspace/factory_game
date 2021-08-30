#pragma once

#include "Macros.h"

#include "Tile.h"

class Rock : public Tile
{
	public:
		Rock(int x, int y);
		~Rock() override;
};