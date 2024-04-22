#include<iostream>
#include<vector>
#include<functional>
/*
    Objective: 
        Design an Adaptor function that excepts a conatiner of function wrapper and a container of data values
        Map each function on each data member in the function.
        All function must accept only an integer and return void

*/


void Adaptor(const std::vector<std::function<void(int)>> &functions,const std::vector<int> &data ){
    int i=1;
    for(std::function<void(int)> f:functions){
        for(int d:data){
            f(d);
        }
        std::cout<<"*******Function "<<i<<" End****************\n";
        i++;
    }
}

int main(){

    std::vector<std::function<void(int)>> functions {
        [](int number){std::cout<<"number *10 is : "<<number*10<<std::endl;},
        [](int number){std::cout<<"number *20 is : "<<number*20<<std::endl;}
    };


    std::vector<int> data {10,20,30};

    Adaptor(functions,data);
    
    return 0;

}