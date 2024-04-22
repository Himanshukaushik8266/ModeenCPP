#ifndef TEACHER_H
#define TEACHER_H
#include <iostream>
#include <variant>
#include <vector>
#include "OnlineStudents.h"
#include "OfflineStudents.h"
#include<memory>

using OnlinePointer=std::shared_ptr<OnlineStudents>;
using OfflinePointer =std::shared_ptr<OfflineStudents>;
using VarType = std::variant<OnlinePointer,OfflinePointer>;


class Teacher
{
private:
    /* data */
    int _empId;
    std::string _name;
    std::vector<VarType> _students;
    public : 
    Teacher()=default;
    Teacher(const Teacher &)=delete;
    Teacher(Teacher && )=delete;
    Teacher & operator=(const Teacher & )=delete;
    Teacher &operator=(Teacher &&)=delete;
    ~Teacher()=default;



    Teacher(int empId,std::string name,std::vector<VarType> students);

    std::string name() const { return _name; }

    int empId() const { return _empId; }

    std::vector<VarType> students() const { return _students; }

    friend std::ostream &operator<<(std::ostream &os, const Teacher &rhs);
};

#endif // TEACHER_H



