#include <iostream>
#include <vector>
#include <memory>
#include <functional>
class Employee;

using EmployeePointer=std::shared_ptr<Employee>;


class Employee
{
private:
    int _id;
    std::string _name;
    float _salary;

public:
    Employee() = default;
    Employee(const Employee &) = delete;
    Employee(Employee &&) = delete;
    Employee &operator=(const Employee &) = delete;
    Employee &operator=(Employee &&) = delete;
    ~Employee() = default;

    Employee(int id, std::string name, float salary) : _id{id}, _name{name}, _salary{salary} {}

    float operator+(const Employee &rhs)
    {
        return _salary + rhs._salary;
    }

    float operator-(const Employee &rhs)
    {
        return _salary - rhs._salary;
    }

    void operator()()
    {
        std::cout << "Tax for this employee at 10% is : " << _salary * 0.1f;
    }

    float salary() const { return _salary; }

    friend std::ostream &operator<<(std::ostream &os, const Employee &rhs)
    {
        os << "_id: " << rhs._id
           << " _name: " << rhs._name
           << " _salary: " << rhs._salary;
        return os;
    }
};

void Adaptor(
    const std::vector<EmployeePointer> &data,
    std::function<bool(EmployeePointer)> predicate)
{
    for (EmployeePointer ptr : data)
    {
        if (predicate(ptr))
        {
            std::cout << *ptr << "\n";
        }
    }
}

int main()
{

    std::vector<EmployeePointer> data{
        std::make_shared<Employee>(101, "Harshit", 88000.0f),
        std::make_shared<Employee>(101, "Ajay", 98800.0f)};

    Adaptor(
        data,
        [](EmployeePointer emp)
        { return emp->salary() > 8000.0f; });

    return 0;
}