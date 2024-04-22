#include "Fun.h"
#include "EmptyContainerException.h"
#include<iostream>

int main(int argc, char const *argv[])
{
    Container data;
    CreateObjects(data);
    std::optional<Container> ans = InstancesAbove5(data);
    if(ans.has_value()){
        for(auto v : ans.value()){
            std::visit([](auto&& val){std::cout<<*val<<"\n";}, v);
        }
    }else{
        std::cout<<"Chud gaye"<<std::endl;
    }

    std::optional<float> avgsal = CalAverageSal(data);
    if(avgsal.has_value()){
        std::cout<<"Average salary is "<<avgsal.value()<<"\n";
    }
    else{
        
    }
    return 0;
}
