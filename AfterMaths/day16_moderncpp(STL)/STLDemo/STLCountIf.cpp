//counts the number of data instances matching the specified condition
#include<algorithm>
#include "Functionalities.h"

int main(){
    StackEmployeeContainer data1;
    EmployeePointerContainer data2;
    EmployeeSmartPointerContainer data3;
    CreateObjects(data1);
    CreateObjects(data2);
    CreateObjects(data3);
    ///////////////////////////////
    std::size_t count1 = std::count_if(data1.begin(),data1.end(),[](const Employee& emp)->bool{
        return emp.salary()>60000.0f;
    });
    std::size_t count2 = std::count_if(data2.begin(),data2.end(),[](const Employee* emp)->bool{
        return emp->salary()>60000.0f;
    });
    std::size_t count3 = std::count_if(data3.begin(),data3.end(),[](const std::shared_ptr<Employee>& emp)->bool{
        return emp->salary()>60000.0f;
    });
    std::cout<<"count1 is: "<<count1<<"\n";
    std::cout<<"count2 is: "<<count2<<"\n";
    std::cout<<"count3 is: "<<count3<<"\n";
}

