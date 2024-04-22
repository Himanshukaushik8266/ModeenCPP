#include <iostream>
#include <mutex>
#include <condition_variable>
#include <thread>
#include <array>
#include <algorithm>
#include <numeric>
#include <vector>

class Employee;

using EmployeeContainer = std::vector<Employee *>;

class Employee
{
private:
    /* data */
    std::string _name{""};
    bool flag = false;
    std::mutex mt;
    std::condition_variable cv;
    float salary{0.0f};
    EmployeeContainer data;

public:
    Employee() = default;
    Employee(const Employee &) = delete;
    Employee(Employee &&) = delete;
    Employee &operator=(const Employee &) = delete;
    Employee &operator=(Employee &&) = delete;
    ~Employee() = default;

    Employee(std::string name, float sal) : _name{name}, salary{sal} {}

    void CreateAndPerformAction()
    {
        int *count = new int;
        std::unique_lock<std::mutex> ul(mt);
        cv.wait(ul, [&]()
                { return flag; });
        *count = std::count_if(data.begin(), data.end(), [](const Employee *e)
                                   { return e->getSalary() > 1000.0f; });
        std::cout << "The Count of Employee with greater than 1000 salary is : " << *count << std::endl;
    }

    void TakeInput()
    {
        std::lock_guard<std::mutex> lg(mt);
        data.push_back(new Employee("Himanshu", 15000.0f));
        data.push_back(new Employee("Vatanpreet", 60000.0f));
        data.push_back(new Employee("Kushagra", 1500.0f));

        for (Employee *e : data)
        {
            std::cout << *e << std::endl;
        }
    }
    void Notify()
    {
        cv.notify_one();
    }

    float getSalary() const { return salary; }

    void setFlag(bool flag_) { flag = flag_; }

    friend std::ostream &operator<<(std::ostream &os, const Employee &rhs)
    {
        os << "_name: " << rhs._name
           << " salary: " << rhs.salary;
        return os;
    }
};

int main()
{
    Employee *temp = new Employee();

    std::thread t1(&Employee::CreateAndPerformAction, temp);
    temp->TakeInput();
    temp->setFlag(true);
    temp->Notify();

    t1.join();

    return 0;
}