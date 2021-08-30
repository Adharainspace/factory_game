#include "FontHolder.h"

FontHolder::FontHolder()
{
	this->press_start = load_font("Data/Fonts/PressStart2p-vaV7.ttf");
}

sf::Font FontHolder::load_font(std::string font_path)
{
	sf::Font font;
	if (!font.loadFromFile(font_path))
	{
		Exception exception("error loading resource " + font_path);
		throw(exception);
	}
	return font;
}