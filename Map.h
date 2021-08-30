#pragma once

#include "Macros.h"
#include "boost/multi_array.hpp"
#include "Tile.h"
#include <memory>
typedef boost::multi_array<std::unique_ptr<Tile>, 2> MapArray;
typedef MapArray::index MapIndex;

class Map {
private:
public:
	// width of the game map, in tiles
	int map_width;
	// height of the game map, in tiles
	int map_height;
	// internal array that stores map data
	MapArray map_array;
	// default constructor
	Map();
};