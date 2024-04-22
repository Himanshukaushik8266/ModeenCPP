#ifndef ICECAR_H
#define ICECAR_H
#include <iostream>
#include "EngineType.h"
class ICECar
{
private:
    std::string _id;
    std::string _brandName;
    float _price;
    EngineType _engineType;

public:
    ICECar() = default;
    ICECar(const ICECar &) = delete;
    ICECar(ICECar &&) = delete;
    ICECar &operator=(const ICECar &) = delete;
    ICECar &operator=(ICECar &&) = delete;
    ~ICECar() = default;

    ICECar(std::string id, std::string brand, float price, EngineType type);

    float CalculateRegistrationCharges();

    std::string id() const { return _id; }

    std::string brandName() const { return _brandName; }

    float price() const { return _price; }

    EngineType engineType() const { return _engineType; }

    friend std::ostream &operator<<(std::ostream &os, const ICECar &rhs);
};

#endif // ICECAR_H
