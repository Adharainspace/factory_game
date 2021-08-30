#include "Tile.h"

Tile::Tile() : 
	Object::Object()
{}

Tile::Tile(std::string sprite_name, int x, int y) :
	Object::Object(sprite_name, x, y)
{}

Tile::Tile(bool density, std::string sprite_name, int layer, int x, int y) :
	Object::Object(density, sprite_name, layer, x, y)
{}

Tile::~Tile()
{}

void Tile::add_contents(std::shared_ptr<Object> object)
{
	this->contents.push_back(object);
}

void Tile::remove_contents(std::shared_ptr<Object> object)
{
	for (unsigned int i = 0; i < this->contents.size(); i++)
	{
		std::shared_ptr<Object> candidate = this->contents[i];
		if (candidate.get() == object.get())
		{
			this->contents.erase(this->contents.begin() + i);
		}
	}
}

void Tile::add_visible_contents(std::shared_ptr<Object> object)
{
	this->visible_contents.push_back(object);
}

void Tile::remove_visible_contents(std::shared_ptr<Object> object)
{
	for (unsigned int i = 0; i < this->visible_contents.size(); i++)
	{
		std::shared_ptr<Object> candidate = this->visible_contents[i];
		if (candidate.get() == object.get())
		{
			this->visible_contents.erase(this->visible_contents.begin() + i);
		}
	}
}