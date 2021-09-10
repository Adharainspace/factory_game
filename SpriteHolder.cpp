#include "SpriteHolder.h"

SpriteHolder::SpriteHolder()
{
	this->spritesheet = this->load_texture("Data/Sprites/spritesheet.png");
	this->sheet_length = (this->spritesheet.getSize().x);

	// setting up sprite name : sprite index map
	this->index_map[""] = 0;
	this->index_map["grass"] = 1;
	this->index_map["rock"] = 2;
	this->index_map["robot-right"] = 3;
	this->index_map["robot-left"] = 4;
	this->index_map["robot-down"] = 5;
	this->index_map["robot-up"] = 6;
	this->index_map["iron-ore"] = 7;
	this->index_map["iron-ingot"] = 8;
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
	int x = (index % (this->sheet_length / SPRITE_SIZE)) * SPRITE_SIZE;
	int y = (index / (this->sheet_length / SPRITE_SIZE)) * SPRITE_SIZE;
	sf::Sprite sprite(this->spritesheet, sf::IntRect(x, y, SPRITE_SIZE, SPRITE_SIZE));
	return sprite;
}

int SpriteHolder::get_sprite_idx(std::string name)
{
	return this->index_map[name];
}