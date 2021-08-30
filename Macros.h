#pragma once

// SFML Libraries
#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>
#include <SFML\Window.hpp>
#include <SFML\Audio.hpp>
#include <SFML\Network.hpp>

// exception handling
#include "Exception.cpp"

// layer definitions
const int LAYER_GROUND = 1;
const int LAYER_ON_GROUND = 2;
const int LAYER_PLAYER = 3;

// rendering definitions
const int FRAME_CAP = 60;
const int GLOBAL_RENDER_SCALING = 4;
const int SPRITE_SIZE = 8;

//game window defintions
const int WINDOW_WIDTH = 640;
const int WINDOW_HEIGHT = 480;