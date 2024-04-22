#include <iostream>
#include <queue>
#include <vector>
#include "Employee.h"

struct Less_Comparator
{
    bool operator()(int a, int b)
    {
        return a < b;
    }
};
// min head : a,b will be before b in a min heap if a is less than b
// max head : a,b will be before b in a max heap if a is greater than b

template <typename T, typename C>
void Display(std::priority_queue<T, std::vector<T>, C> &pq3)
{
    while (!pq3.empty())
    {
        std::cout << "Popping: " << pq3.top() << std::endl;
        pq3.pop();
    }
}
auto comp = [](const Employee &e1, const Employee &e2)
{
    return e1.expYear() < e2.expYear();
};

int main()
{
    std::vector<int> data{11, 10, 27, 7, 9, 15, 27, 18};
    std::vector<Employee> emp{Employee("Ayush", 20000, "ASE", 1), (Employee("Aman", 30000, "SDE", 4))};

    std::priority_queue<int, std::vector<int>, Less_Comparator> pq(data.begin(), data.end());
    Display<int, Less_Comparator>(pq);

    std::priority_queue<int, std::vector<int>, std::greater<int>> pq2(data.begin(), data.end());
    Display<int, std::greater<int>>(pq2);

    std::priority_queue<Employee, std::vector<Employee>, decltype(comp)> pq3(emp.begin(), emp.end(), comp);
    Display<Employee, decltype(comp)>(pq3);
}

/*
       pq3 is a priority queue designed for storing employees (type Employee). It will be created by using std::vector of employee type.
       The comparison logic comes from lambda object comp. Its data type is unknown to me, hence I am asking compiler to provide declared types of comp i.e decltype(comp) as my third template parameter
*/

// std::priority_queue<Employee, std::vector<Employee>, Less_Comparator> pq3(emp.begin(), emp.end());