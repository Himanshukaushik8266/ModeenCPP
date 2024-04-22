#include "Functionalities.h"

void Adaptor(FnType fn, Container &data)
{
    if(data.empty()){
        throw std::runtime_error("Data is not available for adaptor");
    }
        fn(data);
}

FnType lfn1=[](Container& data){std::cout<<data.front()<<std::endl;};
FnType lfn2=[](Container& data){std::cout<<data.back()<<std::endl;};
FnType lfn3=[](Container& data){std::cout<<data.size()<<std::endl;};

void Square(int i){
    std::cout<<i*i<<std::endl;
}

std::function<void(int)> binded_wrapper=std::bind(&Square,std::placeholders::_1);