#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>

class Employee 
{
private:
    std::string _id;
    std::string _name;
    float _salary;
    int _age;
    std::string _location;
public:
    Employee() = default; // Default constructor
    Employee(const Employee&) = default; // Copy constructor
    Employee& operator=(const Employee&) = default; // Copy assignment operator
    Employee(Employee&&) = default; // Move constructor
    Employee& operator=(Employee&&) = default; // Move assignment operator
    ~Employee() = default; // Destructor

    float operator+(const Employee& rhs){return _salary + rhs._salary;}//used it to skip lamda bcoz my code already knows what + operator is doing

    Employee(std::string id,std::string name,float salary,int age,std::string location);

    std::string id() const { return _id; }

    std::string name() const { return _name; }

    float salary() const { return _salary; }

    int age() const { return _age; }

    std::string location() const { return _location; }

    friend std::ostream &operator<<(std::ostream &os, const Employee &rhs);
};

#endif // EMPLOYEE_H
