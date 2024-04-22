#include<iostream>

#include<array>
int main(){

    std::array<int,2> data{101,90000};
    auto & [empId,empSalary]=data;     //structured binding


    return 0;

}