#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H
#include <unordered_map>
#include "Employee.h"
#include "CorporateEmployee.h"
#include "GovernmentEmployee.h"
#include <memory>
#include <variant>
#include <algorithm>
#include <numeric>

using EmployeePointer = std::shared_ptr<Employee>;
using CorporateEmployeePointer = std::shared_ptr<CorporateEmployee>;
using GovernmentEmployeePointer = std::shared_ptr<GovernmentEmployee>;
using Container = std::unordered_map<EmployeePointer, std::vector<EmployeePointer>>;

void CreateObjects(Container &data);
float AverageofEmployeeUnderManager(Container &data, std::string name);
std::string FindManagerUsingEmpid(Container &data, std::variant<std::string, int> id);
void DisplayObjects(Container &data);

#endif // FUNCTIONALITIES_H
