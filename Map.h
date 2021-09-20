#pragma once
#include "Macros.h"
#include "boost/multi_array.hpp"
#include "Tile.h"
#include <memory>
typedef boost::multi_array<std::shared_ptr<Tile>, 2> MapArray;
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
	// returns true if x,y is out of the bounds of the map
	bool out_of_bounds(int x, int y);
	// places an object in the map at x, y
	bool add_object(int x, int y, std::shared_ptr<Object> object);
	// removes an object in the map from x, y
	bool remove_object(int x, int y, std::shared_ptr<Object> object);
	// moves an object from its current tile to the tile at x ,y
	bool move_object(int new_x, int new_y, std::shared_ptr<Object> object);
	// returns a shared pointer to the tile at x, y
	std::shared_ptr<Tile> get_tile(int x, int y);
};