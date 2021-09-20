#include "Tile.h"

Tile::Tile() : 
	Object::Object()
{
	this->contents = std::vector<std::shared_ptr<Object>>();
	this->visible_contents = std::vector<std::shared_ptr<Object>>();
	this->conveyor_ptr = nullptr;
}

Tile::Tile(std::string sprite_name, int x, int y) :
	Object::Object(sprite_name, "tile", x, y)
{
	this->contents = std::vector<std::shared_ptr<Object>>();
	this->visible_contents = std::vector<std::shared_ptr<Object>>();
	this->conveyor_ptr = nullptr;
}

Tile::Tile(bool density, std::string sprite_name, int layer, int x, int y) :
	Object::Object(density, sprite_name, "tile", layer, x, y)
{
	this->contents = std::vector<std::shared_ptr<Object>>();
	this->visible_contents = std::vector<std::shared_ptr<Object>>();
	this->conveyor_ptr = nullptr;
}

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
	if (this->conveyor_ptr)
	{
		// cast object ptr to a conveyor pointer
		Conveyor* raw_ptr = dynamic_cast<Conveyor*>(conveyor_ptr.get());
		// add it to the fucken contents
		raw_ptr->add_visible_contents(object);
		object->x = raw_ptr->x;
		object->y = raw_ptr->y;
	}
	else
	{
		this->visible_contents.push_back(object);
	}
	this->sort_visible_contents();
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

bool Tile::check_density()
{
	// dense tile?
	if (this->density == true)
		return true;

	// check tile contents
	for (std::shared_ptr<Object> object : this->visible_contents)
	{
		if (object->density)
		{
			// dense
			return true;
		}
	}

	// not dense
	return false;
}

std::shared_ptr<Object> Tile::find_object(std::string object_id)
{
	for (std::shared_ptr<Object> object : this->visible_contents)
	{
		if (object->id == object_id)
		{
			return object;
		}
	}
	return nullptr;
}

int Tile::find_object_idx(std::string object_id)
{
	for (unsigned int i = 0; i < this->visible_contents.size(); i++)
	{
		if (this->visible_contents[i]->id == object_id)
		{
			return i;
		}
	}
	return -1;
}

void Tile::sort_visible_contents()
{
	std::sort(this->visible_contents.begin(), this->visible_contents.end(),
	[](std::shared_ptr<Object> a, std::shared_ptr<Object> b) {return a->layer < b->layer; });
}