#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include<iostream>
class Employee
{
private:
    /* data */
    int _id{1};
    std::string _employeeName{"This name"};
    
public:
    Employee() =default;

    Employee(int id, std::string name):_id{id},_employeeName{name}{}
    ~Employee() {}

    int id() const { return _id; }
    void setId(int id) { _id = id; }

    std::string employeeName() const { return _employeeName; }
    void setEmployeeName(const std::string &employeeName) { _employeeName = employeeName; }

    friend std::ostream &operator<<(std::ostream &os, const Employee &rhs);

};

inline std::ostream &operator<<(std::ostream &os, const Employee &rhs) {
    os << "_id: " << rhs._id
       << " _employeeName: " << rhs._employeeName;
    return os;
}

#endif // EMPLOYEE_H
