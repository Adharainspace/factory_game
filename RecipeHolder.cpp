#include "RecipeHolder.h"

RecipeHolder::RecipeHolder()
{
	// recipe initialisation

	// iron ingot recipe
	std::shared_ptr<Recipe> iron_ingot = std::make_shared<Recipe>();
	iron_ingot->add_input("iron-ore", 1);
	iron_ingot->add_output("iron-ingot", 1);
	this->recipe_list["iron-ingot"] = iron_ingot;
}