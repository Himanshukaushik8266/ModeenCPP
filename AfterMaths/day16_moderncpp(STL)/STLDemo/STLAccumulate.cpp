//total of emp sal for all instances in the container
#include "Functionalities.h"
#include<numeric>
//accumulate performs a successsive binary operation on answer upto previous step with the next 
//instance frmo data and produces one consildatede(aggregated) final value

int main(){
    StackEmployeeContainer data1;
    EmployeePointerContainer data2;
    EmployeeSmartPointerContainer data3;
    CreateObjects(data1);
    CreateObjects(data2);
    CreateObjects(data3);

    float final_answer = std::accumulate(data1.begin(),data1.end(),0.0f,[](float answer_upto_current_point, const Employee& emp){
        return answer_upto_current_point + emp.salary();
    });
    std::cout<<"total is: "<<final_answer<<"\n";

    float final_answer2 = std::accumulate(data2.begin(),data2.end(),0.0f,[](float answer_upto_current_point, const Employee* emp){
        return answer_upto_current_point + emp->salary();
    });
    std::cout<<"total is: "<<final_answer2<<"\n";

    float final_answer3 = std::accumulate(data3.begin(),data3.end(),0.0f,[](float answer_upto_current_point, const std::shared_ptr<Employee> emp){
        return answer_upto_current_point + emp->salary();
    });
    std::cout<<"total is: "<<final_answer3<<"\n";
    double a = std::accumulate(data1.begin(),data1.end(),1.0,[](double product,const Employee& emp1){
        return product + emp1.age();
    });
    std::cout<< a<<"\n";
}
//binary argument in accumulate takes arguments in a sequence p1 is answer upto curr point, p2 is