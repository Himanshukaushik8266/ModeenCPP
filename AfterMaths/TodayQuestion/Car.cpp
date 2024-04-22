#include "Car.h"
std::ostream &operator<<(std::ostream &os, const Car &rhs) {
    os << "_seatcount: " << rhs._seatcount
       << " _model: " << rhs._model
       << " _price: " << rhs._price;
    return os;
}

Car::Car(int seat, std::string model, float price)
: _seatcount{seat},_model{model},_price{price}
{
}