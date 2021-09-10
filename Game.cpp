#include "Game.h"
#include "IronOre.h" // debug
#include <iostream>

Game::Game(int width, int height) :
	name("factory game :]"),
	game_window(sf::VideoMode(width, height), "", (sf::Style::Titlebar | sf::Style::Close)),
	event(),
	window_width(width),
	window_height(height),
	font_holder(),
	sprite_holder(),
	map(),
	player()
{
	this->game_window.setTitle(this->name);
	this->player = std::make_shared<Player>(10, 8);
	this->map.map_array[8][10]->add_visible_contents(player);
}

void Game::main_loop()
{
	while (this->game_window.isOpen())
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
					this->game_window.close();
					break;
				case sf::Keyboard::W:
					// move up
					this->player->sprite_name = "robot-up";
					if (this->move_player(0, -1))
					{
						this->camera.move(0, -1);
					}
					break;
				case sf::Keyboard::A:
					// move left
					this->player->sprite_name = "robot-left";
					if (this->move_player(-1, 0))
					{
						this->camera.move(-1, 0);
					}
					break;
				case sf::Keyboard::S:
					// move down
					this->player->sprite_name = "robot-down";
					if (this->move_player(0, 1))
					{
						this->camera.move(0, 1);
					}
					break;
				case sf::Keyboard::D:
					// move right
					this->player->sprite_name = "robot-right";
					if (this->move_player(1, 0))
					{
						this->camera.move(1, 0);
					}
					break;
				case sf::Keyboard::Space:
					// spawn item - debug purposes
					int x = this->player->x;
					int y = this->player->y;
					std::shared_ptr<Object> ore = std::make_shared<IronOre>(x, y);
					this->spawn_object(x, y, ore);
				}
				break;
			}
		}

		// update game
		this->update_game();

		// render game
		this->render_game();
	}
}

void Game::update_game()
{}

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
			// get sprite to render
			sf::Sprite tile_sprite = this->sprite_holder.get_sprite(this->map.map_array[y][x]->sprite_name);
			// scale it up so that it isnt absolutely teeny
			tile_sprite.scale(sf::Vector2f(static_cast<float>(GLOBAL_RENDER_SCALING), static_cast<float>(GLOBAL_RENDER_SCALING)));
			// set position relative to window
			tile_sprite.setPosition(sf::Vector2f(static_cast<float>(relative_x), static_cast<float>(relative_y)));
			// draw sprite to window
			this->game_window.draw(tile_sprite);

			//iterate through visible contents of tile
			for (unsigned int i = 0; i < this->map.map_array[y][x]->visible_contents.size(); i++)
			{
				// get sprite to render
				sf::Sprite object_sprite = this->sprite_holder.get_sprite(this->map.map_array[y][x]->visible_contents[i]->sprite_name);
				// scale it up so that it isnt absolutely teeny
				object_sprite.scale(sf::Vector2f(static_cast<float>(GLOBAL_RENDER_SCALING), static_cast<float>(GLOBAL_RENDER_SCALING)));
				// set position relative to window
				object_sprite.setPosition(sf::Vector2f(static_cast<float>(relative_x), static_cast<float>(relative_y)));
				// draw sprite to window
				this->game_window.draw(object_sprite);
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

void Game::spawn_object(int x, int y, std::shared_ptr<Object> object)
{
	this->map.map_array[y][x]->add_visible_contents(object);
}