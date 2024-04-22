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
    std::vector<int> data {11,19,14,17,21,16,28};

    auto itr = data.begin();
    std::vector<int>::iterator it = std::next(itr,data.size()-3);
    std::vector<int>::iterator result = std::find_if(
        itr,
        data.end(),
        [](int number){return number%3==0;}
    );
    std::cout<<*result<<"\n";
    //find 1stnumber divisible by 7 amongst the last 3 integeres in input
    // objective : move initial iterator to 3rd element
    //process:

    //size : 7
    //destination 3rd last [4]
    //beginning : 11 [0]
}
     