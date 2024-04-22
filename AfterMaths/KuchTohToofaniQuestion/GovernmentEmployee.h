#ifndef GOVERNMENTEMPLOYEE_H
#define GOVERNMENTEMPLOYEE_H
#include "Employee.h"
#include <ostream>

class GovernmentEmployee : public Employee
{
private:
    /* data */
    int _id{0};

public:
    GovernmentEmployee() = default;
    GovernmentEmployee(const GovernmentEmployee &) = delete;
    GovernmentEmployee(GovernmentEmployee &&) = delete;
    GovernmentEmployee &operator=(const GovernmentEmployee &) = delete;
    GovernmentEmployee &operator=(GovernmentEmployee &&) = delete;
    ~GovernmentEmployee() = default;

    GovernmentEmployee(int id, std::string name, unsigned int age, Gender gender, EmployeeType post, float salary);

    float CalculateTaxes() override;

    int id() const { return _id; }

    friend std::ostream &operator<<(std::ostream &os, const GovernmentEmployee &rhs);

};

#endif // GOVERNMENTEMPLOYEE_H
