#include "Functionalities.h"
#include <iomanip>
#define line() std::cout << "********************************************************\n";

int main()
{
    std::cout << std::setprecision(2) << std::fixed;
    Container data;
    CreateObjects(data);

    try
    {
        line();
        Container result = InstancesWithPriceBelow600000(data);
        for (VariantType v : result)
        {
            std::visit([](auto &&val)
                       { std::cout << *val << std::endl; },
                       v);
        }
        line();
        std::cout << "Average EVCar price is : " << AveragePriceOFEVCar(data) << std::endl;
        line();
        std::cout << "Count of Matching EngineType for EVCar is : " << CountEVCarMatchingEngineType(data, EPowerType::ELECTRIC) << std::endl;
        line();
        std::cout << "Brand name for matching Id is : " << BrandNameWithMatchingID(data, "I-103") << std::endl;
        line();
        std::cout<<"Unique Battery Types are : \n";
        std::unordered_set<BatteryType> result2=UniqueBatteryTypes(data);
        for(BatteryType b:result2){
            DisplayBatteryType(b);
            std::cout<<" ";
        }
        std::cout<<"\n";
        line();
        std::cout<<std::boolalpha<<"At least one car is above 6L : "<<AtLeastOneAbove600000(data)<<std::endl;
        line();
    }
    catch (EmptyContainerException &ex)
    {
        std::cout << ex.what() << std::endl;
    }
    return 0;
}