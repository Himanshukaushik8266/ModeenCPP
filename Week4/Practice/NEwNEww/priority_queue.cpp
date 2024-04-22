#include <iostream>
#include <queue> //-------->Priority queue--------->arrainging data from a different container in a specific ordered priority
#include <functional>
#include "Functionalities.h"
#include <future>

std::function<bool(Employee &, Employee &)> Comparator = [](Employee &emp1, Employee &emp2)
{
    return emp1.expYear() < emp2.expYear();
};

// void ArrangeObjects(EmployeeContainer &data)
// {
//     std::priority_queue<Employee, std::vector<Employee>, std::function<bool(Employee &, Employee &)>> pq(data.begin(), data.end(), Comparator);
//     while (!pq.empty())
//     {
//         std::cout << pq.top() << std::endl;
//         pq.pop();
//     }
// }
std::priority_queue<Employee, std::vector<Employee>, std::function<bool(Employee &, Employee &)>> ArrangeObjects(EmployeeContainer &data)
{
    std::priority_queue<Employee, std::vector<Employee>, std::function<bool(Employee &, Employee &)>> pq(data.begin(), data.end(), Comparator);
    return pq;
}

int main()
{

    EmployeeContainer data;
    CreateEmployees(data);

    std::future<std::priority_queue<Employee, std::vector<Employee>, std::function<bool(Employee &, Employee &)>>> yehwalaFunction = std::async(&ArrangeObjects, std::ref(data));
    std::priority_queue<Employee, std::vector<Employee>, std::function<bool(Employee &, Employee &)>> result = yehwalaFunction.get();

    while (!result.empty())
    {
        std::cout << result.top() << std::endl;
        result.pop();
    }
    return 0;
}