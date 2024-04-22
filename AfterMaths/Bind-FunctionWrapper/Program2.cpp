#include<iostream>
#include "Functionalities.h"


int main(){

    function("Hell",std::vector<int> {1,2,3,4,5}, "World");
    bindedfunction( "Hell",std::vector<int> {1,2,3,4,5}, "World");
    
    return 0;

}