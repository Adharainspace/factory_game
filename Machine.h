#pragma once

#include "Macros.h"
#include "Object.h"
#include <vector>
#include <memory>

class Machine : public Object {
	protected: 
		// how many simulation ticks in between updating machine state - 0 updates every tick
		int tick_delay;
		// how many simulation ticks left before updating machine state
		int current_delay;
	public: 
		std::vector<std::shared_ptr<Object>> contents;
		std::vector<std::shared_ptr<Object>> visible_contents;
		Machine();
		Machine(std::string sprite_name, std::string id, int x, int y, int update_delay);
		Machine(bool density, std::string sprite_name, std::string id, int layer, int x, int y, int update_delay);
		~Machine() override;
		void update_delay();
		virtual void update_state();
		virtual void add_contents(std::shared_ptr<Object> object);
		virtual void remove_contents(std::shared_ptr<Object> object);
		virtual void add_visible_contents(std::shared_ptr<Object> object);
		virtual void remove_visible_contents(std::shared_ptr<Object> object);
		virtual void sort_visible_contents();
};