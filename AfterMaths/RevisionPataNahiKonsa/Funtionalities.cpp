#include "Funtionalities.h"

void Adaptor(FnType &fn, int a, int b)
{
    fn(a,b);
}

FnType Square=[](int a,int b){
    std::cout<<"Sqaure of first number is : "<<a*a<<std::endl;
    std::cout<<"Sqaure of second number is : "<<b*b<<std::endl;
};

FnType Cube=[](int a,int b){
    std::cout<<"Cube of first number is : "<<a*a*a<<std::endl;
    std::cout<<"Cube of second number is : "<<b*b*b<<std::endl;
};


auto BindedSquare=std::bind(Square,109,std::placeholders::_1);


