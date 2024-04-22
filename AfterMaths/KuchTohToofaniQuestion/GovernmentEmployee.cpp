#include "GovernmentEmployee.h"
std::ostream &operator<<(std::ostream &os, const GovernmentEmployee &rhs)
{
    os << " _id: " << rhs._id
       << static_cast<const Employee &>(rhs);
    return os;
}

GovernmentEmployee::GovernmentEmployee(int id, std::string name, unsigned int age, Gender gender, EmployeeType post, float salary)
    : Employee(name, age, gender, post, salary), _id{id}
{
}

float GovernmentEmployee::CalculateTaxes()
{
    return 0.05f * salary();
}
