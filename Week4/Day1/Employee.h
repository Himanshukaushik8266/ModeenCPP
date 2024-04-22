#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include<iostream>
class Employee
{
private:
    std::string _name{""};
    float _salary{0.0f};
    std::string _designation{""};
    int _expYear{-1};
public:
    Employee()=default;
    Employee(const Employee &)=default;
    Employee(Employee && )=default;
    Employee & operator=(const Employee & )=default;
    Employee &operator=(Employee &&)=default;
    ~Employee()=default;

    Employee(std::string name, float salary,std::string designation,int years):_name{name},_salary{salary},_designation{designation},_expYear{years}{}

    float salary() const { return _salary; }

    std::string designation() const { return _designation; }

    int expYear() const { return _expYear; }

    std::string name() const { return _name; }

    void setName(const std::string &name) { _name = name; }

    void setSalary(float salary) { _salary = salary; }

    void setDesignation(const std::string &designation) { _designation = designation; }

    void setExpYear(int expYear) { _expYear = expYear; }

    friend std::ostream &operator<<(std::ostream &os, const Employee &rhs) {
        os << "_name: " << rhs._name
           << " _salary: " << rhs._salary
           << " _designation: " << rhs._designation
           << " _expYear: " << rhs._expYear;
        return os;
    }


};

#endif // EMPLOYEE_H
