#ifndef DEVELOPER_H
#define DEVELOPER_H
#include<string>
#include <ostream>
#include "Skills.h"
class Developer
{
private:
    /* data */
    std::string _id;
    std::string _name;
    float _salary;
    int _experience_years;
    Skills _skills;
public:
    Developer() = delete;
    Developer(const Developer&) = delete;
    Developer& operator=(const Developer&) = delete;
    Developer(Developer&&) = delete;
    Developer& operator=(Developer&&) = delete;
    ~Developer() {}

    Developer(std::string id, std::string name, float salary, int experience, Skills skills);
    std::string id() const { return _id; }

    std::string name() const { return _name; }

    float salary() const { return _salary; }

    int experienceYears() const { return _experience_years; }

    Skills skills() const { return _skills; }

    friend std::ostream &operator<<(std::ostream &os, const Developer &rhs);

    float CalculateBonus();
};

#endif // DEVELOPER_H
