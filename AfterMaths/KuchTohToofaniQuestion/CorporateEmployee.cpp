#include "CorporateEmployee.h"
std::ostream &operator<<(std::ostream &os, const CorporateEmployee &rhs)
{
    os << " _id: " << rhs._id
       << static_cast<const Employee &>(rhs);
    return os;
}

CorporateEmployee::CorporateEmployee(std::string id, std::string name, unsigned int age, Gender gender, EmployeeType post, float salary)
    : Employee(name, age, gender, post, salary), _id{id}
{
}

float CorporateEmployee::CalculateTaxes()
{
    return 0.15f * salary();
}
