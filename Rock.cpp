#include "Rock.h"

Rock::Rock(int x, int y) :
	Tile::Tile(true, "rock", LAYER_GROUND, x, y)
{}

Rock::~Rock()
{}