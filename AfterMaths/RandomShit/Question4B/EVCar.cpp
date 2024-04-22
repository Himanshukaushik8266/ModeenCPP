#include "EVCar.h"
std::ostream &operator<<(std::ostream &os, const EVCar &rhs)
{
    std::string val1{""}, val2{""};
    if (rhs.batteryType() == BatteryType::LI_ION)
    {
        val1 = "Li-ion Battery";
    }
    else if (rhs.batteryType() == BatteryType::NICAD)
    {
        val1 = "Li-cad Battery";
    }
    else
    {
        val1 = "Other battery type";
    }

    if (rhs.engineType() == EPowerType::ELECTRIC)
    {
        val2 = "Electric";
    }
    else
    {
        val2 = "Hybrid";
    }
    os << "_id: " << rhs._id
       << " _brandName: " << rhs._brandName
       << " _price: " << rhs._price
       << " _enginePowerType: " << val2
       << " _batteryType: " << val1;
    return os;
}

EVCar::EVCar(std::string id, std::string brand, float price, EPowerType powerType, BatteryType batType)
    : _id{id}, _brandName{brand}, _price{price}, _engineType{powerType}, _batteryType{batType}
{
}

float EVCar::CalculateRegistrationCharges()
{
    if (_engineType == EPowerType::ELECTRIC)
    {
        return 0.05f * _price;
    }
    else
    {
        return 0.08f * _price;
    }
}