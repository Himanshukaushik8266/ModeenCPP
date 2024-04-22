#include "ElectricCar.h"

ElectricCar::ElectricCar(std::string name,int acceleration,int top_speed,float price,int battery_capacity, float time_to_charge, float motor_power, float max_power, float range)
:Car(name,acceleration,top_speed,price),_batteryCapacity{battery_capacity},_timeToCharge{time_to_charge},_motorPower{motor_power},_maxPower{max_power},_range{range}{}

std::ostream &operator<<(std::ostream &os, const ElectricCar &rhs) {
    os << static_cast<const Car &>(rhs)
       << " _batteryCapacity: " << rhs._batteryCapacity
       << " _timeToCharge: " << rhs._timeToCharge
       << " _motorPower: " << rhs._motorPower
       << " _maxPower: " << rhs._maxPower
       << " _range: " << rhs._range;
    return os;
}

float ElectricCar::drive()
{
    return _range;
}

void ElectricCar::showElectricCarDetails()
{
    std::cout<< " _batteryCapacity: " << _batteryCapacity
       << " _timeToCharge: " << _timeToCharge
       << " _motorPower: " << _motorPower
       << " _maxPower: " << _maxPower
       << " _range: " << _range;   
}
