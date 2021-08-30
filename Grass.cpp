#include "Grass.h"

Grass::Grass(int x, int y) : 
	Tile::Tile(false, "grass", LAYER_GROUND, x, y)
{}

Grass::~Grass()
{}