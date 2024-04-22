#include "Functionalities.h"

void CreateObjects(StackEmployeeContainer &data)
{
    data.push_back(Employee("1","tanmay",10000.0f,22,"pune"));
    data.push_back(Employee("2","john",20000.0f,23,"goa"));
    data.push_back(Employee("3","alice",30000.0f,24,"mumbai"));
    data.push_back(Employee("4","abel",4500.0f,43,"new york"));
    data.push_back(Employee("5","george",450000.0f,33,"new york"));
}

void CreateObjects(EmployeePointerContainer &data)
{
    data.push_back(new Employee("10","tanmay",10000.0f,22,"pune"));
    data.push_back(new Employee("20","john",20000.0f,23,"goa"));
    data.push_back(new Employee("30","alice",30000.0f,24,"mumbai"));
    data.push_back(new Employee("30","alice",30000.0f,24,"mumbai"));
    data.push_back(new Employee("30","alice",30000.0f,24,"mumbai"));
}

void CreateObjects(EmployeeSmartPointerContainer &data)
{
    data.push_back(std::make_shared<Employee>("11","tanmay",10000.0f,22,"pune"));
    data.push_back(std::make_shared<Employee>("22","john",20000.0f,23,"goa"));
    data.push_back(std::make_shared<Employee>("33","alice",30000.0f,24,"mumbai"));
    data.push_back(std::make_shared<Employee>("44","alice",30000.0f,24,"mumbai"));
    data.push_back(std::make_shared<Employee>("55","alice",30000.0f,24,"mumbai"));
}
