#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
class Employee
{
private:
    /* data */
    std::string _name;
    int _salary;

public:
    Employee() = default;
    Employee(const Employee &) = delete;
    Employee(Employee &&) = delete;
    Employee &operator=(const Employee &) = delete;
    Employee &operator=(Employee &&) = delete;
    ~Employee() = default;

    Employee(std::string name, int salary) : _name{name}, _salary{salary} {}

    std::string name() const { return _name; }
    void setName(const std::string &name) { _name = name; }

    int salary() const { return _salary; }
    void setSalary(int salary) { _salary = salary; }

    friend std::ostream &operator<<(std::ostream &os, const Employee &rhs)
    {
        os << "_name: " << rhs._name
           << " _salary: " << rhs._salary;
        return os;
    }
};

#endif // EMPLOYEE_H
