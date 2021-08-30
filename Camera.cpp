#include "Camera.h"

Camera::Camera()
{
	corner_x = 0;
	corner_y = 0;
	camera_width = WINDOW_WIDTH / (SPRITE_SIZE * GLOBAL_RENDER_SCALING);
	camera_height = WINDOW_HEIGHT / (SPRITE_SIZE * GLOBAL_RENDER_SCALING);
}

void Camera::move(int x_mod, int y_mod)
{
	this->corner_x += x_mod;
	this->corner_y += y_mod;
}