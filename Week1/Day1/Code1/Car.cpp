#include "Car.h"

std::ostream &operator<<(std::ostream &os, const Car &rhs) {
    os << "_name: " << rhs._name
       << " _acceleration: " << rhs._acceleration
       << " _topSpeed: " << rhs._topSpeed
       << " _exShowroomPrice: " << rhs._exShowroomPrice;
    return os;
}

Car::Car(std::string name, int acceleration, int top_speed, float price)
: _name{name},_acceleration{acceleration},_topSpeed{top_speed},_exShowroomPrice{price} {}

