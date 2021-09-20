#include "IronIngot.h"

IronIngot::IronIngot(int x, int y) :
	Object::Object(false, "iron-ingot", "iron-ingot", LAYER_OBJECT_ON_GROUND, x, y)
{}

IronIngot::~IronIngot()
{}