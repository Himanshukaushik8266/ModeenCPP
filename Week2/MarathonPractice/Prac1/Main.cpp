#include <iostream>
#include "Employee.h"
#include "Functionalities.h"

int main()
{

    EmployeeConatiner employeedata;
    CompanyContainer companydata;

    CreateObjects(companydata, employeedata);

    PrintObjects(companydata);

    Deletecompany(companydata);

    Deleteemployee(employeedata);

    return 0;
}