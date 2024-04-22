#include "Functionalities.h"
#include<iomanip>
int main()
{
    std::cout<<std::setprecision(2)<<std::fixed;
    Container data;
    CreateObjects(data);
    // DisplayObjects(data);

    std::cout<<"Average of Employee of Particular Manager : "<<AverageofEmployeeUnderManager(data,"Shreya")<<std::endl;

    std::cout<<"Name of manager for given EmployeeId is : "<<FindManagerUsingEmpid(data,"E-102")<<std::endl;


    return 0;
}