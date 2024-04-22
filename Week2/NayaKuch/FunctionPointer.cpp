#include<iostream>
#include<functional>
#include<vector>
using Container=std::vector<int(*)(int number)>;

using FunctionalConatiner=std::vector<std::function<int(int)>>;


int Square(int number){
    return number * number;
}

int Cube(int number){
    return number * number * number;
}

void Adaptor(FunctionalConatiner &data, int number){
    for(std::function<int(int)> i :data){
        std::cout<<i(number)<<std::endl;
    }
}


int main(){

    auto f1=std::bind(&Square,std::placeholders::_1);

    FunctionalConatiner data{Cube,f1};
    Adaptor(data,78);

    
    return 0;

}