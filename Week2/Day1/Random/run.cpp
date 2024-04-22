#include <iostream>
#include <memory>
#include <vector>

class Child;
class Demo;

using ChildPointer = std::shared_ptr<Child>;
using DemoPointer = std::shared_ptr<Demo>;

class Child
{
private:
    std::string _name{""};

public:
    Child() = default;
    Child(std::string name) : _name{name} {}
    ~Child() {}

    friend std::ostream &operator<<(std::ostream &os, const Child &rhs)
    {
        os << "_name: " << rhs._name;
        return os;
    }
};

class Demo
{
private:
    int _id{0};
    ChildPointer _childDetail{nullptr};

public:
    Demo() = default;
    Demo(int id, ChildPointer childDetail) : _id{id}, _childDetail{childDetail} {}
    ~Demo() {}

    friend std::ostream &operator<<(std::ostream &os, const Demo &rhs)
    {
        os << "_id: " << rhs._id
           << " _childDetail: " << *rhs._childDetail;
        return os;
    }
};

using Container = std::vector<DemoPointer>;

int main()
{
    Container data;

    data.push_back(std::make_shared<Demo>(12, std::make_shared<Child>("Ayush")));

    for (const DemoPointer &d : data)
    {
        std::cout << *d << std::endl;
    }

    return 0;
}
