#include "Teacher.h"

Teacher::Teacher(int empId, std::string name, std::vector<VarType> students)
    : _empId{empId}, _name{name}, _students{students}
{
}
std::ostream &operator<<(std::ostream &os, const Teacher &rhs)
{
    os << "_empId: " << rhs._empId
       << " _name: " << rhs._name
       << " _students: ";
    for (VarType v : rhs._students)
    {
        std::visit([](auto &&val)
                   { std::cout << *val; },
                   v);
    }
    return os;
}
