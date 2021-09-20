#include "Conveyor.h"

Conveyor::Conveyor(int x, int y, int update_delay, uint8_t start_direction, uint8_t end_direction) :
	Machine::Machine(false, "conveyor-west-east", "conveyor", LAYER_MACHINE_ON_GROUND, x, y, update_delay)
{
	this->start_direction = start_direction;
	this->end_direction = end_direction;
}

Conveyor::~Conveyor()
{}

void Conveyor::update_state()
{
	// get offsets for where to move stuff
	std::pair<int, int> offsets = direction_offsets(this->end_direction);
	int new_x = this->x + offsets.first;
	int new_y = this->y + offsets.second;
	std::shared_ptr<Object> conveyor_ptr = this->map->get_tile(new_x, new_y)->find_object("conveyor");

	for (std::shared_ptr<Object> object : this->visible_contents)
	{
		this->map->get_tile(this->x, this->y)->remove_visible_contents(object);
		if (conveyor_ptr)
		{
			// stop the ptr from going out of scope immediately
			std::shared_ptr<Object> conveyor_ptr = this->map->get_tile(new_x, new_y)->find_object("Conveyor");
			// cast it to a conveyor pointer
			Conveyor* raw_ptr = dynamic_cast<Conveyor*>(conveyor_ptr.get());
			// add it to the fucken contents
			raw_ptr->add_visible_contents(object);
			object->x = raw_ptr->x;
			object->y = raw_ptr->y;
			// maybe avoid memory leak by doing this?? :3
			raw_ptr = nullptr;
		}
		else
		{
			this->map->move_object(new_x, new_y, object);
		}
	}
}

void Conveyor::set_direction(uint8_t start, uint8_t end)
{
	this->start_direction = start;
	this->end_direction = end;
	this->sprite_name = std::string("conveyor-").append(std::to_string(start).append("").append(std::to_string(end)));
} 