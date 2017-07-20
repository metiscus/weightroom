#pragma once

#include <string>

class Exercise
{
	friend class hiberlite::access;

	std::string name_;
	bool quadraceps_;
	bool hamstrings_;
	bool calves_;
	bool chest_;
	bool back_;
	bool shoulders_;
	bool triceps_;
	bool biceps_;
	bool forearms_;
	bool traps_;
	bool abs_;

    template<class Archive>
    void hibernate(Archive & ar)
    {
        ar & HIBERLITE_NVP(name_);
        ar & HIBERLITE_NVP(quadraceps_);
        ar & HIBERLITE_NVP(hamstrings_);
        ar & HIBERLITE_NVP(calves_);
        ar & HIBERLITE_NVP(chest_);
        ar & HIBERLITE_NVP(back_);
        ar & HIBERLITE_NVP(shoulders_);
        ar & HIBERLITE_NVP(triceps_);
        ar & HIBERLITE_NVP(biceps_);
        ar & HIBERLITE_NVP(forearms_);
        ar & HIBERLITE_NVP(traps_);
        ar & HIBERLITE_NVP(abs_);
    }

};