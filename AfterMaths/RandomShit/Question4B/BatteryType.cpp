#include "BatteryType.h"

void DisplayBatteryType(BatteryType type){
    if (type == BatteryType::LI_ION)
    {
        std::cout<<"Li-ion";
    }
    else if(type==BatteryType::NICAD)
    {
        std::cout<<"NI-CAD";
    }
    else{
        std::cout<<"Other";
    }
}