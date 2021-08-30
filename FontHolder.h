#pragma once

#include "Macros.h"

class FontHolder
{
	private:
		// loads a font from a file
		sf::Font load_font(std::string font_path);
	public:
		// default constructor
		FontHolder();
		// pixelated font
		sf::Font press_start;
};