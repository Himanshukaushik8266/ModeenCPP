#include "Employee.h"
#include "Functionalities.h"
#include <algorithm>
#include <numeric>

/*
    std::max_element
*/

int main()
{
    EmployeeContainer data1;
    EmployeePointerContainer data2;
    EmployeeSmartPointerContainer data3;
    CreateEmployees(data1);
    CreateEmployeesPointer(data2);
    CreateEmployeesSmartPointer(data3);

    /*
        If there are two max values first iteration is returned
    */

    auto itr=std::max_element(data1.begin(),data1.end(),[](const Employee & emp1,const Employee emp2){return emp1.salary()<emp2.salary();});

    std::cout<<*itr<<std::endl;

}