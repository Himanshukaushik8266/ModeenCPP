#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H
#include "Company.h"
#include "Employee.h"
using CompanyContainer=std::vector<Company *>;
using EmployeeConatiner=std::vector<Employee *>;

void CreateObjects(CompanyContainer & Companydata, EmployeeConatiner & Employeedata);
void PrintObjects(const CompanyContainer &data);

void Deletecompany(CompanyContainer &data);
void Deleteemployee(EmployeeConatiner &data);
#endif // FUNCTIONALITIES_H
