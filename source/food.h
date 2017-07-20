#pragma once

#include <map>
#include <string>
#include "hiberlite/hiberlite.h"

class Food
{
	friend class hiberlite::access;

	std::string name_;
	float serving_size_;
	float calories_;
	float protein_;
	float carbs_;
	float fat_;
	float fiber_;

    template<class Archive>
    void hibernate(Archive & ar)
    {
        ar & HIBERLITE_NVP(name_);
        ar & HIBERLITE_NVP(serving_size_);
        ar & HIBERLITE_NVP(calories_);
        ar & HIBERLITE_NVP(protein_);
        ar & HIBERLITE_NVP(carbs_);
        ar & HIBERLITE_NVP(fat_);
        ar & HIBERLITE_NVP(fiber_);
    }

public:

	Food()
		: name_(""), serving_size_(0), calories_(0), protein_(0)
		, carbs_(0), fat_(0), fiber_(0)
	{}

	void set_name(const std::string& name);
	inline void set_serving_size(float serving_size) 	{ serving_size_ = serving_size; }
	inline void set_calories(float calories) 			{ calories_ = calories; }
	inline void set_protein(float protein) 				{ protein_ = protein; }
	inline void set_carbs(float carbs) 					{ carbs_ = carbs; }
	inline void set_fat(float fat) 						{ fat_ = fat; }
	inline void set_fiber(float fiber) 					{ fiber_ = fiber; }

	inline std::string get_name () const 				{ return name_; }
	inline float set_serving_size () const 				{ return serving_size_; }
	inline float set_calories () const 					{ return calories_; }
	inline float set_protein () const 					{ return protein_; }
	inline float set_carbs () const 					{ return carbs_; }
	inline float set_fat () const 						{ return fat_; }
	inline float set_fiber () const 					{ return fiber_; }
};
