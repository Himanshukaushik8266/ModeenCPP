/*
    Smart Pointers : They are wrappers around raw pointers to allow better memory management using RAII design pattern
    
    std::jthread (CPP20) 
        
        
        1) shared_pointer
        2) unique_pointer
        3) weak_pointer : stalker pointer [shared pointer---->token]
*/

/*
    <----------------20 bytes-------------->
    [                                       ]
    <-------12bytes--------><-----8 bytes---->
            ptr1                   ptr2

*/

#include<iostream>
#include "Employee.h"
#include<mutex>
#include<thread>

#include<memory>
std::mutex mt;
bool allThreadsDone{false};



// void ChangeName(std::shared_ptr<Employee> owner2){
//     owner2->setName("Himanshu Kaushik");
//     std::lock_guard<std::mutex> lg(mt);
//     std::cout<<*owner2<<std::endl;


// }

// void UpdateSalary(std::shared_ptr<Employee> owner3){
//     owner3->setSalary(1000.0f);
//     std::lock_guard<std::mutex> lg(mt);
//     std::cout<<*owner3<<std::endl;
// }


// int main(){
//     std::shared_ptr<Employee> ptr=std::make_shared<Employee>("Himanshu",19000.0f,"Trainee",1);

//     std::thread t1(&ChangeName,ptr);
//     std::thread t2(&UpdateSalary,ptr);

//     if(std::lock_guard<std::mutex> lg(mt); !allThreadsDone){
//         std::cout<<*ptr<<std::endl;
//     }   

//     t1.join();
//     t2.join();

//     allThreadsDone=true;
//     return 0;
// }


void ChangeName(std::unique_ptr<Employee> &owner2){
    owner2->setName("Himanshu Kaushik");
    std::lock_guard<std::mutex> lg(mt);
    std::cout<<*owner2<<std::endl;


}

void UpdateSalary(std::unique_ptr<Employee> & owner3){
    owner3->setSalary(1000.0f);
    std::lock_guard<std::mutex> lg(mt);
    std::cout<<*owner3<<std::endl;
}


int main(){
    std::unique_ptr<Employee> ptr=std::make_unique<Employee>("Himanshu",19000.0f,"Trainee",1);

    std::thread t1(&ChangeName,std::ref(ptr));
    std::thread t2(&UpdateSalary,std::ref(ptr));

    if(std::lock_guard<std::mutex> lg(mt); !allThreadsDone){
        std::cout<<*ptr<<std::endl;
    }   

    t1.join();
    t2.join();

    allThreadsDone=true;
    return 0;
}