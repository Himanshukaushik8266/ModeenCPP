/*
    std::any_of(at least one) instance satisfies condition
*/
#include "Employee.h"
#include "Functionalities.h"
#include <algorithm>
 
int main()
{
    EmployeeContainer data1;
    EmployeePointerContainer data2;
    EmployeeSmartPointerContainer data3;
    CreateEmployees(data1);
    CreateEmployeesPointer(data2);
    CreateEmployeesSmartPointer(data3);
 
    std::cout<< std::boolalpha<<std::any_of(
        data1.begin(),
        data1.end(),
        [](const Employee& emp){return emp.salary()>40000;}
    )<<std::endl;

    std::cout<<std::boolalpha<<std::any_of(
        data2.begin(),
        data2.end(),
        [](const Employee* emp){return emp->salary()>40000;}
    )<<std::endl;
}