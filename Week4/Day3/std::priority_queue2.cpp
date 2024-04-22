#include <iostream>
#include <queue>
#include "Employee.h"
 
struct lessComparator
{
    bool operator()(int a, int b)
    {
        return a > b;
    }
};
 
struct lessEmployeeComparator
{
    bool operator()(const Employee& e1, const Employee& e2)
    {
        return e1.expYear() < e2.expYear();
    }
};
 
int main()
{
    std::vector<int> data{1, 2, 43, 432, 123, 43};
    std::priority_queue<int, std::vector<int>, lessComparator> pq(data.begin(), data.end());
    std::cout<<"Using Struct comparitor :- \n";
    while (!pq.empty())
    {
        std::cout << "Popping :- " << pq.top() << '\n';
        pq.pop();
    }
 
    std::vector<Employee> data2;
    data2.push_back(Employee("Himanshu", 50000.0f, "Trainee", 1));
    data2.push_back(Employee("Vikas", 35000.0f, "Trainer", 5));
    data2.push_back(Employee("Ramesh", 30000.0f, "Manager", 2));
 
    auto comparitor = [](const Employee& e1, const Employee& e2)
    {
        return e1.expYear() < e2.expYear();
    };
 
    std::priority_queue<Employee, std::vector<Employee>, lessEmployeeComparator> pq2(data2.begin(), data2.end());
    std::cout<<"\n\nUsing Struct comparitor :- \n";
    while (!pq2.empty())
    {
        std::cout << "Popping :- " << pq2.top() << '\n';
        pq2.pop();
    }
    
    std::priority_queue<Employee, std::vector<Employee>, decltype(comparitor)> pq3(data2.begin(), data2.end(),comparitor);
    std::cout<<"\n\nUsing Lambda comparitor :- \n";
    while (!pq3.empty())
    {
        std::cout << "Popping :- " << pq3.top() << '\n';
        pq3.pop();
    }
    // std::cout<<
}