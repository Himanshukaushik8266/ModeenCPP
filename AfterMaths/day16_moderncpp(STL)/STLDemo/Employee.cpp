#include "Employee.h"

Employee::Employee(std::string id, std::string name, float salary, int age, std::string location)
    :_id{id},_name{name}, _salary{salary}, _age{age}, _location{location}
{
}
std::ostream &operator<<(std::ostream &os, const Employee &rhs) {
    os << "_id: " << rhs._id
       << " _name: " << rhs._name
       << " _salary: " << rhs._salary
       << " _age: " << rhs._age
       << " _location: " << rhs._location;
    return os;
}
