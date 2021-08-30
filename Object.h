#pragma once

#include "Macros.h"

class Object {
	protected:

	public:
		// whether or not an object can be moved through
		bool density;
		// the index in the spritesheet for the sprite of an object
		std::string sprite_name;
		// the layer that an object is on - higher layers renders above lower layers, definitions in "Macros.h"
		int layer;
		// x coordinate on the map
		int x;
		// y coordinate on the map
		int y;
		// pixel offset in x axis of sprite
		int pixel_x;
		// pixel offset in y axis of sprite
		int pixel_y;
		
		Object();
		Object(std::string sprite_name, int x, int y);
		Object(bool density, std::string sprite_name, int layer, int x, int y);
		virtual ~Object();
};