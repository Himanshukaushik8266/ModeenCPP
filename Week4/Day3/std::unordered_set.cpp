/*
    11,12,11,14,11,13
    has function : Mod 4

    11%4 = 3 
    12%4 = 0
    11%4 = 3 ///key already exists!

    hash table of set has same value of key and value are stored 
*/

#include<iostream>
#include<unordered_set>

int main(){

    std::unordered_set<int> s1 {11,12,11,13,11,14};
    for(int i:s1){
        std::cout<<i<<std::endl;
    }
    std::cout<<std::boolalpha<<s1.insert(10).second<<std::endl;
    return 0;
}



