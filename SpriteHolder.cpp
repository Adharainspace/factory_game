#include "SpriteHolder.h"

SpriteHolder::SpriteHolder()
{
	this->spritesheet = this->load_texture("Data/Sprites/spritesheet.png");
	this->sheet_length = (this->spritesheet.getSize().x);

	// setting up index map, sprite name : sprite index
	this->index_map[""] = 0;
	this->index_map["grass"] = 1;
	this->index_map["rock"] = 2;
	this->index_map["robot-right"] = 3;
	this->index_map["robot-left"] = 4;
	this->index_map["robot-down"] = 5;
	this->index_map["robot-up"] = 6;
	this->index_map["iron-ore"] = 7;
	this->index_map["iron-ingot"] = 8;
	// conveyor-west-east
	this->index_map["conveyor-8-2"] = 9;
	// conveyor-east-west
	this->index_map["conveyor-2-8"] = 10;
	// conveyor-north-south
	this->index_map["conveyor-1-4"] = 11;
	// conveyor-south-north
	this->index_map["conveyor-4-1"] = 12;
	// conveyor-north-east
	this->index_map["conveyor-1-2"] = 13;
	// conveyor-north-west
	this->index_map["conveyor-1-8"] = 14;
	// conveyor-south-east
	this->index_map["conveyor-4-2"] = 15;
	// conveyor-south-west
	this->index_map["conveyor-4-8"] = 16;
}

sf::Texture SpriteHolder::load_texture(std::string file_path)
{
	sf::Texture texture;
	if (!texture.loadFromFile(file_path))
	{
		Exception exception("error loading resource " + file_path);
		throw(exception);
	}
	return texture;
}

sf::Sprite SpriteHolder::get_sprite(std::string name)
{
	int index = this->index_map[name];
	// invalid sprite
	if (!index)
	{
		// return missing texture
		return sf::Sprite(this->spritesheet, sf::IntRect(0, 0, SPRITE_SIZE, SPRITE_SIZE));
	}
	int x = (index % (this->sheet_length / SPRITE_SIZE)) * SPRITE_SIZE;
	int y = (index / (this->sheet_length / SPRITE_SIZE)) * SPRITE_SIZE;
	sf::Sprite sprite(this->spritesheet, sf::IntRect(x, y, SPRITE_SIZE, SPRITE_SIZE));
	return sprite;
}

int SpriteHolder::get_sprite_idx(std::string name)
{
	return this->index_map[name];
}