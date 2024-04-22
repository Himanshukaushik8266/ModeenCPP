#include "EPowerType.h"

void DisplayEPowerType(EPowerType type){
    if (type == EPowerType::HYBRID)
    {
        std::cout<<"Hybrid";
    }
    else
    {
        std::cout<<"Electric";
    }
}
