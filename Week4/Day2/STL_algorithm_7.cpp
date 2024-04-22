#include "Employee.h"
#include "Functionalities.h"
#include <algorithm>
#include <numeric>

/*
    std::copy -------> copy all the data without any condition
*/

int main()
{
    EmployeeContainer data1;
    EmployeePointerContainer data2;
    EmployeeSmartPointerContainer data3;
    CreateEmployees(data1);
    CreateEmployeesPointer(data2);
    CreateEmployeesSmartPointer(data3);

    //result
    EmployeeContainer result(data1.size());

    std::copy(data1.begin(),data1.end(),result.begin());


}

