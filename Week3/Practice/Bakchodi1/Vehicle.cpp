#include "Vehicle.h"
std::ostream &operator<<(std::ostream &os, const Vehicle &rhs) {
    os << "_variant: ";
    std::visit([&](auto&& args){
        std::cout<<*args<<"\n";
    }, rhs._variant);
    os  << " _milage: " << rhs._milage;
    return os;
}

Vehicle::Vehicle(VType variant, float milage)
        : _variant{variant}, _milage{milage} {}