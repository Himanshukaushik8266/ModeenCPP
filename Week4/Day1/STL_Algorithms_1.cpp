/*
    How to use STL algorithms effectively!

1) std::count_if
    count instances matching with given condition 
    condition is written as predicate.
    return value is the final count.
*/
#include <iostream>
#include "Functionalities.h"
#include <algorithm>
#include <numeric>


int main()
{

    EmployeeContainer data1;
    EmployeePointerContainer data2;
    EmployeeSmartPointerContainer data3;

    CreateEmployees(data1);

    CreateEmployeesPointer(data2);

    CreateEmployeesSmartPointer(data3);

    int count = std::count_if(data1.begin(), data1.end(), [&](const Employee &emp)
                              { return emp.salary() > 10000.0f; });
    int count2 = std::count_if(data2.begin(), data2.end(), [&](const Employee *emp)
                               { return emp->salary() > 10000.0f; });
    int count3 = std::count_if(data3.begin(), data3.end(), [&](const EmpSptr emp)
                               { return emp->salary() > 10000.0f; });

    std::cout << count << std::endl;
    std::cout << count2 << std::endl;
    std::cout << count3 << std::endl;
    return 0;
}