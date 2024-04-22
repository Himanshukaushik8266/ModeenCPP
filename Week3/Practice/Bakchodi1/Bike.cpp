#include "Bike.h"
std::ostream &operator<<(std::ostream &os, const Bike &rhs) {
    os << "_car_name: " << rhs._bike_type
       << " _wheels: " << rhs._wheels;
    return os;
}

Bike::Bike(std::string bike_name, int wheels)
    : _bike_type{bike_name}, _wheels{wheels} {}