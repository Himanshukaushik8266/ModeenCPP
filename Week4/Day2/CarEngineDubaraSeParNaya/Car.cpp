#include "Car.h"
#include<memory>


/*
    Constructor Delegation feature: use multiple constructor of same class together to make an object;
*/
Car::Car(std::string id, std::string model, std::shared_ptr<Engine> engine, CarType ctype)
:  _id{id},_model{model},_engine{engine}, _ctype{ctype}{}

//  ** We cannot use delegated constructor and member list initialisation in the same constructor
Car::Car(std::string id, float price, std::string model,std::shared_ptr<Engine> engine,CarType ctype)
:  Car(id,model,engine,ctype)
{
    _price=price;
}

std::ostream &operator<<(std::ostream &os, const Car &rhs) {
    os << "_id: " << rhs._id
       << " _price: " << rhs._price
       << " _model: " << rhs._model
       << " _engine: " << *rhs._engine;
        // << " _ctype: " << rhs._ctype;
    return os;
}

