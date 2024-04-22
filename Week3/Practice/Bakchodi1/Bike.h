#ifndef BIKE_H
#define BIKE_H

#include <iostream>
class Bike
{
private:
    std::string _bike_type;
    int _wheels;

public:
    Bike()=default;
    Bike(const Bike &)=delete;
    Bike(Bike && )=delete;
    Bike & operator=(const Bike & )=delete;
    Bike &operator=(Bike &&)=delete;
    ~Bike()=default;
    Bike(std::string bike_name, int wheels);

    std::string bikeType() const { return _bike_type; }
    void setBikeType(const std::string &bike_type) { _bike_type = bike_type; }

    int wheels() const { return _wheels; }
    void setWheels(int wheels) { _wheels = wheels; }

    friend std::ostream &operator<<(std::ostream &os, const Bike &rhs);
};

#endif // BIKE_H
