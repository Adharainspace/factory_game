#include "IronOre.h"

IronOre::IronOre(int x, int y) :
	Object::Object(false, "iron-ore", "iron-ore", LAYER_ON_GROUND, x, y)
{}

IronOre::~IronOre()
{}