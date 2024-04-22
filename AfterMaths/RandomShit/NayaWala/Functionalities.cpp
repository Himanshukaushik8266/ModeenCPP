#include "Functionalities.h"

void CreateObjects(EmployeeContainer &employees, ProjectsContainer &projects)
{
    Project *p1=new Project("ADAS HillAssist");
    // ,p2("BMW Infotainment"),p3("Local Drive");
    projects.push_back(std::ref(*p1));
    // projects.push_back(std::ref(*p2));
    // projects.push_back(std::ref(*p3));

    //Creating Employees using the projects vector
    employees.push_back(std::make_shared<Employee>(101,"Himanshu Kaushik",projects[0]));
//     employees.push_back(std::make_shared<Employee>(102,"Priyanshu Joshi",projects[1]));
//     employees.push_back(std::make_shared<Employee>(103,"Manthan Nanda",projects[2]));

    delete p1;
}

void DisplayObjects(EmployeeContainer &employees)
{
    for(std::shared_ptr<Employee> ptr:employees){
        std::cout<<*ptr<<std::endl;
    }
}
