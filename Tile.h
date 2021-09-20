#pragma once

#include "Macros.h"

#include "Object.h"
#include <vector>
#include <memory>

class Tile : public Object {
public:
	// possibly deprecated
	std::vector<std::shared_ptr<Object>> contents;
	// objects in the tile (these are rendered)
	std::vector<std::shared_ptr<Object>> visible_contents;
	// flag for if the tile has a conveyor belt. if its true, all additions go onto the conveyor and the conveyor contents are rendered with the tile
	bool has_conveyor;
	// default constructor
	Tile();
	// im not commenting this
	Tile(std::string sprite_name, int x, int y);
	// not this one either
	Tile(bool density, std::string sprite_name, int layer, int x, int y);
	// default destructor
	~Tile() override;
	// adds an object to the contents of the tile -- deprecated?
	virtual void add_contents(std::shared_ptr<Object> object);
	// removes an object from the contents of the tile -- deprecated? 
	virtual void remove_contents(std::shared_ptr<Object> object);
	// adds an object to the visible contents vector of the tile
	virtual void add_visible_contents(std::shared_ptr<Object> object);
	// removes an object from the visible contents vector of the tile
	virtual void remove_visible_contents(std::shared_ptr<Object> object);
	// checks the density of the tile and all objects in it. returns true if it or any contents are dense. false if it is not dense
	virtual bool check_density();
	// finds an object in the visual contents of a tile. returns a shared pointer to the first object that matches the passed id, or nullptr
	virtual std::shared_ptr<Object> find_object(std::string object_id);
	// finds the index of an object in the visual contents vector of the tile. returns the index to the first that matches, or -1 if none match.
	virtual int find_object_idx(std::string object_id);
};