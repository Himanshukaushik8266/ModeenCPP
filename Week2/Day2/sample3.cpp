/*
    Objectves : Design an adaptor to accept
    a vector of integers
    a predicate function that return true or false based on a single input
    use the predicate {takes one arguments and return true or false} to print data from vector

*/

#include<iostream>
#include<functional>

void Operator(std::function<bool(int)> predicate,const std::vector<int> &data){
    for(int val :data){
        if(predicate(val)){
            std::cout<<val<<" ";
        }
    }
    std::cout<<std::endl;
}

int main(){

    Operator(
        [](int number){return number%5==0;},
        std::vector<int> {10,20,46,30,26}
    );
    Operator(
        [](int number){return number%5==0 && number%3==0;},
        std::vector<int> {10,20,46,30,26}
    );
    
    return 0;
}