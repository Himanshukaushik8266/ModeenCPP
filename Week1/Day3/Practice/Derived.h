#ifndef DERIVED_H
#define DERIVED_H
#include<iostream>
class Derived
{
private:
    int _dId {0};
    std::string _dName{""};
public:
    Derived()=default; 
    Derived (const Derived &)=delete;
    Derived (const Derived &&)=delete;
    Derived & operator =(const Derived &)=delete;
    Derived && operator =(const Derived && )=delete;
    ~Derived()=default;

    Derived(int id ,std::string name);

    int dId() const { return _dId; }
    void setDId(int dId) { _dId = dId; }

    std::string dName() const { return _dName; }
    void setDName(const std::string &dName) { _dName = dName; }

    friend std::ostream &operator<<(std::ostream &os, const Derived &rhs);


};

#endif // DERIVED_H
