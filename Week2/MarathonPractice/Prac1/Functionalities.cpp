#include "Functionalities.h"

void CreateObjects(CompanyContainer &Companydata, EmployeeConatiner &Employeedata)
{
    Employeedata.push_back(new Employee(1,"Himanshu"));

    Companydata.push_back(new Company("KPIT",*Employeedata[0]));

}

void PrintObjects(const CompanyContainer &data){
    for(Company * c:data){
        std::cout<<*c<<std::endl;
    }
}
void Deletecompany(CompanyContainer &data){
    for(Company * c:data){
        delete c;
    }
}

void Deleteemployee(EmployeeConatiner &data)
{
    for(Employee * e:data){
        delete e;
    }
}
