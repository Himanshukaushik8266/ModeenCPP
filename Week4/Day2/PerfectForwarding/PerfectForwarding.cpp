#include<iostream>
#include "Employee.h"
/*
    the middlemen/intermediate functions will have to designed to accept 0 or more argument (potentially infinite)
*/

// Demo(int &&n2){

// }

void Magic(int && n1){ //10 gets assigned to n1. now n1 is lvalue!
    //forwarding n1 to any function will now forward n1 a lvalue rather than rvalue
 
    //Demo(n1) // lvalue passed to rvalue reference ------> not work!
    std::cout<<"The value of n1 is : "<<n1<<std::endl;
}


template <typename T, typename... Args>
T Relay(Args&&... args){
    return T(std::forward<Args>(args)...);
}


int main(){

    // Magic(10);//10 is rvalue in the scope of main

    Employee obj=Relay<Employee>("Himanshu", 50000.0f, "Trainee", 1);

    std::cout<<obj.salary()<<std::endl;


    Magic(Relay<int>(10)); 
    


    return 0;

}
