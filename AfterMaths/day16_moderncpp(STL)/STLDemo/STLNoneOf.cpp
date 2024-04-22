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
    bool count1 = std::none_of(data1.begin(),data1.end(),[](const Employee& emp)->bool{
        return emp.salary()>60000.0f;
    });
    std::size_t count2 = std::none_of(data2.begin(),data2.end(),[](const Employee* emp)->bool{
        return emp->salary()>60000.0f;
    });
    std::size_t count3 = std::none_of(data3.begin(),data3.end(),[](const std::shared_ptr<Employee>& emp)->bool{
        return emp->salary()>60000.0f;
    });
    std::cout<<"count1 is: "<<std::boolalpha<<count1<<"\n";
    std::cout<<"count2 is: "<<count2<<"\n";
    std::cout<<"count3 is: "<<count3<<"\n";
}
