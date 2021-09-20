#include "Machine.h"

Machine::Machine() :
	Object::Object()
{
	this->tick_delay = 0;
	this->current_delay = 0;
}

Machine::Machine(std::string sprite_name, std::string id,  int x, int y, int tick_delay) :
	Object::Object(sprite_name, id, x, y)
{
	this->tick_delay = tick_delay;
	this->current_delay = 0;
}

Machine::Machine(bool density, std::string sprite_name, std::string id, int layer, int x, int y, int tick_delay) : 
	Object::Object(density, sprite_name, id, layer, x, y)
{
	this->tick_delay = tick_delay;
	this->current_delay = 0;
}

Machine::~Machine()
{}

void Machine::update_delay()
{
	if (this->current_delay == 0)
	{
		this->update_state();
		this->current_delay = this->tick_delay;
		return;
	}
	this->current_delay--;
}

void Machine::update_state()
{}

void Machine::add_contents(std::shared_ptr<Object> object)
{
	this->contents.push_back(object);
}

void Machine::remove_contents(std::shared_ptr<Object> object)
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

void Machine::add_visible_contents(std::shared_ptr<Object> object)
{
	this->visible_contents.push_back(object);
	this->sort_visible_contents();
}

void Machine::remove_visible_contents(std::shared_ptr<Object> object)
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

void Machine::sort_visible_contents()
{
	std::sort(this->visible_contents.begin(), this->visible_contents.end(),
		[](std::shared_ptr<Object> a, std::shared_ptr<Object> b) {return a->layer < b->layer; });
}