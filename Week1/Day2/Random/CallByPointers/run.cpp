#include<bits/stdc++.h>

/*
    int &a : reference
    &a :  no data type to left of a : address (pointer)
*/

void Magic(int * value){
    std::cout<<"Value in Magic before modification is: "<<*value<<std::endl;
    std::cout<<"Address of value inside Magic is : "<<value<<std::endl;
    *value=111;
    std::cout<<"Value in Magic after modification is : "<<*value<<std::endl;
    

}
int main(){
    int value=100;
    std::cout<<"Value in Main before modification is: "<<value<<std::endl;
    std::cout<<"Address of value inside Main is : "<<&value<<std::endl;
    Magic(&value);
    std::cout<<"Value in Main after modification is : "<<value<<std::endl;
    return 0;

}