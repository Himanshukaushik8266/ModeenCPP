/*
    TaxPayers: Employees, BusinessOwners
    Number of child classes will be fixed if we want to use variants


    Algebraic Data type(ADT)
    Variant is also an ADT.


    using variants for runtime polymorphism is called functional polymorphism

*/

#include <iostream>
#include <iomanip>
#include <array>
#include <variant>

class Employee;
class BusinessOwner;

using VType = std::variant<Employee *, BusinessOwner *>;
using Container = std::array<VType, 2>;

class BusinessOwner
{
private:
    std::string _name;
    std::string _comanyGSTnumber;
    float _revenue;
    float _expenses;

public:
    BusinessOwner() = default;
    BusinessOwner(const BusinessOwner &) = delete;
    BusinessOwner(BusinessOwner &&) = delete;
    BusinessOwner &operator=(const BusinessOwner &) = delete;
    BusinessOwner &operator=(BusinessOwner &&) = delete;
    ~BusinessOwner() = default;

    BusinessOwner(std::string name, std::string gst, float rev, float exp) : _name{name}, _comanyGSTnumber{gst}, _revenue{rev}, _expenses{exp} {}

    float CalculateTaxAmount()
    {
        return 0.3f * (_revenue - _expenses);
    }

    std::string name() const { return _name; }
    void setName(const std::string &name) { _name = name; }

    float revenue() const { return _revenue; }
    void setRevenue(float revenue) { _revenue = revenue; }
};
class Employee
{
private:
    std::string _name;
    float _salary;

public:
    Employee() = default;
    Employee(const Employee &) = delete;
    Employee(Employee &&) = delete;
    Employee &operator=(const Employee &) = delete;
    Employee &operator=(Employee &&) = delete;
    ~Employee() = default;

    Employee(std::string name, float sal) : _name{name}, _salary{sal} {}

    std::string name() const { return _name; }
    void setName(const std::string &name) { _name = name; }

    void Display()
    {
        std::cout << std::setprecision(2) << std::fixed << _salary << std::endl;
    }
};

void CommonAction(Container &arr)
{
    for (VType v : arr)
    {
        std::visit([](auto &&val)
                   { std::cout << val->name() << "\n"; },
                   v);
        /*  auto &&val----------------> Template parameter for lambda */
    }
}

void NotSoCommonAction(Container &arr)
{

    for (VType v : arr)
    {
        if (std::holds_alternative<BusinessOwner *>(v))
        {
            BusinessOwner *ow = std::get<1>(v);
            std::cout << ow->CalculateTaxAmount() << std::endl;
        }
        if (std::holds_alternative<Employee *>(v))
        {
            Employee *em = std::get<0>(v);
            em->Display();
        }
    }
}

int main()
{
    Employee *emp = new Employee("himanshu", 25000.0f);
    BusinessOwner *bow = new BusinessOwner("Muskan Limited", "05AKK783623", 10560070.0f, 34000.0f);
    Container arr{emp, bow};

    CommonAction(arr);
    NotSoCommonAction(arr);

    return 0;
}
/*
    Employee | Business                         Employee | Business

    [ 0x100H  |  //////// ]                     [ /////// | 0x987H ]

    <------------------------------arr------------------------------>


    Both slot can't fill at the same time


    Scenario 1 : I want to execute a function that present in all types of variant
            e.g getter for name(just open the variant and call getter)

    Scenario 2 : You want to call a function that only exists in some but not all type of variant
        -> for variants in array check whether variant has Employee and perform action else continue
*/