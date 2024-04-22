#include "Tester.h"



std::ostream &operator<<(std::ostream &os, const Tester &rhs) {
    os << "_id: " << rhs._id
       << " _name: " << rhs._name
       << " _salary: " << rhs._salary
       << " _experience_years: " << rhs._experience_years;
    return os;
}

Tester::Tester(std::string id, std::string name, float salary, int experience, Skills skills)
: _id{id}, _name{name}, _experience_years{experience}, _skills{skills},_salary{salary}
{}

float Tester::CalculateBonus()
{
    if (this->experienceYears() < 5)
        return 0.05f * this->salary();

    else if (this->experienceYears() > 5)
        return 0.1f * this->salary();

    else
        return 0.0f;
}
