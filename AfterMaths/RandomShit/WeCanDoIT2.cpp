#include <iostream>
#include <vector>
#include <functional>
#include <memory>
#include <list>

class Projects
{
private:
    /* data */
    std::string _name;

public:
    Projects() = default;
    Projects(const Projects &) = delete;
    Projects(Projects &&) = default;
    Projects &operator=(const Projects &) = delete;
    Projects &operator=(Projects &&) = delete;
    ~Projects() = default;
    Projects(std::string name) : _name{name} {}

    friend std::ostream &operator<<(std::ostream &os, const Projects &rhs)
    {
        os << "_name: " << rhs._name;
        return os;
    }
};

using ProjectsContainer = std::list<Projects>;

void CreateObjects(ProjectsContainer &data)
{

    data.push_back(Projects("Vatan"));

    std::cout << data.front() << std::endl;
}

int main()
{

    ProjectsContainer data;

    CreateObjects(data);

    return 0;
}