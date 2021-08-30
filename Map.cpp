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
				this->map_array[y][x] = std::make_unique<Rock>(x, y);
			}
			// otherwise its grass
			else
			{
				this->map_array[y][x] = std::make_unique<Grass>(x, y);
			}
		}
	}
}