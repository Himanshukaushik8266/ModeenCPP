#ifndef CAR_H
#define CAR_H
#include<iostream>
#include "Engine.h"
#include "Enums.h"
#include<memory>
class Car
{
private:
    std::string _id;
    float _price;
    std::string _model;
    std::shared_ptr<Engine> _engine{nullptr};
    CarType _ctype;
public:
    Car() =default;
    Car (const Car &) =delete;                  //(delete -> disabled copy constructor )
    Car(Car &&)=delete;                         //brand new
    Car &operator=(const Car&)=delete;          //deleted copy assignment
    Car && operator=(Car&&)=delete;  
    ~Car()=default;

    Car(std::string id, float price, std:: string model,std::shared_ptr<Engine>  engine,CarType ctype);
    Car (std::string id, std::string model,std::shared_ptr<Engine> engine,CarType ctype);


    std::string id() const { return _id; }

    float price() const { return _price; }
    void setPrice(float price) { _price = price; }

    std::string model() const { return _model; }

    std::shared_ptr<Engine> engine() const { return _engine; }
    void setEngine(const std::shared_ptr<Engine> &engine) { _engine = engine; }

    friend std::ostream &operator<<(std::ostream &os, const Car &rhs);
    
};

#endif // CAR_H
