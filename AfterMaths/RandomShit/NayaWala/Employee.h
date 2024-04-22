#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include "Project.h"
#include<functional>
#include <ostream>
class Employee
{
private:
    /* data */
    int _empId;
    std::string _empName;
    std::reference_wrapper<Project> _project;
public:
    Employee()=default;
    Employee(const Employee &)=delete;
    Employee (Employee &&)=delete;
    Employee &operator=(const Employee &)=delete;
    Employee &operator=(Employee &&)=delete;
    ~Employee()=default;

    Employee(int id,std::string name,std::reference_wrapper<Project> project):_empId{id},_empName{name},_project{project}{}

    friend std::ostream &operator<<(std::ostream &os, const Employee &rhs) {
        os << "_empId: " << rhs._empId
           << " _empName: " << rhs._empName
           << " _project: " << rhs._project.get();
        return os;
    }
};

#endif // EMPLOYEE_H
