#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include<vector>
#include "Employee.h"
#include<memory>

using StackEmployeeContainer = std::vector<Employee>;
using EmployeePointerContainer = std::vector<Employee*>;
using EmployeeSmartPointerContainer = std::vector<std::shared_ptr<Employee>>;


void CreateObjects(StackEmployeeContainer& data);

void CreateObjects(EmployeePointerContainer& data);

void CreateObjects(EmployeeSmartPointerContainer& data);

#endif // FUNCTIONALITIES_H
