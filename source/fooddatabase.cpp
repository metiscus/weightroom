#include "fooddatabase.h"
#include "food.h"

#include "hiberlite/hiberlite.h"

#include <algorithm>
#include <cassert>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

namespace FoodDatabase
{

	namespace 
	{
		typedef hiberlite::bean_ptr<Food> FoodPtr;
		std::vector<FoodPtr> foods_;
		std::unique_ptr<hiberlite::Database> database_;
	}

	void open(const std::string& filename)
	{
		if(database_)
		{
			assert(false);
			database_->close();
		}

		// load the database
		database_ = std::unique_ptr<hiberlite::Database>(new hiberlite::Database(filename.c_str()));

		assert(database_);
		if(database_)
		{
			foods_ = database_->getAllBeans<Food>();
		}
	}

	void close(const std::string& filename)
	{
		if(database_)
		{
			database_->close();
		}
	}

	void add_food(const Food& food)
	{
		assert(database_);
		if(database_)
		{
			FoodPtr foodPtr = database_->copyBean(food);
			foods_.push_back(foodPtr);
		}
	}

	void remove_food(const std::string& name)
	{
		assert(database_);
		for(auto itr = foods_.begin(); itr != foods_.end(); ++itr)
		{
			if((*itr)->get_name() == name)
			{
				(*itr).destroy();
				foods_.erase(itr);
				break;
			}
		}
	}

	void clear()
	{
		foods_.clear();
	}

	std::vector<Food> lookup(const std::string& name)
	{
		std::vector<Food> matches;

		// all names are encoded as lower case
		std::string search_name = name;
		std::transform(search_name.begin(), search_name.end(), search_name.begin(), ::tolower);

		// search for foods that match
		for(auto food : foods_)
		{
			if(food->get_name().find(name) != std::string::npos)
			{
				matches.emplace_back(*food);
			}
			else
			{
				std::cerr<<"!"<<food->get_name()<<"\n";
			}
		}

		return matches;
	}

}