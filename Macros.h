#pragma once

// SFML Libraries
#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>
#include <SFML\Window.hpp>
#include <SFML\Audio.hpp>
#include <SFML\Network.hpp>

// exception handling
#include "Exception.cpp"

// layer definitions
const int LAYER_GROUND = 1;
const int LAYER_MACHINE_ON_GROUND = 2;
const int LAYER_OBJECT_ON_GROUND = 3;
const int LAYER_PLAYER = 4;

// rendering definitions
const int FRAME_CAP = 60;
const int GLOBAL_RENDER_SCALING = 4;
const int SPRITE_SIZE = 8;

// game window defintions
const int WINDOW_WIDTH = 640;
const int WINDOW_HEIGHT = 480;

// direction definitions
const uint8_t NORTH = (1 << 0);
const uint8_t EAST = (1 << 1);
const uint8_t SOUTH = (1 << 2);
const uint8_t WEST = (1 << 3);
const uint8_t NORTHEAST = (NORTH | EAST);
const uint8_t SOUTHEAST = (SOUTH | EAST);
const uint8_t SOUTHWEST = (SOUTH | WEST);
const uint8_t NORTHWEST = (NORTH | WEST);

// returns a pair of x/y offsets used for relative positioning. first is x offset, second is y offset
inline std::pair<int, int> direction_offsets(uint8_t dir)
{
	std::pair<int, int> offsets;
	offsets.first = (dir & EAST ? 1 : 0) + (dir & WEST ? -1 : 0);
	offsets.second = (dir & NORTH ? 1 : 0) + (dir & SOUTH ? -1 : 0);
	return offsets;
}
