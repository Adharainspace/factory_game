#pragma once

#include "Macros.h"
#include "Object.h"

class IronIngot : public Object
{
	public:
		IronIngot(int x, int y);
		~IronIngot() override;
};