/*
    Hastable (Employee ID)
    value is Employee object on stack
*/

#include<iostream>
#include<unordered_map>
#include "Employee.h"
#include "Functionalities.h"

void Display(const std::unordered_map<int,Employee> & mapData){
    for(auto[key,value] :mapData){
        std::cout<<key<<"\t"<<value<<"\n";
    }
}
void CreateObjects(std::unordered_map<int,Employee> & mapData){
    mapData.emplace(101,Employee("Himanshu", 50000.0f, "Trainee", 1));
    mapData.emplace(102,Employee("Vikas", 35000.0f, "Trainer", 5));

}


/**************************************************************************************************/

void DisplayPointer(const std::unordered_map<int,Employee*> & mapData){
    for(auto[key,value] :mapData){
        std::cout<<key<<"\t"<<*value<<"\n";
    }
}
void CreatePointerObjects(std::unordered_map<int,Employee*> & mapData){
    mapData.emplace(101,new Employee("Himanshu", 50000.0f, "Trainee", 1));
    mapData.emplace(102,new Employee("hikjngb", 35000.0f, "Trainer", 5));

}

int main(){
    
    std::unordered_map<int, Employee> mapData;
    CreateObjects(mapData);
    Display(mapData);

    std::cout<<"************************************************"<<std::endl;

    std::unordered_map<int,Employee *>mapData2;
    CreatePointerObjects(mapData2);
    DisplayPointer(mapData2);
    
    return 0;

}