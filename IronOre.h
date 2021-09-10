#pragma once

#include "Macros.h"
#include "Object.h"

class IronOre : public Object
{
	public:
		IronOre(int x, int y);
		~IronOre() override;
};
