#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include<iostream>
#include "Gender.h"
#include "EmployeeType.h"
class Employee
{
private:
    
    std::string _name{""};
    unsigned int _age{0};
    Gender _gender{Gender::MALE};
    EmployeeType _post{EmployeeType::EMPLOYEE};
    float _salary{0.0f};

public:

    Employee()=default;
    Employee(const Employee &)=delete;
    Employee(Employee && )=delete;
    Employee & operator=(const Employee & )=delete;
    Employee &operator=(Employee &&)=delete;
    virtual ~Employee()=default;

    Employee(std::string name, unsigned int age, Gender gender, EmployeeType post,float salary);
    
    virtual float CalculateTaxes()=0;

    std::string name() const { return _name; }

    unsigned int age() const { return _age; }

    Gender gender() const { return _gender; }

    EmployeeType post() const { return _post; }

    float salary() const { return _salary; }

    friend std::ostream &operator<<(std::ostream &os, const Employee &rhs);
    
};

#endif // EMPLOYEE_H
