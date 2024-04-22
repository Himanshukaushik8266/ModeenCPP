/*
    If there is multiple owners of the same resource then we should have a way to track how many owners of the resource exists.

*/
#include "Employee.h"
#include<iostream>
#include<memory>
#include<thread>
 
std::shared_ptr<Employee> sptr;
 
void Magic(std::shared_ptr<Employee> owner2){
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout<<*owner2<<"\n";
}
 
int main(int argc, char const *argv[])
{
    /* code */
    sptr = std::make_shared<Employee>("Kshitij", 3423.0f, "Trainee", 10);
    Magic((sptr));
 
    std::weak_ptr<Employee> wkptr = sptr;
 
    if(wkptr.lock()){
        std::cout<<"owner zinda hai\n";
    }else{
        std::cout<<"Owner toh gaya\n";
    }
 
    sptr.reset();
 
    if(wkptr.lock()){
        std::cout<<"owner zinda hai\n";
    }else{
        std::cout<<"Owner toh gaya\n";
    }
 
    return 0;
}