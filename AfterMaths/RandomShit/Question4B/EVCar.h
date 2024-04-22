#ifndef EVCAR_H
#define EVCAR_H

#include<iostream>
#include "BatteryType.h"
#include "EPowerType.h"
class EVCar
{
private:
    std::string _id;
    std::string _brandName;
    float _price;
    EPowerType _engineType;
    BatteryType _batteryType;

    
public:
    EVCar()=default;
    EVCar(const EVCar &)=delete;
    EVCar(EVCar && )=delete;
    EVCar & operator=(const EVCar & )=delete;
    EVCar &operator=(EVCar &&)=delete;
    ~EVCar()=default;

    EVCar(std::string id, std::string brand, float price, EPowerType powerType,BatteryType batType);

    float CalculateRegistrationCharges();


    std::string id() const { return _id; }

    std::string brandName() const { return _brandName; }

    float price() const { return _price; }

    BatteryType batteryType() const { return _batteryType; }

    EPowerType engineType() const { return _engineType; }

    friend std::ostream &operator<<(std::ostream &os, const EVCar &rhs);
};

#endif // EVCAR_H
