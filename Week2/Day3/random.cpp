#include<iostream>
#include<vector>
using FunType=int(*)(int number);
int Square(int number){
    return number *number;
}
int Cube(int number){
    return number*number*number;
}

void Magic(int(*ptr)(int number), int data){
    std::cout<<ptr(data)<<std::endl;
}

int main(){

    Magic(Square,10);
    Magic(Cube,30);

    // int(*ptr)(int number)=[](int number){return number*3;};
    // std::cout<<ptr(90)<<std::endl;

    std::vector<FunType> data{
        [](int number){return number*3;},
        [](int number){return number*4;}

    };
    for(FunType f:data){
        std::cout<<f(67)<<std::endl;
    }

    return 0;

}