#pragma once

#include "Macros.h"
#include "FontHolder.h"
#include "SpriteHolder.h"
#include "RecipeHolder.h"
#include "Map.h"
#include "Camera.h"
#include "Player.h"
#include "Machine.h"
#include "Tile.h"
#include <vector>

class Game
{
	private:
		//name of game / window
		std::string name;
		// the window which the game displays in
		sf::RenderWindow game_window;
		// any input events from the user are stored here
		sf::Event event;
		// camera that controls what is rendered on screen
		Camera camera;
	public:
		// width of the game window
		int window_width;
		// height of the game window
		int window_height;
		// class which holds font data for use in drawing text
		FontHolder font_holder;
		// class which holds spritesheet data for use in drawing sprites
		SpriteHolder sprite_holder;
		// class which holds recipe data for crafting items in game
		RecipeHolder recipe_holder;
		// class which holds map data for game
		Map map;
		// object that is controlled by user input - the player
		std::shared_ptr<Player> player;
		// vector which holds a shared pointer to a machine object, for all machines in the game
		std::vector<std::shared_ptr<Machine>> machine_list;
		// game class constructor
		Game(int width, int height);
		// the main backbone loop of the game, polls input, calls update game and renders game functions
		void main_loop();
		// input polling 
		void poll_input();
		// all non-graphical calculations for the game take place here
		void update_game();
		// the current frame is drawn and displayed here
		void render_game();
		// moves the player object around on the map
		bool move_player(int x_mod, int y_mod);
};