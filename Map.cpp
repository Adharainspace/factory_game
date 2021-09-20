#include "Map.h"
#include "Grass.h"
#include "Rock.h"

Map::Map() : 
	map_width(30),
	map_height(20),
	map_array(boost::extents[map_height][map_width])
{
	for (MapIndex y = 0; y < this->map_height; y++)
	{
		for (MapIndex x = 0; x < this->map_width; x++)
		{
			// borders are solid
			if (x == 0 || x == (this->map_width - 1) || y == 0 || y == (this->map_height - 1))
			{
				this->map_array[y][x] = std::make_shared<Rock>(x, y);
			}
			// otherwise its grass
			else
			{
				this->map_array[y][x] = std::make_shared<Grass>(x, y);
			}
		}
	}
}

bool Map::out_of_bounds(int x, int y)
{
	// if outside of map bounds (0->map_width, 0->map_height)
	if ((x > this->map_width - 1) || (x < 0) || (y > this->map_height - 1) || (y < 0))
	{
		return true;
	}
	return false;
}

bool Map::add_object(int x, int y, std::shared_ptr<Object> object)
{
	if (!this->out_of_bounds(x,y))
	{
		// in bounds
		std::shared_ptr<Tile> tile = this->map_array[y][x];
		tile->add_visible_contents(object);
		object->x = tile->x;
		object->y = tile->y;
		return true;
	}
	// out of bounds
	return false;
}

bool Map::remove_object(int x, int y, std::shared_ptr<Object> object)
{
	if (!this->out_of_bounds(x, y))
	{
		// in bounds
		std::shared_ptr<Tile> tile = this->map_array[y][x];
		tile->remove_visible_contents(object);
		object->x = -1;
		object->y = -1;
		return true;
	}
	// out of bounds
	return false;
}

bool Map::move_object(int new_x, int new_y, std::shared_ptr<Object> object)
{
	if (!this->remove_object(object->x, object->y, object))
	{
		// removal failed
		return false;
	}
	if (!this->add_object(new_x, new_y, object))
	{
		// addition failed
		return false;
	}
	return true;
}

std::shared_ptr<Tile> Map::get_tile(int x, int y)
{
	return this->map_array[y][x];
}