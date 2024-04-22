#include<iostream>
#include "Employee.h" //copy are deleted and move are as usual default

Employee Magic(){
    Employee e1("Harshit", 78080.0f,"Trainer", 10);
    return e1;
}

int main(){

    Employee emp=Magic();
    std::cout<<emp;

    return 0;

}