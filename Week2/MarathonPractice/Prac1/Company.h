#ifndef COMPANY_H
#define COMPANY_H
#include<iostream>
#include<functional>
#include "Employee.h"

class Company
{
private:
    /* data */
    std::string _companyName;
    std::reference_wrapper<Employee> _employee;    
public:
    Company() =default;
    Company (const Company &)=delete;
    Company(const Company &&)=delete;
    Company & operator=(const Company &)=delete;
    Company & operator=(const Company &&)=delete;
    Company(std:: string name, std::reference_wrapper<Employee> employee):_companyName{name},_employee{employee}{}
    ~Company()=default;

    void display(){
        std::cout<<_employee.get().id()<<std::endl;
    }

    friend std::ostream &operator<<(std::ostream &os, const Company &rhs);
};

inline std::ostream &operator<<(std::ostream &os, const Company &rhs) {
    os << "_companyName: " << rhs._companyName
       << " _employee: " << rhs._employee;
    return os;
}

#endif // COMPANY_H
