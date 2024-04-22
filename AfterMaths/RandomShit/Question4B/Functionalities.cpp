#include "Functionalities.h"

void CreateObjects(Container &data)
{
    data.push_back(std::make_shared<EVCar>("E-101", "Hyundai", 1500000.0f, EPowerType::ELECTRIC, BatteryType::LI_ION));
    data.push_back(std::make_shared<ICECar>("I-101", "TATA", 560000.43f, EngineType::DIESEL));
    data.push_back(std::make_shared<EVCar>("E-102", "Mahindra", 54632546.0f, EPowerType::HYBRID, BatteryType::NICAD));
    data.push_back(std::make_shared<ICECar>("I-102", "Honda", 545322.43f, EngineType::PETROL));
    data.push_back(std::make_shared<EVCar>("E-103", "Tesla", 9875895.0f, EPowerType::ELECTRIC, BatteryType::OTHER));
    data.push_back(std::make_shared<ICECar>("I-103", "Masserati", 2341345.43f, EngineType::PETROL));
    data.push_back(std::make_shared<EVCar>("E-104", "Aston Martin", 4562456.0f, EPowerType::ELECTRIC, BatteryType::NICAD));
    data.push_back(std::make_shared<ICECar>("I-104", "Lambroghini", 867996.43f, EngineType::PETROL));
}

Container InstancesWithPriceBelow600000(Container &data)
{
    if (data.empty())
    {
        throw EmptyContainerException("Data Container is empty!!");
    }
    Container result;
    std::copy_if(data.begin(), data.end(), std::inserter(result, result.begin()), [](VariantType v)
                 {
        bool flag=false;
        std::visit([&](auto && val){if(val->price()<600000.0f) flag=true;},v);
        return flag; });

    return result;
}

float AveragePriceOFEVCar(Container &data)
{
    if (data.empty())
    {
        throw EmptyContainerException("Data Container is empty !!");
    }
    float countEVCar{0.0f};
    float total = std::accumulate(data.begin(), data.end(), 0.0f, [&](float sum_upto_this, VariantType v)
                                  {
        float sum{0.0f};
        if(v.index()==1){
            EVCarPointer ev=std::get<1>(v);
            countEVCar++;
            sum_upto_this+=ev->price();
        }
        return sum_upto_this; });
    return total / countEVCar;
}

int CountEVCarMatchingEngineType(Container &data, EPowerType type)
{
    return std::count_if(data.begin(), data.end(), [&](VariantType v)
                         {
        if(std::holds_alternative<EVCarPointer>(v))
        {
            EVCarPointer ev=std::get<1>(v);
            return ev->engineType()==type;
        }
        return false; });
}

std::string BrandNameWithMatchingID(Container &data, std::string id)
{
    std::string ans{""};
    auto itr = std::find_if(data.begin(), data.end(), [&](VariantType v){
        bool flag=false;
        std::visit([&](auto && val){if(val->id()==id)flag=true;},v);
        return flag;
    });
    VariantType temp = *itr;
    std::visit([&](auto &&val){
        ans = val->brandName();
    },temp);

    return ans;
}

std::unordered_set<BatteryType> UniqueBatteryTypes(Container &data)
{
    std::unordered_set<BatteryType> mySet;

    std::transform(data.begin(),data.end(),std::inserter(mySet,mySet.begin()),[&](VariantType v){
        if(v.index()==1){
            EVCarPointer ev=std::get<1>(v);
            return ev->batteryType();
        }
        return BatteryType::OTHER;
    });

    return mySet;
}

bool AtLeastOneAbove600000(Container &data)
{
    return std::any_of(data.begin(),data.end(),[](VariantType v){
        bool flag=false;
        std::visit([&](auto && val){if(val->price()>600000.0f)flag=true;},v);
        return flag;
    });
}

















