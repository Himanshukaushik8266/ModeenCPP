#include "Car.h"
std::ostream &operator<<(std::ostream &os, const Car &rhs) {
    os << "_bike_type: " << rhs._car_name
       << " _wheels: " << rhs._wheels;
    return os;
}

Car::Car(std::string car_name, int wheels)
    : _car_name{car_name}, _wheels{wheels} {}