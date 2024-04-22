#include "Employee.h"
std::ostream &operator<<(std::ostream &os, const Employee &rhs) {
    os << "_name: " << rhs._name
       << " _age: " << rhs._age
    //    << " _gender: " << rhs._gender
    //    << " _post: " << rhs._post
       << " _salary: " << rhs._salary;
    return os;
}

Employee::Employee(std::string name, unsigned int age, Gender gender, EmployeeType post, float salary)
:_name{name},_age{age},_gender{gender},_post{post},_salary{salary}
{
}