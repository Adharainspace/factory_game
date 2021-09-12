#pragma once


#include <unordered_map>

#include <string>


class Recipe
{
public:
	Recipe();
	Recipe(const std::unordered_map<std::string, int>& input_items, const std::unordered_map<std::string, int>& output_items, double process_time);
	std::unordered_map<std::string, int> input_items;
	std::unordered_map<std::string, int> output_items;
	double process_time;
	void add_input(std::string item, int amount);
	void add_output(std::string item, int amount);
	void set_process_time(double process_time);
	bool check_requirements(const std::unordered_map<std::string, int>& input_items, const std::unordered_map<std::string, int>& output_items);
};