/*
    std::optional : Indicates an algebraic data type that may
                    -either contain a valid value
                    -or a symbol indicating "Absence Of Information"


    FindOddNumbers is a fucntion taht optionally returns a std::vector<int>

    OR

    FindOddNumbers may or may not retrun a vector of integer to the user
*/

#include <iostream>
#include <vector>
#include <optional>
 
std::optional<std::vector<int>> FindOddNumbes(std::vector<int> &data){
    if(data.empty()){
        throw std::runtime_error("Data is empty");
    }
    std::vector<int> result;
    for(int i : data){
        if(i%2!=0) result.push_back(i);
    }
    if(result.empty()){
        return std::nullopt; //Symbol to indicate no information
    }
    return result;
}
int main(){
    std::vector<int> data ;
    std::optional<std::vector<int>> result;
    try{
        result = FindOddNumbes(data);
    }
    catch(std::runtime_error &e){
        std::cout<<e.what()<<std::endl;
    }
    //std::cout<<result[0]<<std::endl; //This wont be allowed as you have optional so you have to write in ifelse
    if(result.has_value()){
        std::cout<<result.value()[0]<<std::endl;
    }
    else{
        std::cout<<"haye raam"<<std::endl;
    }
}