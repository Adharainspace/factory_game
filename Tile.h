#pragma once

#include "Macros.h"

#include "Object.h"
#include <vector>
#include <memory>

class Tile : public Object {
public:
	std::vector<std::shared_ptr<Object>> contents;
	std::vector<std::shared_ptr<Object>> visible_contents;
	Tile();
	Tile(std::string sprite_name, int x, int y);
	Tile(bool density, std::string sprite_name, int layer, int x, int y);
	~Tile() override;
	virtual void add_contents(std::shared_ptr<Object> object);
	virtual void remove_contents(std::shared_ptr<Object> object);
	virtual void add_visible_contents(std::shared_ptr<Object> object);
	virtual void remove_visible_contents(std::shared_ptr<Object> object);
	virtual bool check_density();
	virtual std::shared_ptr<Object> find_object(std::string object_id);
};