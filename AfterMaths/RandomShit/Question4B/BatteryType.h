#ifndef BATTERYTYPE_H
#define BATTERYTYPE_H
#include<iostream>
enum class BatteryType{
    LI_ION,NICAD, OTHER
};

void DisplayBatteryType(BatteryType type);

#endif // BATTERYTYPE_H
