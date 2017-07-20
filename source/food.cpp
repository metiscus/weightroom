#include "food.h"

#include <algorithm>
#include <string>

HIBERLITE_EXPORT_CLASS(Food)


void Food::set_name(const std::string& name)
{
	name_ = name;
	std::transform(name_.begin(), name_.end(), name_.begin(), ::tolower);
}