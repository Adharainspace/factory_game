#pragma once

#include "Macros.h"
#include <unordered_map>

/* 
sprites are accessed on an index system.the first sprite is at 0, the 2nd is at 1. right to left, top to bottom
0 1 2
3 4 5
6 7 8
*/

class SpriteHolder
{
	private:
		// spritesheet that holds every sprite used in the game
		sf::Texture spritesheet;
		// width and height are the same so we only need one variable, length of the sprite sheet
		int sheet_length;
		// map of string sprite names : spritesheet index
		std::unordered_map<std::string, int> index_map;
	public:
		// constructor for SpriteHolder class
		SpriteHolder();
		// loads a texture from a file
		sf::Texture load_texture(std::string file_path);
		// returns a sprite in the spritesheet based on supplied index
		sf::Sprite get_sprite(std::string name);
};