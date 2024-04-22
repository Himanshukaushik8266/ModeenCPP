#ifndef DEMO_H
#define DEMO_H
#include<iostream>
class Demo
{
private:
    /* data */
    int _id;
    std::string _name;


public:
    Demo()=delete;
    Demo (const Demo &)=delete;
    ~Demo()=default;




    Demo(int id,std::string name);

    int id() const { return _id; }
    void setId(int id) { _id = id; }

    std::string name() const { return _name; }
    void setName(const std::string &name) { _name = name; }

    friend std::ostream &operator<<(std::ostream &os, const Demo &rhs);

    
};

#endif // DEMO_H
