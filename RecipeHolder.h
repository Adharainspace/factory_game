#pragma once

#include "Recipe.h"
#include <memory>
//#include <string>

class RecipeHolder
{
private:

public:
	RecipeHolder();
	std::unordered_map<std::string, std::shared_ptr<Recipe>> recipe_list;
};