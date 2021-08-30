#pragma once

#include "Macros.h"

#include "Tile.h"

class Grass : public Tile
{
	public:
		Grass(int x, int y);
		~Grass() override;
};