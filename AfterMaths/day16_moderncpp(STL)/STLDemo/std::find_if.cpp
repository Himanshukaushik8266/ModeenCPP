/* 
to find the position of first matching data in input container
e.g. find the employee name for the employee whose id matches with id provided
eg: find the name of the first employee in input whose salary is above 50000.

findif returns iterator to match found or end iterator for input data if match is not found
 */

#include<iostream>
#include "Functionalities.h"
#include<algorithm>

StackEmployeeContainer::const_iterator FetchById(std::string id, StackEmployeeContainer& data1){
    auto itr =std::find_if(
        data1.begin(),data1.end(),
        [&](const Employee& emp){return emp.id()==id;}
    );
    return itr;
}

int main(){
    StackEmployeeContainer data1;
    EmployeePointerContainer data2;
    EmployeeSmartPointerContainer data3;
    CreateObjects(data1);
    StackEmployeeContainer result1;
    std::string id = "1";
    // auto itr =std::find_if(
    //     data1.begin(),data1.end(),
    //     [&](const Employee& emp){return emp.id()==id;}
    // );
    if(StackEmployeeContainer::const_iterator itr = FetchById(id,data1);itr == data1.end()){
        std::cerr << "data with matching id is not found\n";
    }
    else{
        std::cout<<(*itr).name()<<"\n";
    }
}
