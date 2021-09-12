#include "Recipe.h"

#include <iostream>

Recipe::Recipe()
{
	this->input_items = std::unordered_map<std::string, int>();
	this->output_items = std::unordered_map<std::string, int>();
	this->process_time = 0;
}

Recipe::Recipe(const std::unordered_map<std::string, int>& input_items, const std::unordered_map<std::string, int>& output_items, double process_time)
{
	this->input_items = input_items;
	this->output_items = output_items;
	this->process_time = process_time;
}

void Recipe::add_input(std::string item, int amount)
{
	this->input_items[item] = amount;
}

void Recipe::add_output(std::string item, int amount)
{
	this->output_items[item] = amount;
}

void Recipe::set_process_time(double time)
{
	this->process_time = time;
}

bool Recipe::check_requirements(const std::unordered_map<std::string, int>& input_items, const std::unordered_map<std::string, int>& output_items)
{
	for (auto const& recipe_pair : this->input_items)
	{
		for (auto const& check_pair : input_items)
		{
			if (check_pair.first == recipe_pair.first && check_pair.second >= recipe_pair.second)
			{
				continue;
			}
			return false;
		}
	}
	return true;
}