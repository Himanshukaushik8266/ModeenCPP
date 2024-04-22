#include "Employee.h"
#include "Functionalities.h"
#include <algorithm>
#include <numeric>

/*
    std::copy_if -------> copy all the data that are obeying a condition
    1) this is a copy operation. copy semantic has to be supported 
    2) We don't know how many instances will statisfy the consition
    3) to copy from source to destination, destination has to already bre initialised with memory allocated to it
*/


int main()
{
    EmployeeContainer data1;
    EmployeePointerContainer data2;
    EmployeeSmartPointerContainer data3;
    CreateEmployees(data1);
    CreateEmployeesPointer(data2);
    CreateEmployeesSmartPointer(data3);

    //Result
    EmployeeContainer result(data1.size());

    //Conditional Copy
    auto itr=std::copy_if(data1.begin(),data1.end(),result.begin(),[](const Employee & emp){return emp.salary()>40000;});

    //Fix the size difference

    std::size_t actual_size=std::distance(result.begin(),itr);
    result.resize(actual_size);

    std::cout<<result.size()<<std::endl;

}

