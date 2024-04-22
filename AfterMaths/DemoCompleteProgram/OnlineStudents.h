#ifndef ONLINESTUDENTS_H
#define ONLINESTUDENTS_H
#include <iostream>
#include <vector>
#include "Gender.h"

class OnlineStudents
{
private:
    /* data */
    int _studId;
    std::string _name;
    std::vector<int> _marks;
    Gender _gender;

public:
    OnlineStudents() = default;
    OnlineStudents(const OnlineStudents &) = delete;
    OnlineStudents(OnlineStudents &&) = delete;
    OnlineStudents &operator=(const OnlineStudents &) = delete;
    OnlineStudents &operator=(OnlineStudents &&) = delete;
    ~OnlineStudents() = default;

    OnlineStudents(int studId, std::string name, std::vector<int> marks, Gender gender);

    friend std::ostream &operator<<(std::ostream &os, const OnlineStudents &rhs);

    bool Ispass();
};

#endif // ONLINESTUDENTS_H
