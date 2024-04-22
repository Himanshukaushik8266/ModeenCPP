#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <variant>
#include <memory>
#include "Car.h"
#include "Bike.h"

class Vehicle;
using BikePointer = std::shared_ptr<Bike>;
using CarPointer = std::shared_ptr<Car>;
using VType = std::variant<BikePointer, CarPointer>;

class Vehicle
{
private:
    VType _variant;
    float _milage;
public:
    Vehicle()=delete;
    Vehicle(const Vehicle &)=delete;
    Vehicle(Vehicle && )=delete;
    Vehicle & operator=(const Vehicle & )=delete;
    Vehicle &operator=(Vehicle &&)=delete;
    ~Vehicle()=default;
    Vehicle(VType variant, float milage);

    VType variant() const { return _variant; }
    void setVariant(const VType &variant) { _variant = variant; }

    float milage() const { return _milage; }
    void setMilage(float milage) { _milage = milage; }

    friend std::ostream &operator<<(std::ostream &os, const Vehicle &rhs);

    
};

#endif // VEHICLE_H
