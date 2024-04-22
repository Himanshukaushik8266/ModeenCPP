#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include <iostream>
#include "Employee.h"
#include <memory>
#include <vector>

using EmployeeContainer = std::vector<Employee>;
using EmployeePointerContainer = std::vector<Employee *>;
using EmpSptr = std::shared_ptr<Employee>;
using EmployeeSmartPointerContainer = std::vector<EmpSptr>;

void CreateEmployees(EmployeeContainer &data)
{
    data.push_back(Employee("Himanshu", 50000.0f, "Trainee", 1));
    data.push_back(Employee("Vikas", 55000.0f, "Trainer", 5));
    data.push_back(Employee("Ramesh", 47000.0f, "Manager", 2));
}
void CreateEmployeesPointer(EmployeePointerContainer &data)
{
    data.push_back(new Employee("Himanshu", 19000.0f, "Trainee", 1));
    data.push_back(new Employee("Vikas", 20000.0f, "Trainer", 5));
    data.push_back(new Employee("Ramesh", 25000.0f, "Manager", 2));
}
void CreateEmployeesSmartPointer(EmployeeSmartPointerContainer &data)
{
    data.push_back(std::make_shared<Employee>("Himanshu", 19000.0f, "Trainee", 1));
    data.push_back(std::make_shared<Employee>("Vikas", 20000.0f, "Trainer", 5));
    data.push_back(std::make_shared<Employee>("Ramesh", 25000.0f, "Manager", 2));
}

#endif // FUNCTIONALITIES_H
