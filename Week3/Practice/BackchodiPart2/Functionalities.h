#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "Employee.h"
#include "Customer.h"
#include <thread>
#include <variant>
#include <array>
#include <vector>
#include <memory>
#include <functional>
#include <mutex>

std::mutex mt;

using EmpPointer = std::shared_ptr<Employee>;
using CustomerPointer = std::shared_ptr<Customer>;
using Variant = std::variant<EmpPointer, CustomerPointer>;
using VariantContainer = std::vector<Variant>;
using FnType = std::function<void(VariantContainer &)>;
using ThreadsContainer = std::array<std::thread, 2>;
using FunctionContainer = std::array<FnType, 2>;

void CreateObjects(VariantContainer &data)
{
    data.push_back(std::make_shared<Employee>("Human", 10000));
    data.push_back(std::make_shared<Customer>("Human2", 21));
    data.push_back(std::make_shared<Customer>("Human3", 34));
}

auto F1 = [](VariantContainer &data)
{
    int compare = 0;
    std::string name{""};
    for (Variant v : data)
    {
        if (std::holds_alternative<CustomerPointer>(v))
        {
            CustomerPointer temp = std::get<1>(v);
            if (temp->age() > compare)
            {
                name = temp->name();
            }
        }
    }
    std::cout << "The customer with max age is : " << name << std::endl;
};

auto F2 = [](VariantContainer &data)
{
    for (Variant v : data)
    {
        std::visit([](auto &&val)
                   { std::cout << "The name of Customer/Employee is  : " << val->name() << std::endl; },
                   v);
    }
};

void CreateFunctionalConatiner(FunctionContainer &data)
{
    data[0] = (F1);
    data[1] = (F2);
}

void CreateThreads(FunctionContainer &data, ThreadsContainer &data2, VariantContainer &variants)
{

    for (int i = 0; i < 2; i++)
    {
        data2[i] = std::thread(data[i], std::ref(variants));
    }
}

void JoinThreads(ThreadsContainer &data)
{
    for (int i = 0; i < 2; i++)
    {
        if (data[i].joinable())
        {
            data[i].join();
        }
    }
}

#endif // FUNCTIONALITIES_H
