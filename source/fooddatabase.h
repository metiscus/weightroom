#pragma once

#include "food.h"

#include <string>
#include <vector>

namespace FoodDatabase
{
	void open(const std::string& filename);
	void close(const std::string& filename);
	void add_food(const Food& food);
	void remove_food(const std::string& name);
	void clear();

	std::vector<Food> lookup(const std::string& name);
};