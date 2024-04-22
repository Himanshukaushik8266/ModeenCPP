#include<iostream>
#include "Functionalities.h"
#include<algorithm>
#include<unordered_set>
#include<vector>
#include<functional>
int main(){
    std::unordered_set<int> arr;
    arr.emplace(1);
    arr.emplace(1);
    arr.emplace(2);
    arr.emplace(1);
    for(auto i:arr){
        std::cout<<i<<"\n";
    }

    // StackEmployeeContainer data1;
    // EmployeePointerContainer data2;
    // EmployeeSmartPointerContainer data3;
    // CreateObjects(data1);
    
    // std::vector<int> result;
    // std::vector<int> data {11,19,14,17,21,16,28};
    // std::transform(data.begin(),data.end(),
    // std::inserter(result,result.begin()),
    // [](int num){return num*num;}
    // );
    // for(auto res:result){
    //     std::cout<<res<<"\n";
    // }
}
     