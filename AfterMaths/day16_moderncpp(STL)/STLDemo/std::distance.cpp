#include<iostream>
#include "Functionalities.h"
#include<algorithm>
#include<vector>

int main(){
    StackEmployeeContainer data1;
    EmployeePointerContainer data2;
    EmployeeSmartPointerContainer data3;
    CreateObjects(data1);
    StackEmployeeContainer result1;
    
    std::vector<int> v {11,19,14,17,21,16,28};
    std::vector<int>::iterator itr = std::find_if(
        v.begin(),v.end(),
        [](int number){return number%3==0;}
    );
    std::cout<< std::distance(v.begin(),itr);

}
