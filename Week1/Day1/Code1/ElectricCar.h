#ifndef ELECTRIC_H
#define ELECTRIC_H
#include "Car.h"
#include <ostream>

class ElectricCar:public Car
{
private:
    /* data */
    int _batteryCapacity {0};
    float _timeToCharge{0.0f};
    float _motorPower{0.0f};
    float _maxPower{0.0f};
    float _range{0.0f};

public:
    ElectricCar()=default;
    ElectricCar (const ElectricCar &) =delete;                  //(delete -> disabled copy constructor)
    ElectricCar(ElectricCar &&)=delete;                         //brand new
    ElectricCar &operator=(const ElectricCar&)=delete;          //deleted copy assignment
    ElectricCar &operator=(ElectricCar&&)=delete;               //brand new(deleted move assignement)
    ~ElectricCar()=default;


    ElectricCar(std::string name,int acceleration,int top_speed,float price,int battery_capacity,float time_to_charge,float motor_power,float max_power,float range);


    float drive () override;
    void showElectricCarDetails();


    friend std::ostream &operator<<(std::ostream &os, const ElectricCar &rhs);
    
};

#endif // ELECTRIC_H
