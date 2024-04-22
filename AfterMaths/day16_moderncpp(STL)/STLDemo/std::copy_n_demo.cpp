#include<iostream>
#include "Functionalities.h"
#include<algorithm>

int main(){
    StackEmployeeContainer data1;
    EmployeePointerContainer data2;
    EmployeeSmartPointerContainer data3;
    CreateObjects(data1);
    StackEmployeeContainer result1;

    std::copy_n(
        data1.begin(),
        2,
        std::inserter(result1,result1.begin())
    );
    if(result1.size()==2){
        std::cout<<"elements copied\n";
    }
        std::cout<<result1[0].age()<<"\n";
}

/* 
input :1,2,3,4,5
N=3
result [no mem in it]
 */