#include "ICECar.h"

ICECar::ICECar(std::string id, std::string brand, float price, EngineType type)
:_id{id},_brandName{brand},_price{price},_engineType{type}
{
}

float ICECar::CalculateRegistrationCharges()
{
    if(_engineType==EngineType::DIESEL){
        return 0.1f*_price;
    }
    else{
        return 0.13f*_price;
    }
}

std::ostream &operator<<(std::ostream &os, const ICECar &rhs)
{
    std::string val{""};
    if (rhs.engineType() == EngineType::DIESEL)
    {
        val = "Diesel";
    }
    else
    {
        val = "Petrol";
    }
    os << "_id: " << rhs._id
       << " _brandName: " << rhs._brandName
       << " _price: " << rhs._price
       << " _engineType: " << val;
    return os;
}
