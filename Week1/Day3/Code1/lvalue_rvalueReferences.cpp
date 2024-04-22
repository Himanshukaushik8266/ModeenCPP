#include<iostream>
#include<list>
void Magic(std::list<int> & data){

}
/*
    1) Weird magic function can only be called by a rvalue 
        -> It means the user will never be able to have two copies of data.
            One in caller(Main) function and one in callee(WeirdMagic)
    2)  
*/
void WeirdMagic(std::list<int> && data){

}
int main(){

    std::list<int> l1{1,2,3,4,5}; //100 bytes of heap allocation

    Magic(l1);      //call by lvalue //move will convert this lvalue----->rvalue

    WeirdMagic(std::list<int>{1,2,3,4,5}); //call by rvalue
    return 0;

}