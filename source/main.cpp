#include "food.h"
#include "hiberlite/hiberlite.h"

#include "fooddatabase.h"

#include <iostream>
#include <fstream>
#include <string>


int main(int argc, char** argv)
{
#if 0
	hiberlite::Database db("foods.db");
	db.registerBeanClass<Food>();
	db.dropModel();
	db.createModel();


	Food food2;
	food2.set_name("Protein Powder");
	food2.set_serving_size(100);
	food2.set_calories(100);
	food2.set_fat(10);
	food2.set_protein(32);
	food2.set_fiber(1);
	food2.set_carbs(50);

	auto food = db.copyBean(food2);


	db.close();

#else
	FoodDatabase::open("foods.db");


	std::string line;

	bool stop = false;
	for( ; !stop; )
	{
		std::getline(std::cin, line);
		if(line == "quit")
		{
			stop = true;
		}
		else
		{
			std::cout<<"Searching for \""<<line<<"\"\n";
			std::vector<Food> matches = FoodDatabase::lookup(line);
			for(auto food : matches)
			{
				std::cout<<"\t"<<food.get_name()<<"\n";
			}
			std::cout<<"\n";
		}
	}
#endif

	return 0;
}