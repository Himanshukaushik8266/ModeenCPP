#ifndef PROJECT_H
#define PROJECT_H
#include<iostream>
class Project
{
private:
    /* data */
    std::string _name;
public:
    Project()=default;
    Project(const Project &)=default;
    Project(Project &&)=delete;
    Project &operator=(const Project &)=delete;
    Project &operator=(Project &&)=delete;
    ~Project()=default;

    Project(std::string name):_name{name}{}

    friend std::ostream &operator<<(std::ostream &os, const Project &rhs) {
        os << "_name: " << rhs._name;
        return os;
    }
    
};

#endif // PROJECT_H
