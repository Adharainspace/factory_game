#pragma once

#include "Macros.h"
#include "Machine.h"
#include "Map.h"
#include <memory>

class Map;

class Conveyor : public Machine
{
	protected:
		std::shared_ptr<Map> map;
	public:
		uint8_t start_direction;
		uint8_t end_direction;
		Conveyor(int x, int y, int update_delay, uint8_t start_direction, uint8_t end_direction, std::shared_ptr<Map> map);
		~Conveyor() override;
		void update_state() override;
		void set_direction(uint8_t start, uint8_t end);
};
