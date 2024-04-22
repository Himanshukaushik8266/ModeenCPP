#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
class Customer
{
private:
    /* data */
    std::string _name;
    int _age;

public:
    Customer() = default;
    Customer(const Customer &) = delete;
    Customer(Customer &&) = delete;
    Customer &operator=(const Customer &) = delete;
    Customer &operator=(Customer &&) = delete;
    ~Customer() = default;

    Customer(std::string name, int age) : _name{name}, _age{age} {}

    std::string name() const { return _name; }
    void setName(const std::string &name) { _name = name; }

    int age() const { return _age; }
    void setAge(int age) { _age = age; }

    friend std::ostream &operator<<(std::ostream &os, const Customer &rhs)
    {
        os << "_name: " << rhs._name
           << " _age: " << rhs._age;
        return os;
    }
};

#endif // CUSTOMER_H
