#ifndef OFFLINESTUDENTS_H
#define OFFLINESTUDENTS_H
#include <iostream>
#include <vector>
#include "Gender.h"
class OfflineStudents
{
private:
    /* data */
    int _studId;
    std::string _name;
    std::vector<int> _marks;
    Gender _gender;

public:
    OfflineStudents() = default;
    OfflineStudents(const OfflineStudents &) = delete;
    OfflineStudents(OfflineStudents &&) = delete;
    OfflineStudents &operator=(const OfflineStudents &) = delete;
    OfflineStudents &operator=(OfflineStudents &&) = delete;
    ~OfflineStudents() = default;

    OfflineStudents(int studId, std::string name, std::vector<int> marks, Gender gender);

    friend std::ostream &operator<<(std::ostream &os, const OfflineStudents &rhs);
   
   
    bool Ispass();
};

#endif // OFFLINESTUDENTS_H
