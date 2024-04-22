#ifndef CORPORATEEMPLOYEE_H
#define CORPORATEEMPLOYEE_H
#include "Employee.h"
#include <ostream>

class CorporateEmployee : public Employee
{
private:
    /* data */
    std::string _id{""};

public:
    CorporateEmployee() = default;
    CorporateEmployee(const CorporateEmployee &) = delete;
    CorporateEmployee(CorporateEmployee &&) = delete;
    CorporateEmployee &operator=(const CorporateEmployee &) = delete;
    CorporateEmployee &operator=(CorporateEmployee &&) = delete;
    ~CorporateEmployee() = default;

    CorporateEmployee(std::string id, std::string name, unsigned int age, Gender gender, EmployeeType post, float salary);

    float CalculateTaxes() override;

    std::string id() const { return _id; }

    friend std::ostream &operator<<(std::ostream &os, const CorporateEmployee &rhs);
};

#endif // CORPORATEEMPLOYEE_H
