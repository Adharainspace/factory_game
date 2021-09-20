#include "Game.h"
#include "IronOre.h" // debug
#include "IronIngot.h" // debug
#include "Conveyor.h" // needed for rendering
#include <iostream>

Game::Game(int width, int height) :
	name("factory game :]"),
	game_window(sf::VideoMode(width, height), "", (sf::Style::Titlebar | sf::Style::Close)),
	event(),
	window_width(width),
	window_height(height),
	font_holder(),
	sprite_holder(),
	recipe_holder(),
	map(),
	player()
{
	this->game_window.setTitle(this->name);
	this->game_window.setFramerateLimit(FRAME_CAP);
	this->player = std::make_shared<Player>(10, 8);
	this->map.map_array[8][10]->add_visible_contents(player);
}

void Game::main_loop()
{
	while (this->game_window.isOpen())
	{
		// poll input
		this->poll_input();

		// update game
		this->update_game();

		// render game
		this->render_game();
	}
}

void Game::poll_input()
{
	// event polling
	while (this->game_window.pollEvent(event))
	{
		switch (event.type)
		{
			// window closed
		case sf::Event::Closed:
			this->game_window.close();
			break;

			// keyboard input
		case sf::Event::KeyPressed:
			switch (event.key.code)
			{
				case sf::Keyboard::Escape:
				{
					this->game_window.close();
					break;
				}
				case sf::Keyboard::W:
				{
					// move up
					this->player->sprite_name = "robot-up";
					if (this->move_player(0, -1))
					{
						this->camera.move(0, -1);
					}
					break;
				}
				case sf::Keyboard::A:
				{
					// move left
					this->player->sprite_name = "robot-left";
					if (this->move_player(-1, 0))
					{
						this->camera.move(-1, 0);
					}
					break;
				}
				case sf::Keyboard::S:
				{
					// move down
					this->player->sprite_name = "robot-down";
					if (this->move_player(0, 1))
					{
						this->camera.move(0, 1);
					}
					break;
				}
				case sf::Keyboard::D:
				{
					// move right
					this->player->sprite_name = "robot-right";
					if (this->move_player(1, 0))
					{
						this->camera.move(1, 0);
					}
					break;
				}
				case sf::Keyboard::Space:
				{
					// spawn item - debug purposes
					int x = this->player->x;
					int y = this->player->y;
					std::shared_ptr<Object> ore = std::make_shared<IronOre>(x, y);
					this->map.add_object(x, y, ore);
					break;
				}
				case sf::Keyboard::C:
				{
					//craft item on tile - debug purposes
					int x = this->player->x;
					int y = this->player->y;
					std::shared_ptr<Object> object;
					object = this->map.map_array[y][x]->find_object("iron-ore");
					if (object)
					{
						std::shared_ptr<Recipe> recipe = this->recipe_holder.recipe_list["iron-ingot"];
						std::unordered_map<std::string, int> item_list;
						item_list["iron-ore"] = 1;
						if (recipe->check_requirements(recipe->input_items, item_list))
						{
							this->map.remove_object(x, y, object);
							std::shared_ptr<Object> ingot = std::make_shared<IronIngot>(x, y);
							this->map.add_object(x, y, ingot);
						}
					}
					break;
				}
				case sf::Keyboard::Num1:
				{
					//spawn conveyor on tile facing south->north - debug purposes
					int x = this->player->x;
					int y = this->player->y;
					std::shared_ptr<Object> conveyor = std::make_shared<Conveyor>(x, y, 60, SOUTH, NORTH, std::make_shared<Map>(this->map));
					this->map.add_object(x, y, conveyor);
				//	this->map.get_tile(x, y)->conveyor_ptr = conveyor;
					break;
				}
				case sf::Keyboard::Num2:
				{
					//spawn conveyor on tile facing west->east - debug purposes
					int x = this->player->x;
					int y = this->player->y;
					std::shared_ptr<Object> conveyor = std::make_shared<Conveyor>(x, y, 60, WEST, EAST, std::make_shared<Map>(this->map));
					this->map.add_object(x, y, conveyor);
				//	this->map.get_tile(x, y)->conveyor_ptr = conveyor;
					break;
				}
				case sf::Keyboard::Num3:
				{
					//spawn conveyor on tile facing north->south - debug purposes
					int x = this->player->x;
					int y = this->player->y;
					std::shared_ptr<Object> conveyor = std::make_shared<Conveyor>(x, y, 60, NORTH, SOUTH, std::make_shared<Map>(this->map));
					this->map.add_object(x, y, conveyor);
					//this->map.get_tile(x, y)->has_conveyor = true;
					break;
				}
				case sf::Keyboard::Num4:
				{
					//spawn conveyor on tile facing east->west - debug purposes
					int x = this->player->x;
					int y = this->player->y;
					std::shared_ptr<Object> conveyor = std::make_shared<Conveyor>(x, y, 60, EAST, WEST, std::make_shared<Map>(this->map));
					this->map.add_object(x, y, conveyor);
				//	this->map.get_tile(x, y)->has_conveyor = true;
					break;
				}
			}
			break;
		}
	}
}

void Game::update_game()
{
	// machine loop
	for (std::shared_ptr<Machine> machine : this->machine_list)
	{
		machine->update_delay();
	}
}

void Game::render_game()
{
	// clear previous frame
	this->game_window.clear();

	// draw camera render region
	// relative coordinates for drawing to the screen
	int relative_x = 0;
	int relative_y = 0;
	for (MapIndex y = this->camera.corner_y; y < (this->camera.corner_y + this->camera.camera_height); y++)
	{
		for (MapIndex x = this->camera.corner_x; x < (this->camera.corner_x + this->camera.camera_width); x++)
		{
			// if its outside of the game map, dont render anything
			if ((x >= this->map.map_width || x < 0) || (y >= this->map.map_height || y < 0))
			{
				relative_x += (SPRITE_SIZE * GLOBAL_RENDER_SCALING);
				continue;
			}
			std::shared_ptr<Tile> tile = this->map.map_array[y][x];
			// get sprite to render
			sf::Sprite tile_sprite = this->sprite_holder.get_sprite(tile->sprite_name);
			// scale it up so that it isnt absolutely teeny
			tile_sprite.scale(sf::Vector2f(static_cast<float>(GLOBAL_RENDER_SCALING), static_cast<float>(GLOBAL_RENDER_SCALING)));
			// set position relative to window
			tile_sprite.setPosition(sf::Vector2f(static_cast<float>(relative_x), static_cast<float>(relative_y)));
			// draw sprite to window
			this->game_window.draw(tile_sprite);

			//iterate through visible contents of tile
			for (std::shared_ptr<Object> object : tile->visible_contents)
			{
				// get sprite to render
				sf::Sprite object_sprite = this->sprite_holder.get_sprite(object->sprite_name);
				// scale it up so that it isnt absolutely teeny
				object_sprite.scale(sf::Vector2f(static_cast<float>(GLOBAL_RENDER_SCALING), static_cast<float>(GLOBAL_RENDER_SCALING)));
				// set position relative to window
				object_sprite.setPosition(sf::Vector2f(static_cast<float>(relative_x), static_cast<float>(relative_y)));
				// draw sprite to window
				this->game_window.draw(object_sprite);
			}

			// conveyor belt in tile?
			if (tile->conveyor_ptr)
			{
				// cast object ptr to a conveyor pointer
				Conveyor* raw_ptr = dynamic_cast<Conveyor*>(tile->conveyor_ptr.get());
				for (std::shared_ptr<Object> object : raw_ptr->visible_contents)
				{
					// get sprite to render
					sf::Sprite object_sprite = this->sprite_holder.get_sprite(object->sprite_name);
					// scale it up so that it isnt absolutely teeny
					object_sprite.scale(sf::Vector2f(static_cast<float>(GLOBAL_RENDER_SCALING), static_cast<float>(GLOBAL_RENDER_SCALING)));
					// set position relative to window
					object_sprite.setPosition(sf::Vector2f(static_cast<float>(relative_x), static_cast<float>(relative_y)));
					// draw sprite to window
					this->game_window.draw(object_sprite);
				}
			}

			// increment relative x coordinate
			relative_x += (SPRITE_SIZE * GLOBAL_RENDER_SCALING);
		}
		// increment relative y coordinate and reset relative x
		relative_x = 0;
		relative_y += (SPRITE_SIZE * GLOBAL_RENDER_SCALING);
	}

	// tell window that the frame is ready
	this->game_window.display();
}

bool Game::move_player(int x_mod, int y_mod)
{
	int x = this->player->x;
	int y = this->player->y;

	//cant move into it
	if (this->map.map_array[y + y_mod][x + x_mod]->check_density() == true)
	{
		return false;
	}

	this->map.map_array[y][x]->remove_visible_contents(this->player);
	this->map.map_array[y + y_mod][x + x_mod]->add_visible_contents(this->player);
	this->player->x = x + x_mod;
	this->player->y = y + y_mod;
	return true;
}