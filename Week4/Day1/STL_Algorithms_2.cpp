/*
    How to use STL algorithms effectively!

2) std::find_if : find object matching my search criteria 
    returns "Iterator" to the first matching objects
    if match is not found find_if returns end iterator

    end()-> is not the last position , it is one position beyond that  


*/
#include <iostream>
#include "Functionalities.h"
#include <algorithm>
#include<functional>
#include <numeric>
template<typename T,typename P>
typename T::const_iterator Search(const T& data, const P &fn){
    auto itr=std::find_if(data.begin(),data.end(),fn);

    if(itr==data.end()){
        std::cerr<<"Object not found"<<std::endl;
    }
    // else{
    //     std::cout<<" Object found \n"<<*itr<<"\n";
    // }
    return itr;
}

int main()
{

    EmployeeContainer data1;
    EmployeePointerContainer data2;
    EmployeeSmartPointerContainer data3;

    CreateEmployees(data1);

    CreateEmployeesPointer(data2);

    CreateEmployeesSmartPointer(data3);


    EmployeeContainer::const_iterator itr=Search<EmployeeContainer, std::function<bool(const Employee &)>>(data1, [](const Employee& e){return e.designation() == "Manager";});
    std::cout<<*itr<<std::endl;


    EmployeePointerContainer::const_iterator itr1=Search<EmployeePointerContainer, std::function<bool(const Employee*)>>(data2, [](const Employee* e){return e->designation() == "Manager";});
    std::cout<<**itr1<<std::endl;


    return 0;
}