#include "Functionalities.h"

int main()
{
    EmployeeContainer employees;
    ProjectsContainer projects;

    CreateObjects(employees, projects);

    DisplayObjects(employees);

    return 0;
}