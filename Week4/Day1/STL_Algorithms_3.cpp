/*
    Check if all instances meet a condition Returns true if all meet else return false

3) std::all_of
    - takes 1 predicate,
    return a boolean

*/

#include <iostream>
#include "Functionalities.h"
#include <algorithm>
#include <functional>
#include <numeric>

int main()
{

    EmployeeContainer data1;
    EmployeePointerContainer data2;
    EmployeeSmartPointerContainer data3;

    CreateEmployees(data1);

    CreateEmployeesPointer(data2);

    CreateEmployeesSmartPointer(data3);

    std::cout << std::boolalpha << std::all_of(data1.begin(), data1.end(), [](const Employee &emp)
                                               { return emp.salary() > 40000.0f; })
              << std::endl;

    return 0;
}