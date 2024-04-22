#ifndef TESTER_H
#define TESTER_H
#include<string>
#include <ostream>
#include "Skills.h"

class Tester
{
private:
    /* data */
    std::string _id;
    std::string _name;
    float _salary;
    int _experience_years;
    Skills _skills;
public:
    Tester() = delete;
    Tester(const Tester&) = delete;
    Tester& operator=(const Tester&) = delete;
    Tester(Tester&&) = delete;
    Tester& operator=(Tester&&) = delete;
    ~Tester() {}

    Tester(std::string id, std::string name, float salary, int experience, Skills skills);

    std::string id() const { return _id; }

    std::string name() const { return _name; }
    void setName(const std::string &name) { _name = name; }

    float salary() const { return _salary; }

    int experienceYears() const { return _experience_years; }

    Skills skills() const { return _skills; }

    friend std::ostream &operator<<(std::ostream &os, const Tester &rhs);
    float CalculateBonus();
};

#endif // TESTER_H
