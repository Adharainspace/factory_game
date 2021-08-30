#pragma once

#include "macros.h"

class Camera
{
	private:
	public:
		// reference to the x coordinate of the map location of the top left corner of the camera
		int corner_x;
		// reference to the y coordinate of the map location of the top left corner of the camera
		int corner_y;
		// how many map tiles wide the camera render zone is
		int camera_width;
		// how many map tiles high the camera render zone is
		int camera_height;
		// default constructor
		Camera();
		// moves the camera x_mod tiles in the x direction, y_mod tiles in the y direction
		void move(int x_mod, int y_mod);
};