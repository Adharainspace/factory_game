#include "Object.h"

Object::Object()
{
	this->density = false;
	this->sprite_name = "";
	this->layer = LAYER_GROUND;
	this->x = 0;
	this->y = 0;
	this->pixel_x = 0;
	this->pixel_y = 0;
}

Object::Object(std::string sprite_name, int x, int y)
{
	this->density = false;
	this->sprite_name = sprite_name;
	this->layer = LAYER_GROUND;
	this->x = x;
	this->y = y;
	this->pixel_x = 0;
	this->pixel_y = 0;
}

Object::Object(bool density, std::string sprite_name, int layer, int x, int y)
{
	this->density = density;
	this->sprite_name = sprite_name;
	this->layer = layer;
	this->x = x;
	this->y = y;
	this->pixel_x = 0;
	this->pixel_y = 0;
}

Object::~Object()
{}