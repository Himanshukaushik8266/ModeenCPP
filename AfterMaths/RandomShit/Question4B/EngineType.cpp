#include "EngineType.h"
void DisplayEngineType(EngineType type){
    if (type == EngineType::DIESEL)
    {
        std::cout<<"Diesel";
    }
    else
    {
        std::cout<<"Petrol";
    }
}