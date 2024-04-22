#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "Employee.h"
#include<vector>
#include<memory>

using ProjectsContainer=std::vector<Project>;
using EmployeeContainer=std::vector<std::shared_ptr<Employee>>;


void CreateObjects(EmployeeContainer &employees,ProjectsContainer &projects);

void DisplayObjects(EmployeeContainer &employees);

#endif // FUNCTIONALITIES_H
