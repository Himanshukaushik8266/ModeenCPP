#include<iostream>
#include "Functionalities.h"
#include<algorithm>

int main(){
    StackEmployeeContainer data1;
    EmployeePointerContainer data2;
    EmployeeSmartPointerContainer data3;
    CreateObjects(data1);
    StackEmployeeContainer result1;

    std::copy_if(
        data1.begin(),
        data1.end(),
        std::inserter(result1,result1.begin()),
        [](const Employee& emp){return emp.location()=="pune";}
    );
    if(result1.size()==0){
        std::cout<<"no matching element found\n";
    }
    
    
}
