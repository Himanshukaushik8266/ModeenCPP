#ifndef MAJOR_H
#define MAJOR_H

#include "Minor.h"
#include<functional>
#include<iostream>
class Major
{
private:
    /* data */
    std::reference_wrapper<Minor> _minor;
public:
    Major() =default;
    ~Major()=default;

    void Operations(std::function<void(int,int)> fn, int n1, int n2){
        fn(n1,n2);
    }

    Major(std::reference_wrapper<Minor> minor):_minor{minor}{}

    std::reference_wrapper<Minor> minor() const { return _minor; }
    void setMinor(const std::reference_wrapper<Minor> &minor) { _minor = minor; }
    
};

#endif // MAJOR_H
