#ifndef BASE_H
#define BASE_H
#include<iostream>
#include "Derived.h"
class Base
{
private:
    int _id {0};
    std::string _name{""};
    Derived * _data;
public:
    Base()=default;
    Base(const Base &)=delete;
    Base (const Base &&)=delete;
    Base & operator=(const Base &)=delete;
    Base && operator=(const Base &&)=delete;
    ~Base()=default;

    Base(int id,std::string name,Derived * d);

    int id() const { return _id; }
    void setId(int id) { _id = id; }

    std::string name() const { return _name; }
    void setName(const std::string &name) { _name = name; }

    Derived * data() const { return _data; }
    void setData(Derived * data) { _data = data; }

    friend std::ostream &operator<<(std::ostream &os, const Base &rhs);

};

#endif // BASE_H
